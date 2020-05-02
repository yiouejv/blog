

class Node(object):

	def __init__(self, value=None, nxt=None):
		self.value = value
		self.next = nxt

	def __str__(self):
		return '<value: {value}, next={next}>'.format(value=self.value, next=self.next)


class LinkList(object):
	'''单链表'''
	def __init__(self):
		self.head, self.tail = None, None
		self.length = 0

	def __iter(self):
		cur_node = self.head

		while cur_node != self.tail:
			yield cur_node
			cur_node = cur_node.next

		yield self.tail

	def __len__(self):
		return self.length

	def __iter__(self):
		for node in self.__iter():
			yield node.value

	def append(self, value):
		node = Node(value=value)

		if self.head is None:
			self.head = node
			self.tail = node
		else:
			self.tail.next = node
			self.tail = node
		self.length += 1

	def left_append(self, value):
		node = Node(value=value)

		node.next = self.head
		self.head = node
		self.length += 1


	def find(self, value):
		for v in self:
			if v == value:
				return True
		return False

	def delete(self, value):
		if self.head.value == value:
			self.head = self.head.next
			self.length -= 1
			return value

		if self.tail.value == value:
			for node in self.__iter():
				if node.next == self.tail:
					self.tail = node
					self.length -= 1
					return value

		for node in self.__iter():
			if node.next.value == value:
				node.next = node.next.next
				self.length -= 1
				return value

		return -1



def test_linklist():
	ll = LinkList()

	ll.append(1)
	ll.append(2)
	assert(len(ll)==2)
	ll.append(3)
	ll.append(4)
	ll.append(5)
	assert(len(ll)==5)
	assert(list(ll)==list(range(1, 6)))

	ll.delete(1)
	assert(len(ll)==4)
	assert(list(ll)==[2, 3, 4, 5])

	ll.append(6)
	assert(len(ll)==5)
	assert(list(ll)==[2, 3, 4, 5, 6])

	ll.delete(6)
	assert(len(ll)==4)
	assert(list(ll)==[2, 3, 4, 5])

	ll.delete(3)
	assert(list(ll)==[2, 4, 5])

	ll.left_append(0)
	assert(len(ll)==4)
	assert(list(ll)==[0, 2, 4, 5])

	assert(ll.find(0))
	assert(ll.find(100))

	assert(0)