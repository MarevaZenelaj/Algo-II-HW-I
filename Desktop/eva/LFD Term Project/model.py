import numpy as np
import keras
import tensorflow as tf
import csv
from keras import Model, Sequental

def read_csv_file(filename):
	dataset = []
	with open(filename, "r") as f:
		data = csv.reader(f, delimiter='\n')
		header = next(data)
		numberColumns = len(header)
		counter = 0
		for row in data:
			columns = list(row[0].split(','))
			newcolumns = []
			for number in columns:
				newcolumns.append(float(number))

			dataset.append(newcolumns)
			counter += 1

	dataset = np.asarray(dataset)
	return dataset

train = read_csv_file("train.csv")
labels = train[:,-1].astype(int)
train = train[:,:-1]
test = read_csv_file('test.csv')

print("train data: ", train.shape)
print("test data: ", test.shape)

model = Sequental()
model.add(Dense(2,input_dim=))