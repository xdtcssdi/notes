import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import numpy as np
print(tf.__version__)
print(keras.__version__)

def Model_1():
    # 网络构建
    network = keras.Sequential([
        layers.Flatten(),
        layers.Dense(256, activation='relu', 
                    kernel_initializer='orthogonal',  #string
                    kernel_regularizer=keras.regularizers.l2(0.01)),
        layers.Dense(128, activation=tf.nn.relu, 
                    kernel_initializer=tf.keras.initializers.glorot_normal(),# obj
                    kernel_regularizer=keras.regularizers.l2(0.01))
    ])
    network.add(layers.Dense(10, activation=tf.nn.softmax))

    # 设置编译参数
    network.compile(optimizer=keras.optimizers.Adam(), 
                    loss=keras.losses.categorical_crossentropy,
                    metrics=['acc'])

    # 数据导入 和 预处理
    (feature, labels), (val_x, val_y) = keras.datasets.fashion_mnist.load_data()
    print(feature.shape, labels.shape, val_x.shape, val_y.shape)
    labels = tf.one_hot(labels, depth=10)
    val_y = tf.one_hot(val_y, depth=10)

    datasets = tf.data.Dataset.from_tensor_slices((feature, labels)).batch(100)
    datasets = datasets.repeat() #确保 m > steps_per_epoch * batch_size，否则使用repeat
    print(datasets)

    val_datasets = tf.data.Dataset.from_tensor_slices((val_x, val_y)).batch(100)
    val_datasets = val_datasets.repeat()
    print(val_datasets)

    # 训练
    # 确保 m > steps_per_epoch * batch_size，否则使用repeat
    network.fit(feature, labels, 
                epochs=1, #模型迭代次数
                steps_per_epoch = 1000, #每一轮生成1000个batch，默认None自动计算
                validation_data=val_datasets,
                validation_steps=101 #每一轮结束后生成100个batch验证，默认None自动计算
            )

    network.evaluate(val_datasets, steps=100)

    # network.save('model.h5')
    tf.saved_model.save(network, 'model')

def load_Model_1():
    #network = keras.models.load_model('model.h5')
    network = tf.saved_model.load('model')
    # 数据导入 和 预处理
    (feature, labels), (val_x, val_y) = keras.datasets.fashion_mnist.load_data()
    print(feature.shape, labels.shape, val_x.shape, val_y.shape)
    labels = tf.one_hot(labels, depth=10)
    val_y = tf.one_hot(val_y, depth=10)

    datasets = tf.data.Dataset.from_tensor_slices((feature, labels)).batch(100)
    datasets = datasets.repeat() #确保 m > steps_per_epoch * batch_size，否则使用repeat
    print(datasets)

    val_datasets = tf.data.Dataset.from_tensor_slices((val_x, val_y)).batch(100)
    print(val_datasets)
    
    #network.evaluate(val_datasets, steps=100)
    
    acc_meter = keras.metrics.CategoricalAccuracy()
    for x,y in val_datasets: # 遍历测试集，不能用repeat否则就是无限数据
        pred = network(x) # 前向计算
        acc_meter.update_state(y_true=y, y_pred=pred) # 更新准确率统计 # 打印准确率
    print("Test Accuracy:%f" % acc_meter.result())


class MyDense(layers.Layer):
    def __init__(self, in_dim, out_dim):
        super(MyDense, self).__init__()
        self.kernel = self.add_variable('w', [in_dim, out_dim], trainable=True) #默认trainable=true
        self.bias = tf.Variable(tf.random.normal([out_dim]), name='b') #变量自动为trainable
    
    def cell(self, inputs, training=None):
        """
            training: test:False, None ;  train:True
        """
        y = inputs @ self.kernel + self.bias
        a = tf.nn.relu(y)
        return a
    '''
    net = keras.Sequential([
        MyDense(10,5),
        MyDense(5,4),
        MyDense(4,1)
    ])
    net.build(input_shape=(None,10))
    print(net.summary())
    '''

class MyModel(keras.Model):
    def __init__(self):
        super(MyModel, self).__init__()
        self.fc1 = MyDense(10, 5)
        self.fc2 = MyDense(5, 3)
        self.fc3 = MyDense(3, 1)
    
    def call(self, inputs, training=None):
        x = self.fc1(inputs)
        x = self.fc2(x)
        x = self.fc3(x)
        return x

    """
    net = MyModel()
    net.build(input_shape=(None, 10))
    print(net.summary())
    """

class ResNet50():
    import ssl
    import tensorflow as tf
    from tensorflow import keras
    from tensorflow.keras import layers
    import numpy as np
    ssl._create_default_https_context = ssl._create_unverified_context
    vgg16 = keras.applications.VGG16(weights='imagenet', include_top=False)
    vgg16.trainable = False
    network = keras.Sequential([
                                vgg16,
                                layers.Conv2D(2048, (1, 1), activation='relu')
                                layers.GlobalAveragePooling2D(),
                                layers.Conv2D(2048, (1, 1), activation='relu'),
                                layers.BatchNormalization(),
                                layers.Conv2D(2048, (1, 1), activation='relu'),
                                layers.BatchNormalization(),
                                layers.Conv2D(100, (1, 1))
                                layers.Flatten()
                            ])
    # 设置编译参数
    network.compile(optimizer=keras.optimizers.Adam(0.01), 
                    loss=keras.losses.CategoricalCrossentropy(),
                    metrics=['acc'])
    print(network.summary())
    # 数据导入 和 预处理
    (feature, labels), (val_x, val_y) = keras.datasets.cifar100.load_data()
    print(feature.shape, labels.shape, val_x.shape, val_y.shape)
    labels = tf.one_hot(labels.reshape(-1,), depth=100)
    val_y = tf.one_hot(val_y.reshape(-1,), depth=100)
    datasets = tf.data.Dataset.from_tensor_slices((feature, labels)).batch(512)
    datasets = datasets.repeat() #确保 m > steps_per_epoch * batch_size，否则使用repeat
    print(datasets)
    val_datasets = tf.data.Dataset.from_tensor_slices((val_x, val_y)).batch(512)
    val_datasets = val_datasets.repeat()
    print(val_datasets)

    # 训练
    # 确保 m > steps_per_epoch * batch_size，否则使用repeat
    network.fit(feature, labels, 
                epochs=30, #模型迭代次数
                steps_per_epoch = 1000, #每一轮生成1000个batch，默认None自动计算
                validation_data=val_datasets,
                validation_steps=100 #每一轮结束后生成100个batch验证，默认None自动计算
            )


if __name__=='__main__':
    #Model_1()
    #load_Model_1()
    ResNet50()