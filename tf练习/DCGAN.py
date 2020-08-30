import tensorflow as tf
from tensorflow.keras import layers
from tensorflow import keras
from tensorflow.keras.layers import Conv2D, BatchNormalization, Dense, Conv2DTranspose
import glob
from dataset import *
import numpy as np
batch_size = 64

def load_data():

    img_path = glob.glob(r'/Users/oswin/cropped/*.jpg')
    print(len(img_path))
    dataset, img_shape, _ =  make_anime_dataset(img_path, batch_size)
    return dataset, img_path

class Generator(keras.Model):
    def __init__(self):
        super(Generator, self).__init__()
        filter = 64
        self.conv1 = Conv2DTranspose(filter * 8, 4, 1, 'valid', use_bias=False)
        self.bat1 = BatchNormalization()

        self.conv2 = Conv2DTranspose(filter * 4, 4, 2, 'same', use_bias=False)
        self.bat2 = BatchNormalization()

        self.conv3 = Conv2DTranspose(filter * 2, 4, 2, 'same', use_bias=False)
        self.bat3 = BatchNormalization()

        self.conv4 = Conv2DTranspose(filter * 1, 4, 2, 'same', use_bias=False)
        self.bat4 = BatchNormalization()

        self.conv5 = Conv2DTranspose(3, 4, 2, 'same', use_bias=False)

    def call(self, inputs, training=None):

        x = inputs
        x = tf.reshape(x, (x.shape[0], 1, 1, x.shape[1]))
        x = tf.nn.relu(x)

        x = tf.nn.relu(self.bat1(self.conv1(x), training=training))
        x = tf.nn.relu(self.bat2(self.conv2(x), training=training))
        x = tf.nn.relu(self.bat3(self.conv3(x), training=training))
        x = tf.nn.relu(self.bat4(self.conv4(x), training=training))
        x = tf.tanh(self.conv5(x))

        return x


class Discriminator(keras.Model):
    def __init__(self):
        super(Discriminator, self).__init__()
        filter = 64
        self.conv1 = Conv2D(filter, 4, 2, 'valid', use_bias=False)
        self.bat1 = BatchNormalization()
        self.conv2 = Conv2D(filter * 2, 4, 2, 'valid', use_bias=False)
        self.bat2 = BatchNormalization()
        self.conv3 = Conv2D(filter * 4, 4, 2, 'valid', use_bias=False)
        self.bat3 = BatchNormalization()
        self.conv4 = Conv2D(filter * 8, 3, 1, 'valid', use_bias=False)
        self.bat4 = BatchNormalization()
        self.conv5 = Conv2D(filter * 16, 3, 1,'valid', use_bias=False)
        self.bat5 = BatchNormalization()
        self.pool = layers.GlobalAveragePooling2D()
        self.flatten = layers.Flatten()
        self.fc = Dense(1)
    def call(self, inputs, training=None):
        x = inputs
        x = tf.nn.leaky_relu(self.bat1(self.conv1(x), training=training))
        x = tf.nn.leaky_relu(self.bat2(self.conv2(x), training=training))
        x = tf.nn.leaky_relu(self.bat3(self.conv3(x), training=training))
        x = tf.nn.leaky_relu(self.bat4(self.conv4(x), training=training))
        x = tf.nn.leaky_relu(self.bat5(self.conv5(x), training=training))
        x = self.pool(x)
        x = self.flatten(x)
        x = self.fc(x)
        return x

def d_loss_zero(out):
    target = tf.zeros_like(out)
    loss = keras.losses.binary_crossentropy(target, out, True)
    return tf.reduce_mean(loss)

def d_loss_one(out):
    target = tf.ones_like(out)
    loss = keras.losses.binary_crossentropy(target, out, True)
    return tf.reduce_mean(loss)

def d_loss_fn(generator, discriminator, batch_z, batch_x, is_training):
    fake_img = generator(batch_z)
    fake_logits = discriminator(fake_img, is_training)
    rel_logits = discriminator(batch_x, is_training)

    loss_rel = d_loss_one(rel_logits)
    loss_fake = d_loss_zero(fake_logits)

    return loss_rel + loss_fake
from PIL import Image
idx = 0
def save_images(imgs):
    global idx
    for step, i in enumerate(imgs):
        img = ((i.numpy() + 1) * 127.5).astype(np.uint8)
        im = Image.fromarray(img)
        im.save(f"test{idx},{step}.jpg")
    idx +=1
def g_loss_fn(generator, discriminator, batch_z, batch_x, is_training):
    fake_img = generator(batch_z, is_training)
    save_images(fake_img)
    
    fake_logits = discriminator(fake_img, is_training)
    loss = d_loss_one(fake_logits)
    return loss

lr = 0.001
epoches = 20
k=5
z_dim = 64
db_iter = iter(load_data()[0])
generator = Generator() # 创建生成器 
generator.build(input_shape = (4, z_dim))
#print(generator.summary())
discriminator = Discriminator() # 创建判别器 
discriminator.build(input_shape=(4, 64, 64, 3))
#print(discriminator.summary())
g_optimizer = keras.optimizers.Adam(lr, 0.5)
d_optimizer = keras.optimizers.Adam(lr, 0.5)

for epoch in range(epoches):
    for _ in range(k):
        batch_z = tf.random.normal([batch_size, z_dim])
        batch_x = next(db_iter)
        with tf.GradientTape() as tape:
            loss = d_loss_fn(generator, discriminator, batch_z, batch_x, True)
        grads = tape.gradient(loss, discriminator.trainable_variables)
        d_optimizer.apply_gradients(zip(grads, discriminator.trainable_variables))
    print(f"{epoch} {loss}")
    batch_z = tf.random.normal([batch_size, z_dim])
    batch_x = next(db_iter)
    with tf.GradientTape() as tape:
        loss = g_loss_fn(generator, discriminator, batch_z, batch_x, True)
    
    grads = tape.gradient(loss, generator.trainable_variables)
    g_optimizer.apply_gradients(zip(grads, generator.trainable_variables))
    print(f"{loss}")




