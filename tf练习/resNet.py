import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import ssl
ssl._create_default_https_context = ssl._create_unverified_context
class BasicBlock(layers.Layer):
    def __init__(self, filter_num, stride = 1):
        super(BasicBlock, self).__init__()

        self.conv1 = layers.Conv2D(filter_num, (3, 3), strides=stride, padding='SAME')
        self.batch1 = layers.BatchNormalization()
        self.relu1 = layers.ReLU()

        self.conv2 = layers.Conv2D(filter_num, (3, 3), strides=1, padding='SAME')
        self.batch2 = layers.BatchNormalization()

        self.shortcut = None
        if stride == 1:
            self.shortcut = lambda x: x
        else:
            self.shortcut = layers.Conv2D(filter_num, (1, 1), strides=stride, padding='valid')
        self.relu2 = layers.ReLU()
        
    def call(self, inputs, training=None):
        x = self.conv1(inputs)
        x = self.batch1(x, training=training)
        x = self.relu1(x)
        x = self.conv2(x)
        x = self.batch2(x, training=training)
        out = self.shortcut(inputs)

        out = layers.add([x, out])
        a = self.relu2(out)
        return a

class ResNet(keras.Model):
    def __init__(self, layer_dims ,classes=10, ):
        super(ResNet, self).__init__()
        self.start = keras.Sequential([
            layers.Conv2D(64, (3,3), strides=1),
            layers.BatchNormalization(),
            layers.ReLU(),
            layers.MaxPool2D(pool_size=2, strides=1, padding='SAME')
        ])
        self.res_block1 = self.build_resblock(64, layer_dims[0])
        self.res_block2 = self.build_resblock(128, layer_dims[1], stride=2)
        self.res_block3 = self.build_resblock(256, layer_dims[2], stride=2)
        self.res_block4 = self.build_resblock(512, layer_dims[3], stride=2)
        self.avgpool = layers.GlobalAvgPool2D()
        self.fc = layers.Dense(classes)

    def build_resblock(self, filter_num, block_num, stride=1):
        res_blocks = keras.Sequential([])
        res_blocks.add(BasicBlock(filter_num, stride))

        for _ in range(1, block_num):
            res_blocks.add(BasicBlock(filter_num, 1))
        
        return res_blocks

    def call(self, inputs, training=None):

        x = self.start(inputs)
        x = self.res_block1(x, training=training)
        x = self.res_block2(x, training=training)
        x = self.res_block3(x, training=training)
        x = self.res_block4(x, training=training)
        x = self.avgpool(x)
        x = self.fc(x)
        return x
 
def res18():
    return ResNet([2, 2, 2, 2])

def res34():
    return ResNet([3, 4, 6, 3])

def preprocess(x, y):
    # 将数据映射到-1~1
    x = 2*tf.cast(x, dtype=tf.float32) / 255. - 1 
    y = tf.squeeze(y) # 删除不必要的维度 print(x.shape, y.shape, x_test.shape, y_test.shape)
    y = tf.one_hot(y, depth=10, dtype=tf.int32) # 类型转换 
    return x,y

(x,y), (x_test, y_test) = keras.datasets.cifar10.load_data() # 加载数据集
train_db = tf.data.Dataset.from_tensor_slices((x,y)) # 构建训练集 # 随机打散，预处理，批量化
train_db = train_db.shuffle(1000).map(preprocess).batch(128)
test_db = tf.data.Dataset.from_tensor_slices((x_test,y_test)) #构建测试集 # 随机打散，预处理，批量化
test_db = test_db.map(preprocess).batch(128)

model = res18()
model.compile(optimizer=keras.optimizers.Adam(1e-3), loss=keras.losses.CategoricalCrossentropy(True), metrics=['acc'])
model.fit(train_db, epochs=30, validation_data=test_db)
model.evaluate(test_db)
