

class Node(object):

	def __init__(self, value=None, pre=None, nxt=None):
		self.value = value
		self.pre = pre
		self.next = nxt

	def __str__(self):
		return '<value: {value}, pre:{pre}, next:{next}>'.format(value=self.value, pre=self.pre, next=self.next)


class DoubleLinkList(object):

	def __init__(self):
		self.head, self.tail = None, None
		self.length = 0

	def __len__(self):
		return self.length

	def __iter(self):
		cur_node = self.head

		while cur_node != self.tail:
			yield cur_node
			cur_node = cur_node.next
		yield self.tail

	def __iter__(self):
		for node in self.__iter():
			yield node.value

	def append(self, value):
		node = Node(value=value)

		if self.head is None:
			self.head, self.tail = node
			self.head.pre = node
			self.head.next = node

			self.tail.pre = node
			self.tail.next = node
		else:
			self.tail.next = node
			node.pre = self.tail
			self.tail = node

		self.length += 1

	def left_append(self, value):
		node = Node(value=value)

		if self.head is Node:
			self.head, self.tail = node
			self.head.pre = node
			self.head.next = node

			self.tail.pre = node
			self.tail.next = node
		else:
			node.next = self.head
			self.head.pre = node
			self.head = node

		self.length += 1

	def find(self, value):
		for v in self:
			if v == value:
				return True
		return False

