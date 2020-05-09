

from _array import Array


class Slot(object):

    def __init__(self, key, value):
        self.key, self.value = key, value

    def __str__(self):
        return '<key: {key}, value: {value}>'.format(key=self.key, value=self.value)

class HashTable(object):
    UNUSE = None               # 未使用过
    EMPTY = Slot(None, None)    # 使用过被删除了

    def __init__(self):
        self._items = Array(4)
        self.length = 0

    def __str__(self):
        res = ''
        for solt in self._items:
            if solt not in (HashTable.UNUSE, HashTable.EMPTY):
                res += str(solt)
        return res

    def _hash(self, key):
        return abs(hash(key)) % len(self._items)

    def _index_can_insert(self, index):
        return self._items[index] is HashTable.UNUSE or self._items[index] is HashTable.EMPTY

    @property
    def _load_factor(self):
        return self.length / float(len(self._items))

    def _find_can_insert_index(self, key):
        index = self._hash(key)

        while not self._index_can_insert(index):
            index = self._hash(index + 1)
        return index

    def _rehash(self):
        new_length = len(self._items) * 2
        old_items = self._items
        self._items = Array(new_length)

        self.length = 0
        for solt in old_items:
            if solt is not HashTable.EMPTY and solt is not HashTable.UNUSE:
                index = self._find_can_insert_index(solt.key)
                self._items[index] = solt
                self.length += 1

    def __setitem__(self, key, value):
        if key in self:
            index = self._find_key(key)
            self._items[index].value = value
        else:
            # 检查装载因子, >0.7重哈希
            if self._load_factor > 0.7:
                self._rehash()

            index = self._find_can_insert_index(key)
            self._items[index] = Slot(key, value)
            self.length += 1

    def _find_key(self, key):
        origin_index = self._hash(key)  # 查找起点，如果找了一圈又回到了起点，则没有key
        index = origin_index

        while self._items[index] is not HashTable.UNUSE:
            if self._items[index] is HashTable.EMPTY:  # 注意如果是 EMPTY，继续寻找下一个槽
                index = self._hash(index + 1)
                if index == origin_index:
                    return None
                continue

            if self._items[index].key == key:
                return index
            else:
                index = self._hash(index + 1)
                if index == origin_index:
                    return None

    def __getitem__(self, key):
        index = self._find_key(key)
        if index is None: return None
        return self._items[index].value

    def __len__(self):
        return self.length

    def remove(self, key):
        index = self._find_key(key)
        if index is None:
            raise KeyError()

        self._items[index] = HashTable.EMPTY
        self.length -= 1

    def __contains__(self, key):
        index = self._find_key(key)
        return index is not None

    def __iter__(self):
        for solt in self._items:
            if solt not in (HashTable.UNUSE, HashTable.EMPTY):
                yield solt.key


def test_hash_table():
    a = HashTable()
    assert(len(a) == 0)

    a[None] = None
    assert(len(a) == 1)

    a['a'] = 0
    a['b'] = 1
    assert(len(a) == 3)
    assert(a[None] is None)
    assert(a['a'] == 0)
    assert(a['b'] == 1)
    assert(a['c'] == None)

    a.remove('b')
    assert(len(a)==2)

    a['b'] = 1
    a['c'] = 2
    a['d'] = 3
    a['e'] = 4
    a['f'] = 5
    a['g'] = 6
    a['g'] = 7
    print(a)
    assert(a['b']==1)
    assert(a['c']==2)
    assert(a['d']==3)
    assert(a['e']==4)
    assert(a['f']==5)
    assert(a['g']==7)

test_hash_table()