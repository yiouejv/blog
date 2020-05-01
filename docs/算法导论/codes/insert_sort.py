

# 2 5 10 7
# 

def insert_sort(seq):

	for j in range(len(seq)):
		key = seq[j]
		i = j - 1

		while i >= 0 and seq[i] > key:
			seq[i + 1] = seq[i]
			i -= 1

		seq[i+1] = key


def test_insert_sort():
	import random
	seq = list(range(10))
	random.shuffle(seq)

	insert_sort(seq)
	assert(seq==sorted(seq))

