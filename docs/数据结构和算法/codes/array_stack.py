

from _array import Array


class ArrayStack(object):

	def __init__(self, size):
		self._size = size
		self.top = 0
		self._items = Array(size)

	def __len__(self):
		return self.top

	def push(self, value):
		if self.top >= self._size:
			raise Exception("stack is full")

		self._items[self.top] = value
		self.top += 1

	def pop(self):
		if self.top <= 0:
			raise Exception("stack is empty")

		v = self._items[self.top - 1]
		self._items[self.top - 1] = None
		self.top -= 1
		return v

	def is_empty(self):
		return self.top == 0


def test_array_stack():
	astack = ArrayStack(5)

	astack.push(1)
	astack.push(2)
	astack.push(3)
	astack.push(4)
	astack.push(5)
	# astack.push(6)

	assert(len(astack) == 5)

	assert(astack.pop()==5)
	assert(len(astack) == 4)

	assert(astack.pop()==4)
	assert(astack.pop()==3)
	assert(astack.pop()==2)
	assert(astack.pop()==1)
	# assert(astack.pop())

	assert(astack.is_empty())

