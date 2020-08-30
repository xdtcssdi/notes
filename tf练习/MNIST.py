import tensorflow as tf


# 训练集的数据在训练时进行拆分
def load_data():
    mnist = tf.keras.datasets.mnist #训练集和测试集
    (x_train, y_train), (x_test, y_test) = mnist.load_data()
    print("类型：", type(x_train))
    print("训练集数量为：", x_train.shape[0])
    print("测试集数量为：", x_test.shape[0])
    return (x_train, y_train), (x_test, y_test)

def model():
    x = tf.compat.v1.placeholder(tf.float32, [None, 784])
    y = tf.compat.v1.placeholder(tf.float32, [None, 10])

    y_hat = layer(x, out_dim = 10) # layer 1
    
    # 计算loss
    cross_entroy = tf.reduce_mean(-y_hat * tf.math.log(y))
    # 优化
    opt = tf.compat.v1.train.GradientDescentOptimizer(0.01)
    train_step = opt.minimize(cross_entroy)
    




def layer(x, out_dim):
    in_dim = x.shape[1]
    weight = tf.Variable(tf.compat.v1.truncated_normal(shape=(in_dim, out_dim)))
    bias = tf.Variable(tf.zeros(in_dim))
    a = tf.matmul(x, weight) + bias
    y = tf.nn.softmax(a)
    return y