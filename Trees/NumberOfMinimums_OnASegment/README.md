# Number of Minimums on a Segment

[Description!](https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C?locale=en)

In this task, you need to change the code of the segment tree so that, in addition to the minimum on a segment, it also counts the number of elements equal to the minimum.

[My Solution for C++](https://github.com/kkwwaa/Problem-Solving/blob/main/Trees/NumberOfMinimums_OnASegment/solution.cpp)
***

<img width="3051" height="1292" alt="image" src="https://github.com/user-attachments/assets/e9d159db-1eb9-4640-a064-8954d2dee0d9" />

<img width="2660" height="1250" alt="image" src="https://github.com/user-attachments/assets/9187dbfa-3e79-4132-a48d-c3ddc2c9335c" />

```cpp
// Запрос индекса 1-го элемента >= x правее l
ll get(int v, int tl, int tr, int x, int l) {
    if (tr < l || tree[v] < x) return -1; //если вышли за границу или зашли в ячейку меньше
    if (tl == tr) return tl; //если спустились до листа и он нас удовлетворяет
    int tm = (tl + tr) >> 1;

    int leftAns = get(v << 1, tl, tm, x, l); //ищем первое вхождение, спускаясь влево
    if (leftAns != -1) return leftAns; //если нашли возвращаем
    return get(v << 1 | 1, tm + 1, tr, x, l); //если нет спускаемся вправое п/дерево
}
