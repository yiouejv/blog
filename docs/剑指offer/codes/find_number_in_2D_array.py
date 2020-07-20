

def find_number_in_2D_array(nums, row, col, target):
    r, c = 0, col - 1
    while nums and row > r >= 0 and c >= 0:
        v = nums[r][c]
        if v == target:
            return True
        elif v > target:
            c -= 1
        else:
            r += 1
    return False


def test_find_number_in_2D_array():
    nums = [
        [1, 2, 8, 9],
        [2, 4, 9, 12],
        [4, 7, 10, 13],
        [6, 8, 11, 15]
    ]
    assert(find_number_in_2D_array(nums, 4, 4, 5) == False)
    assert(find_number_in_2D_array(nums, 4, 4, 7) == True)
    assert(find_number_in_2D_array(nums, 4, 4, 10) == True)

    nums = []
    assert(find_number_in_2D_array(nums, 0, 0, 10) == False)

    nums = [
        [1, 2],
        [3, 4],
    ]
    assert(find_number_in_2D_array(nums, 2, 2, 2) == True)
    assert(find_number_in_2D_array(nums, 2, 2, 5) == False)
