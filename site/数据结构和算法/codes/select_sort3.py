

def select_sort(seq):

	for i in range(len(seq)):
		_min = seq[i]

		for j in range(i+1, len(seq)):
			if seq[j] < _min:
				_min = seq[j]
		seq[i] = _min


def test_select_sort():
	seq = list(range(10))

	import random
	random.shuffle(seq)
	select_sort(seq)

	assert(seq==sorted(seq))
	assert(0)