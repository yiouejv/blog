

class Array(object):

	def __init__(self, max_length):
		self.max_length = max_length
		self._items = [None] * max_length

	def __len__(self):
		return self.max_length

	def __getitem__(self, index):
		return self._items[index]

	def __setitem__(self, index, value):
		self._items[index] = value


def test_array():
	arr = Array(5)

	arr[0] = 0
	arr[1] = 1
	arr[2] = 2
	arr[3] = 3
	arr[4] = 4

	assert(len(arr)==5)
	assert(arr[0]==0)
	assert(arr[1]==1)
	assert(arr[2]==2)
	assert(arr[3]==3)
	assert(arr[4]==4)

	arr[4] = 6
	assert(arr[4]==6)
