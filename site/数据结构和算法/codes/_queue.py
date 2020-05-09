

from _array import Array


class Queue(object):

	def __init__(self, size):
		self._items = Array(size)
		self.head, self.tail = -1, -1
		self.length = 0

	def __len__(self):
		return self.length

	def push(self, value):
		if self.is_full():
			raise Exception("queue is full")

		self.tail += 1
		index = self.tail % len(self._items)
		self._items[index] = value
		self.length += 1
		self.tail = index

	def pop(self):
		if self.is_empty():
			raise Exception("queue is empty")

		self.head += 1
		index = self.head % len(self._items)
		value = self._items[index]

		self.length -= 1
		self.head = index
		return value

	def is_full(self):
		return self.length == len(self._items)

	def is_empty(self):
		return self.length <= 0


def test_queue():
	queue = Queue(4)
	assert(len(queue) == 0)

	assert(queue.is_empty()==True)

	queue.push(0)
	queue.push(1)
	queue.push(2)
	queue.push(3)
	assert(queue.is_empty()==False)
	assert(queue.is_full()==True)

	assert(queue.pop() == 0)
	assert(queue.is_full()==False)
	assert(queue.pop() == 1)
	assert(queue.pop() == 2)

	queue.push(4)
	assert(queue.pop() == 3)
	assert(queue.pop() == 4)
	assert(queue.is_empty()==True)
	assert(0)

