'''
	面试题3: 找出数组中重复的数字
	在一个长度为n的数组里的所有数字都在0~n-1的范围内。
	数组中某些数字是重复的，但是不知道有几个数字是重复的了，也不知道数字重复了几次。
	请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2,3,1,0,2,5,3},那么对应的输出重复的数字2或者3。
'''

def find_one_repeat(nums):
	for i in range(len(nums)):
		while nums[i] != i:
			if nums[nums[i]] == nums[i]: return nums[i]
			nums[nums[i]], nums[i] = nums[i], nums[nums[i]]  # 若写为 nums[i], nums[nums[i]] = nums[nums[i]], nums[i] ，则 nums[i] 先被赋值，之后 nums[nums[i]] 指向的元素则会出错。
	return -1


def test_find_one_repeat():
	nums = [2, 3, 1, 0, 2, 5, 3]
	assert(find_one_repeat(nums) == 2)

	nums = [1, 2, 3, 4, 0]  # 没有重复元素
	assert(find_one_repeat(nums) == -1)	

	nums = [0, 0, 1, 2, 3]  # 重复元素为最小数
	assert(find_one_repeat(nums) == 0)

	nums = [0, 1, 3, 2, 4, 4]  # 重复元素为最大数
	assert(find_one_repeat(nums) == 4)

	nums = []
	assert(find_one_repeat(nums) == -1)


if __name__ == '__main__':
	test_find_one_repeat()

