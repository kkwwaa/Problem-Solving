## Main from DSU
```cpp
ll get(ll v){
    if (p[v] != v)
        p[v] = get(p[v]);
    return p[v];
}

void create_set(ll v){
    p[v] = v;
    sz[v] = 1;
}

void union_sets(ll a, ll b){
    a = get(a);
    b = get(b);

    if (a==b) return;

    if (sz[a] > sz[b])
        swap(a,b);

    p[a] = b;
    sz[b] +=sz[a];
}
```
## Get_next DSU
<img width="1271" height="850" alt="image" src="https://github.com/user-attachments/assets/b1d434cd-ce74-4ed9-ade9-293b6676e559" />

```cpp
// получить след-ий необработанный
ll get_next(ll v){
    if (nxt[v] == v) return v; // если еще необр-ый
    return nxt[v] = get_next(nxt[v]); // если уже обр-ый ищем след-ий необр-ый
}

// объединяем все мн-ва с а по б
// начинаем с первого необраб-го(из границ) мн-ва
void union_range(ll a, ll b){
    for (ll v = get_next(a); v < b; v = get_next(v)){ // переходим к след необр-ому
        union_teams(v,b);// об-яем
        nxt[v] = v+1; // помечаем обр-ым
    }
}
```
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
