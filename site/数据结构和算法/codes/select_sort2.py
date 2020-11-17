

def select_sort(seq):
	for i in range(len(seq)):
		seq[i] = min(seq[i:])


def test_select_sort():
	seq = list(range(10))

	import random
	random.shuffle(seq)
	select_sort(seq)

	assert(seq==sorted(seq))
