

def merge_sort(seq):
	if len(seq) < 2: return seq

	mid = len(seq) // 2
	left_handle = merge_sort(seq[: mid])
	right_handle = merge_sort(seq[mid: ])
	return merge_sort_list(left_handle, right_handle)


def merge_sort_list(seq1, seq2):
	if seq1 == []: return seq2
	if seq2 == []: return seq1

	ret = []

	i, j = 0, 0  # 分别代表seq1, seq2的下标

	while True:
		if seq1[i] < seq2[j]:
			ret.append(seq1[i])
			i += 1
		else:
			ret.append(seq2[j])
			j += 1

		if i >= len(seq1):
			ret.extend(seq2[j:])
			break

		if j >= len(seq2):
			ret.extend(seq1[i:])
			break

	return ret


def test_merge_sort_list():
	seq1 = [1, 2, 3, 4, 6]
	seq2 = [0, 1, 1, 2, 5]
	assert(merge_sort_list(seq1, seq2) == [0, 1, 1, 1, 2, 2, 3, 4, 5, 6])

	seq1 = []
	seq2 = [0, 1, 1, 2, 5]
	assert(merge_sort_list(seq1, seq2) == [0, 1, 1, 2, 5])


def test_merge_sort():
	seq = list(range(10))
	import random
	random.shuffle(seq)
	assert(merge_sort(seq)==sorted(seq))

	