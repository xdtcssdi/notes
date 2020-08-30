from tensorflow.keras import layers
import tensorflow as tf
from tensorflow import keras
import ssl

ssl._create_default_https_context = ssl._create_unverified_context
batch_size = 128
max_review_len = 80
vocab_size = 10000
embedding_len = 100
units = 64
epoches = 20
def load_data():
    (x, y), (x_test, y_test) = keras.datasets.imdb.load_data(num_words=vocab_size)
    
    x = keras.preprocessing.sequence.pad_sequences(x, maxlen=max_review_len)
    x_test = keras.preprocessing.sequence.pad_sequences(x_test, maxlen=max_review_len)
    
    print(f"train : {x.shape}, {y.shape}")
    print(f"test : {x_test.shape}, {y_test.shape}")
    def cast(x, y):
        return x, tf.cast(y, tf.int32)
    db_train = tf.data.Dataset.from_tensor_slices((x, y)).map(cast)
    db_train = db_train.shuffle(1000).batch(batch_size, drop_remainder=True)
    db_test = tf.data.Dataset.from_tensor_slices((x_test, y_test)).map(cast)
    db_test = db_test.batch(batch_size, drop_remainder=True)
    print(db_train, db_test)
    return db_train, db_test

def get_datasets_info():
    word_idx = keras.datasets.imdb.get_word_index() # 'toothsome': 51284
    word_idx = {k:(v+3) for k,v in word_idx.items()}
    word_idx['<PAD>'] = 0
    word_idx['<START>'] = 1
    word_idx['UNK'] = 2
    word_idx['UNUSED'] = 3
    idx_word = {v: k for k, v in word_idx.items()} # 71144: 'tactlessly'
    return word_idx, idx_word

def decode_review(ids, idx_word):
    return ' '.join([idx_word.get(i, '?') for i in ids])

def encode_review(text, word_idx):
    return [word_idx.get(word, 2) for word in text.split(' ')]


class MyRNN(keras.Model):
    def __init__(self, units, cell='simpleRNN'):
        super(MyRNN, self).__init__()

        self.embedding = layers.Embedding(vocab_size, embedding_len, input_length=max_review_len)
        
        if cell.lower() == 'lstm':
            self.state0 = [tf.zeros([batch_size, units]), tf.zeros([batch_size, units])]
            self.state1 = [tf.zeros([batch_size, units]), tf.zeros([batch_size, units])]
            self.rnn_cell0 = layers.LSTMCell(units, dropout=0.5)
            self.rnn_cell1 = layers.LSTMCell(units, dropout=0.5)
        else:
            self.state0 = [tf.zeros([batch_size, units])]
            self.state1 = [tf.zeros([batch_size, units])]
            if cell.lower() == 'gru':
                self.rnn_cell0 = layers.GRUCell(units, dropout=0.5)
                self.rnn_cell1 = layers.GRUCell(units, dropout=0.5)
            elif cell.lower() == 'simpleRNN':
                self.rnn_cell0 = layers.SimpleRNNCell(units, dropout=0.5)
                self.rnn_cell1 = layers.SimpleRNNCell(units, dropout=0.5)
            

        self.outlayer= layers.Dense(1)
    
    def call(self, inputs, training=None):
        x = self.embedding(inputs)
        state0 = self.state0
        state1 = self.state1
        for word in tf.unstack(x, axis=1):
            out0, state0 = self.rnn_cell0(word, state0, training=training)
            out1, state1 = self.rnn_cell1(out0, state1, training=training)
        x = self.outlayer(out1)
        prob = tf.sigmoid(x)
        return prob

if __name__ == "__main__":
    db_train, db_test = load_data()
    word_idx, idx_word = get_datasets_info()

    model = MyRNN(units, 'lstm')
    model.compile(optimizer=keras.optimizers.Adam(0.001),
                loss = keras.losses.BinaryCrossentropy(),
                metrics=['accuracy']
            )
    model.fit(db_train, epochs=epoches, validation_data=db_test)

    model.evaluate(db_test)
    
