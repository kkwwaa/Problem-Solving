# Minimum Spanning Tree

[Description!](https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=32&id_topic=55&id_problem=678)

Given an undirected, weighted, connected graph, you are required to determine the weight of its minimum spanning tree (MST).

[My Solution](https://github.com/kkwwaa/Problem-Solving/blob/main/Graphs/MinimumSpanningTree/solution.py)
***
### Ru Notes

Решение использует **алгоритм Крускала** для нахождения минимального остовного дерева (MST) в неориентированном взвешенном связном графе. Алгоритм основан на **системе непересекающихся множеств (Disjoint Set Union, DSU)** с оптимизациями сжатия путей и объединения по рангу (размеру).

- Сохраняем рёбра в список `edges` как тройки `(w, (u, v))`.
- Сортируем список `edges` по весу рёбер в порядке возрастания, чтобы обрабатывать рёбра от наименьшего веса.
- Инициализация DSU (`make_set(v, p, sz)`)
- Обработка рёбер (алгоритм Крускала) (`find_set(...)`, `union_set(...)`

#### Оптимизации
- **Сжатие путей** в `find_set`: Уменьшает высоту дерева DSU, приближая её к O(1) для поиска.
- **Объединение по размеру** в `union_set`: Присоединяем меньшее множество к большему, минимизируя глубину дерева.
- **Сортировка рёбер**: Гарантирует, что мы всегда выбираем рёбра с минимальным весом, что соответствует жадному подходу Крускала.

- **Временная сложность**: O(m log m) для сортировки рёбер + O(m α(n)) для операций DSU, где `α(n)` — почти константа (функция Аккермана).
