
const int N = 100000;
vl tree(4 * N); // Сегментное дерево

// Построение дерева
void build(int v, int tl, int tr, const vi& a) {
    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a); // левый ребенок
    build(v * 2 + 1, tm + 1, tr, a); // правый ребенок
    tree[v] = tree[v * 2] + tree[v * 2 + 1]; // вычисляем сумму
}

// Обновление значения
void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v * 2, tl, tm, pos, val);
    else
        update(v * 2 + 1, tm + 1, tr, pos, val);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

// Запрос суммы на отрезке [l, r]
ll get(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return tree[v];
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, min(r, tm)) +
           get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);

    fin(a);

    build(1, 0, n - 1, a);

    forn(i,0,m) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            // обновление: a[x] = y
            update(1, 0, n - 1, x, y);
        } else {
            // запрос суммы от x до y-1
            cout << get(1, 0, n - 1, x, y - 1) << en;
        }
    }

    return 0;
}
