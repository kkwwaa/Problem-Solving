import math
import random

def find_set(a):
    if a == p[a]:
        return a
    else:
        p[a] = find_set(p[a])
        return p[a]

def unite_set(a,b):
    a = find_set(a)
    b = find_set(b)
    if random.getrandbits(1):
        a, b = b,a
    if a != b:
        p[a] = b

INF = 1e9 + 7
MAXN = 1e5 + 20
eps = 1e-9
inf = 1e18
pi = math.acos(-1.0)

n = int(input()) # кол-во вершин
p = list(range(n+1)) # список вида 0, 1, 2, ..., n
x, y = [0] * (n+1), [0] * (n+1) # списки координат
for i in range(1, n+1): # вводим координаты
    x[i], y[i] = map(int, input().split())

graph = []
m = int(input()) # кол-во ребер
for _ in range(m):
    x1, y1 = map(int, input().split())
    graph.append((0, (x1, y1))) # добавляем в граф ребра с весом 0 - тк уже построены, платить НЕ надо

# строим полный граф
for i in range(1, n+1): # i и j - вершины
    for j in range(i+1, n+1): # x[] и y[] - координаты в-н
        dis = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) # вычисляем расстояние: сумма квадратов разности координат
        graph.append((dis, (i,j))) # доавляем в граф расстояние и связанные в-ны

ans = 0.
graph.sort() # сортируем ребра по возрастанию веса
for i in range(len(graph)):
    x1, y1 = graph[i][1] # досатем вершины
    c1 = graph[i][0] # вес ребра
    if find_set(x1) != find_set(y1): # смотрим принадлежат ли они одному обр-ся дереву
        ans += math.sqrt(c1) # если нет, значит добавляем расстояние в ответ
        unite_set(x1,y1) # и проводим ребро -> объединяем деревья

print(ans)


