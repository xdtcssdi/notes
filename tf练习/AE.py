import tensorflow as tf
from tensorflow.keras import layers
from tensorflow import keras
import numpy as np
from PIL import Image

print(f"np version{np.__version__}")
batch_size = 128



def load_data():
    (x, y), (x_test, y_test) = keras.datasets.fashion_mnist.load_data()
    x = x.astype(float).reshape(-1, 784) / 255.
    x_test = x_test.astype(float).reshape(-1, 784) / 255.

    db_train = tf.data.Dataset.from_tensor_slices((x, x)).shuffle(batch_size*5).batch(batch_size)
    db_test = tf.data.Dataset.from_tensor_slices((x_test, x_test)).batch(batch_size)

    return db_train, db_test

class AE(keras.Model):
    def __init__(self, input_dim, h_dim):
        super(AE, self).__init__()
        self.encoder = keras.Sequential([
            layers.Dense(256, 'relu'),
            layers.Dense(128, 'relu'),
            layers.Dense(h_dim)
        ])
        self.decoder = keras.Sequential([
            layers.Dense(128, 'relu'),
            layers.Dense(256, 'relu'),
            layers.Dense(input_dim, 'sigmoid')
        ])

    def call(self, inputs, training=None):
        x = self.encoder(inputs)
        x = self.decoder(x)
        return x

def save_images(r, g, name):
    # 创建280x280大小图片阵列
    new_im = Image.new('L', (280, 280)) 
    index = 0
    for i in range(0, 140, 28): # 10 行图片阵列
        for j in range(0, 280, 28): # 10 列图片阵列
            im = r[index]
            im = Image.fromarray(im, mode='L') 
            new_im.paste(im, (i, j)) # 写入对应位置
            index += 1 # 保存图片阵列
    index = 0
    for i in range(140, 280, 28): # 10 行图片阵列
        for j in range(0, 280, 28): # 10 列图片阵列
            im = g[index]
            im = Image.fromarray(im, mode='L') 
            new_im.paste(im, (i, j)) # 写入对应位置
            index += 1 # 保存图片阵列
    new_im.save(name)

if __name__ == "__main__":
    epoches = 20
    db_train, db_test = load_data()
    model = AE(784, 64)
    model.compile(optimizer=keras.optimizers.Adam(0.001),
                loss=keras.losses.BinaryCrossentropy(False),
    )
    model.fit(db_train, epochs=epoches, validation_data=db_test)

    x = next(iter(db_test))[0]
    # 重建图片，从测试集采样一批图片
    x_hat = model(x[:50]) # 打平并送入自编码器 
    
    # 恢复为 28x28,[b, 784] => [b, 28, 28]
    x = tf.cast(tf.reshape(x, (-1, 28, 28)), dtype=tf.float32)
    x_hat = tf.reshape(x_hat, (-1, 28, 28))
    # 输入的前50张+重建的前50张图片合并，[b, 28, 28] => [2b, 28, 28] 
    #x_concat = tf.concat([x, x_hat], axis=0)
    x_concat = x_hat
    x_concat = x_concat.numpy() * 255. # 恢复为0~255范围
    x_concat = x_concat.astype(np.uint8) # 转换为整型

    x = x.numpy() * 255. # 恢复为0~255范围
    x = x.astype(np.uint8) # 转换为整型

    save_images(x, x_concat, '/Users/oswin/ae_images/epoch_%d.png' % epoches) # 保存图片