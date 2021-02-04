

from collections import deque



# 定义一个图
graph = {}
graph["you"] = ["alice", "bob", "claire"] 
graph["bob"] = ["anuj", "peggy"] 
graph["alice"] = ["peggy"] 
graph["claire"] = ["thom", "jonny"] 
graph["anuj"] = [] 
graph["peggy"] = [] 
graph["thom"] = [] 
graph["jonny"] = [] 


global searched
global path
searched = []  # 搜索过的人
path = []


# 查找关系网中是否存在'thom'
def find_person(source, target):
    global path, searched
    path.append(source)

    for person in graph[source]:

        if person not in searched:
            searched.append(person)

            if person == target:
                path.append(source)
                path.append(target)
                return path

            find_person(person, target)
            if person in path: path.remove(person)
    return path


print(find_person('you', 'thom'))
