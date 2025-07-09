def dfs(v):
    used[v] = True # отмечаем, что зашли
    for i in range(len(graph[v])): # обрабатываем все смежные вершинки
        to, id_edge = graph[v][i] # вытаскиваем вершину и индекс связующего ребра
        if used[to]: # если ребро уже проложено
            continue
        save_edges[id_edge] = True # оставляем ребро
        dfs(to) # идем дальше

cnt_vertex, cnt_edges = map(int, input().split()) #вводим кол-во ребер и вершин

# создаем массив вершин и матрицу
edges = []
graph = [[] for _ in range(cnt_vertex)]

# ввод графа
for _ in range(cnt_edges):
    x, y = map(int, input().split()) # вершины
    x -=1
    y -=1
    edges.append((x,y)) # добавляем в массив вершин
    graph[x].append((y, len(edges)-1)) # добавляем к вершине, связанную с ней вершину и индекс этого ребра
    graph[y].append((x, len(edges)-1))

save_edges = [0] * cnt_edges # массив ребер по к-ым прошли
used = [0] * cnt_vertex 

dfs(0) # dfs с первой вершинки

cnt_save_edges = sum(save_edges)
for i in range(cnt_edges):
    if save_edges[i]: # если ребро оставили, значит выводим 
        print(edges[i][0]+1, edges[i][1]+1)
