# Segment Tree for the SumLCA

[Description!](https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A?locale=en)

In this task, you need to write a regular segment tree for the sum.

[My Solution for C++](https://github.com/kkwwaa/Problem-Solving/blob/main/Trees/SegmentTree_ForTheSum/solution.cpp)
[My Solution for Python](https://github.com/kkwwaa/Problem-Solving/blob/main/Trees/SegmentTree_ForTheSum/solution.py)
***

## Solution Explanation

Решение использует дерево отрезков (Segment Tree) для эффективной обработки двух типов запросов: обновление элемента массива и вычисление суммы на отрезке.

**Построение дерева (build):**

Строим дерево отрезков рекурсивно, начиная с корня (v=1, отрезок [0, n-1]).
- Для листа сохраняем значение массива.
- Для нелистовых вершин делим отрезок на два, рекурсивно строим левое и правое поддерево, затем *суммируем* их значения.

**Обновление элемента (update):**

Рекурсивно идём к листу, определяя нужные поддеревья, и обновляем его.
На выходе из рекурсии обновляем задействованные суммы.

**Запрос суммы на отрезке (get):**

Для отрезка [l, r] проверяем:
- Если текущий отрезок [tl, tr] полностью покрывает [l, r], возвращаем tree[v].
- Если нет пересечения, возвращаем 0.
Иначе разбиваем запрос на левое и правое поддеревья и суммируем результаты.

**Сложность**

Время: O(n) для построения, O(log n) для каждого запроса → O(n + m log n).
Память: O(n) для дерева и массива.
