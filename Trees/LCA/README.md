# LCA

[Description!](https://acm.timus.ru/problem.aspx?space=1&num=1471)

Given a weighted tree with n vertices (numbered from 0 to n-1). Find the shortest distance between pairs of vertices specified in queries.

[My Solution](https://github.com/kkwwaa/Problem-Solving/blob/main/Trees/LCA/solution.cpp)
***

## Solution Explanation
Решение использует алгоритм LCA (Lowest Common Ancestor) с техникой двоичных прыжков (Binary Lifting) для эффективного нахождения ближайшего общего предка двух вершин и вычисления расстояния между ними.

### Обход дерева (DFS):

Проводим DFS от корня (вершина 0) для вычисления:
- dist[v] — расстояния от корня до вершины v.
- tin[v] и tout[v] — времена входа и выхода для вершины v (для проверки предков).
- up[v][lvl] — предок вершины v на расстоянии 2^lvl (для двоичных прыжков).

**Функция isParent:** проверяет, является ли вершина a предком вершины b, используя времена tin и tout.

**Функция lca:** находит ближайшего общего предка для вершин u и v с помощью двоичных прыжков.
Если u — предок v или наоборот, возвращаем соответствующую вершину.
Иначе ищем предка, поднимаясь по дереву с помощью массива up.

Вычисляем расстояние: dist[u] + dist[v] - 2 * dist[LCA].

**Временная сложность:**
- Подготовка (DFS и заполнение up): O(n log n).
- Каждый запрос LCA: O(log n).
- Общая: O(n log n + q log n).

### Ru Notes

- Использование двоичных прыжков позволяет эффективно находить LCA за O(log n).
![Снимок экрана 2025-06-28 144652](https://github.com/user-attachments/assets/c55ae3a6-c287-48f1-982b-a7aebe8c8a29)

- Вычисление расстояния
![2025-06-28_15-03-11](https://github.com/user-attachments/assets/01316d9e-b7ed-4c91-b594-94a6c3a2f142)


