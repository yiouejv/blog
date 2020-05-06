'''
	需额外空间版本
'''

def quick_sort(seq):
	if len(seq) <= 1: return seq

	pivot = seq[0]
	less = [i for i in seq[1:] if i < seq[0]]
	greater = [i for i in seq[1:] if i >= seq[0]]
	return quick_sort(less) + [pivot] + quick_sort(greater)


def test_quick_sort():
	seq = list(range(10))
	import random
	random.shuffle(seq)
	assert(quick_sort(seq)==sorted(seq))
