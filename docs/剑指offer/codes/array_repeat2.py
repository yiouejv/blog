

def count_range(nums, start, stop):
	count = 0
	for i in range(len(nums)):
		if start <= nums[i] <= stop:
			count += 1
	return count

def find_one_repeat(nums, start, stop):
	if not nums: return -1

	mid = (start + stop) // 2
	count = count_range(nums, start, mid)

	# 递归终止条件
	if stop - start == 1:
		if count > 1:
			return start
		else:
			count = count_range(nums, mid+1, stop)
			if count > 1: return stop
			return -1

	if count > (mid - start + 1):
		return find_one_repeat(nums, start, mid)
	else:
		return find_one_repeat(nums, mid+1, stop)
	return -1


def test_find_one_repeat():
	nums = [ 2, 3, 5, 4, 3, 2, 6, 7 ]
	assert(find_one_repeat(nums, 1, len(nums)) == 3)

	nums = [1, 1, 5, 4, 3, 2, 6, 7]
	assert(find_one_repeat(nums, 1, len(nums)) == 1)

	nums = [1, 3, 2, 4, 5, 5]
	assert(find_one_repeat(nums, 1, len(nums)) == 5)

	nums = [1, 3, 2, 4, 5, 5, 6, 2]
	assert(find_one_repeat(nums, 1, len(nums)) == 2)

	nums = []
	assert(find_one_repeat(nums, 1, len(nums)) == -1)

	nums = [1, 2, 3, 4, 5]
	assert(find_one_repeat(nums, 1, len(nums)) == -1)

