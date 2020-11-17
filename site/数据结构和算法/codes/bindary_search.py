

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
	assert(0)