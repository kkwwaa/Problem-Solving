class Node:
    def __init__(self, parent, size, mn, mx):
        self.parent = parent
        self.size = size
        self.mn = mn
        self.mx = mx

def make_set(v, my_set):
    my_set[v] = Node(v, 1, v, v)

def find_set(v, my_set):
    if v == my_set[v].parent:
        return v
    else:
        my_set[v].parent = find_set(my_set[v].parent, my_set)
        return my_set[v].parent

def union_sets(a,b,my_set):
    a = find_set(a, my_set)
    b = find_set(b, my_set)
    if a!=b:
        if my_set[a].size < my_set[b].size:
            a,b = b,a
        my_set[b].parent = a
        my_set[a].size += my_set[b].size
        my_set[a].mn = min(my_set[a].mn, my_set[b].mn)
        my_set[a].mx = max(my_set[a].mx, my_set[b].mx)

n, m = map(int, input().split()) # вводим кол-во элементов и запросов
my_set = [None] * n # создаем массив множеств

for i in range(n):
    make_set(i, my_set) # создаем начальные мн-ва (1 эл-т) и добавляем в массив

for _ in range(m):
    inp = list(input().split()) # вводим строку
    s = inp[0] # первое слово - тип операции
    u = int(inp[1])-1 # первый элемент

    if s == "union":
        v = int(inp[2])-1 # второй, если объединение
        union_sets(u,v,my_set)

    elif s == "get":
        u = find_set(u,my_set) # актуализируем данные
        print(my_set[u].mn + 1, my_set[u].mx + 1, my_set[u].size) # выдаем up-to-date инфу
