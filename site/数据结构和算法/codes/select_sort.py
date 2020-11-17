

def select_sort(seq):
	new_seq = []
	seq_cp = list.copy(seq)

	for i in range(len(seq)):
		min_elem = min(seq_cp)
		new_seq.append(min_elem)
		seq_cp.remove(min_elem)

	return new_seq


def test_select_sort():
	seq = list(range(10))

	import random
	random.shuffle(seq)

	assert(select_sort(seq)==sorted(seq))

