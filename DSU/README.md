## People are leaving
```cpp
vl p;
ll n,m;
// получение лидера мн-ва
int get(int v) {
    if (v > n) return n + 1; // за пределами
    if (p[v] == v) return v; // возвращаем лидера
    return p[v] = get(p[v]); // сжатие пути
}

void solve() {
    cin >> n >> m;
    p.assign(n + 2, 0);
    for (int i = 1; i <= n + 1; ++i) p[i] = i;

    while (m--) {
        char type;
        int x;
        cin >> type >> x;
        if (type == '-') {
            // человек с позиции x ушёл: перепрыгнуть на следующего
            p[x] = get(x + 1);
        } else { // '?'
            int ans = get(x);
            if (ans == n + 1) cout << -1 << '\n';
            else cout << ans << '\n';
        }
    }
}
