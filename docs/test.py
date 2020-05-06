

# def _sum(seq):
# 	if seq == []: return 0
# 	if len(seq) == 1: return seq[0]
# 	return seq[0] + _sum(seq[1:])


# print(_sum(range(10000)))


# def _max(seq):
# 	if seq == []: raise
# 	if len(seq) == 1: return seq[0]
# 	max_num = _max(seq[1:])
# 	return seq[0] if seq[0] > max_num else max_num


# print(_max([0, 1, 2, 2, 5, 3]))



# 二分查找的基线条件和递归条件

# 0 1 2 3 4 5 6 7 8 9


def bindary_search(seq, target, begin=0, end=None):
	if end is None: end = len(seq) - 1

	if end < begin: return None

	tmp = (begin+end)//2
	if seq[tmp] == target:
		return tmp
	elif seq[tmp] > target:
		end = tmp - 1
	else:
		begin = tmp + 1
	return bindary_search(seq, target, begin=begin, end=end)


def test_bindary_search():
	seq = [0, 1, 2, 5, 6, 8, 9]
	assert(bindary_search(seq, -1) is None)
	assert(bindary_search(seq, 0)==0)
	assert(bindary_search(seq, 1)==1)
	assert(bindary_search(seq, 2)==2)
	assert(bindary_search(seq, 5)==3)
	assert(bindary_search(seq, 6)==4)
	assert(bindary_search(seq, 8)==5)
	assert(bindary_search(seq, 9)==6)
	assert(bindary_search(seq, 10) is None)