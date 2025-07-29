# v-индекс в-ны, в к-ую кладем значение
# tl-левая граница диапазона по к-му двигаемся ([1,8] для 1)
# tr-правая граница диапазон
# tree[]-дерево
# a[]-изначальный массив
# строим с низов, сначала распределяем единичные отрезки (эл-ты массива а)
# потом поднимаемся выше и высчитываем предков,
# чтобы дойти до рута - общего ответа (всей суммы, макс или мин на всем массиве а)
def build(v:int, tl:int, tr:int, tree:[], a:[]):
    if (tl == tr): #дошли до листка -> дошли до отрезка [2,2]
        tree[v] = a[tl] # кладем значение
        return
    tm = (tl+tr)//2 #вычисляем середину
    #left [tl, tm]
    #right [tm+1, tr]
 
    build(v*2, tl, tm, tree, a) #левый ребенок имеет:
    #индекс v*2   |  отрезок от tl до tm
    build(v*2+1, tm+1, tr, tree, a) #правый ребенок имеет:
    #индекс v*2+1 |  отрезок от tm+1 до tr
    tree[v] = tree[v*2] + tree[v*2+1] #вычисляем верхние вершинки - суммы нижних
 
# v-в-на на к-ой находимся
# tl-tr - отрезок за к-ый она отвечает
# pos-индекс в-ны, к-ую нужно изменить
# val-на что меняем
def update(v:int, tl:int, tr:int, pos:int, val:int, tree:[]):
    if tl == tr: #дошли до pos
        tree[v] = val # присвоили
        return
    tm = (tl+tr)//2 #нашли середину
    # left [tl, tm]
    # right [tm+1, tr]
    if pos <= tm: #если индекс меньше макс значения отрезка
        update(v*2, tl, tm, pos, val, tree) #значит идем в левый п-к
    else:
        update(v*2+1, tm+1, tr, pos, val, tree) #иначе в правый
    tree[v] = tree[v * 2] + tree[v * 2 + 1] #обновляем суммы, к-ые зависили от изме-го знач-я
 
# v-текущая вершина
# tl-tr - ее отрезок
# l-r - на каком подотрезке надо найти сумму
# ф-ия находит a[l] + a[l+1] + ... + a[r]
def get(v:int, tl:int, tr:int, l:int, r:int, tree:[]):
    if l>r:
        return 0
    if tl == l and tr == r:
        return tree[v] # нашли нужный отрезок
    tm = (tl+tr)//2
    sumLeft = get(v*2, tl, tm, l, min(r, tm), tree)
    sumRight = get(v*2+1, tm+1, tr, max(l, tm+1), r, tree)
    return sumLeft+sumRight
 
N = 100000
tree = [0]*(4*N)
n,m = map(int, input().split())
a = list(map(int, input().split()))
build(1,0,n-1,tree,a)
for it in range(m):
    type, x,y = map(int, input().split())
    if type == 1:
        update(1, 0, n-1, x,y, tree)
    else:
        print(get(1, 0, n-1, x, y-1, tree))
