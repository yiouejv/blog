'''
    原位置交换版本
'''

def quick_sort(seq, begin, end):
    if begin < end:
        pivot = partition(seq, begin, end)
        quick_sort(seq, begin, pivot)
        quick_sort(seq, pivot+1, end)


def partition(seq, begin, end):
    pivot_index = begin
    left = begin
    right = end

    while left < right:
        
        while seq[left] < seq[pivot_index]:
            left += 1

        while seq[right] > seq[pivot_index]:
            right -= 1

        seq[left], seq[right] = seq[right], seq[left]

    seq[pivot_index], seq[left] = seq[left], seq[pivot_index]
    return right


def test_quick_sort():
    seq = list(range(10))
    seq_copy = seq.copy()

    import random
    random.shuffle(seq_copy)
    quick_sort(seq, 0, len(seq)-1)
    assert(seq==sorted(seq_copy))