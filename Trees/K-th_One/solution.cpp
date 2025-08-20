#include <bits/stdc++.h>

// #pragma GCC target ("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")


#define en '\n'
#define  isz(x) int((x).size())
#define ins insert
#define pb push_back
#define eb emplace_back
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sortlargetosmall(x) sort(all(x), greater<>())
#define sortsmalltolarge(x) sort(all(x), less<>())
#define fin(x) for (auto &it: x) cin >> it
#define fout(x) for (auto &it: x) cout << it << en;
#define finpairs(x) for (auto &it: x) cin >> it.first >> it.second
#define foutpairs(x) for (auto &it: x) cout << it.first << ' '<<it.second << ' '; cout << en
#define cno cout << "NO" << en
#define cyes cout << "YES" << en
#define PI acos(-1.0L)
#define cmo cout << -1 << en
#define ifyn(x) x ? cyes : cno
#define nline cout << en
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define from_to(start, finish) for (int i = (start); i < int(finish); ++i)
#define forn(i, start, finish) for (int i = (start); i < int(finish); ++i)
#define setmem(a, val) memset(a, val, sizeof(a))

std::vector<std::string> split_names(const std::string &s) {
    std::vector<std::string> result;
    std::istringstream iss(s);
    std::string token;
    while (std::getline(iss, token, ',')) {
        result.push_back(token);
    }
    return result;
}

template<typename T>
concept Printable = requires(std::ostream &os, T a) {
    { os << a } -> std::same_as<std::ostream&>;
};

template<typename T>
concept Container = requires(T a) {
    std::begin(a);
    std::end(a);
} && (!std::same_as<T, std::string>);


template<typename T>
requires Printable<T> && (!Container<T>)
void print_value(std::ostream &os, const T &value) {
    os << value;
}

template<Container T>
void print_value(std::ostream &os, const T &container) {
    os << "{";
    bool first = true;
    for (const auto &elem : container) {
        if (!first)
            os << ", ";
        first = false;
        print_value(os, elem);
    }
    os << "}";
}

template<typename T, typename U>
void print_value(std::ostream &os, const std::pair<T, U> &p) {
    os << "{";
    print_value(os, p.first);
    os << ", ";
    print_value(os, p.second);
    os << "}";
}

template<typename Tuple, std::size_t... Is>
void print_tuple_impl(std::ostream &os, const Tuple &t, std::index_sequence<Is...>) {
    os << "{";
    bool first = true;
    // Распаковываем элементы кортежа с разделителем
    ((os << (first ? "" : ", "), first = false, print_value(os, std::get<Is>(t))), ...);
    os << "}";
}

template<typename... Args>
void print_value(std::ostream &os, const std::tuple<Args...> &t) {
    print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
}

template<typename T, typename Container, typename Compare>
void print_value(std::ostream &os, std::priority_queue<T, Container, Compare> pq) {
    os << "{";
    bool first = true;
    while (!pq.empty()) {
        if (!first)
            os << ", ";
        first = false;
        print_value(os, pq.top());
        pq.pop();
    }
    os << "}";
}
template<typename T>
void print_value(std::ostream &os, std::queue<T> q) {
    os << "{";
    bool first = true;
    while (!q.empty()) {
        if (!first)
            os << ", ";
        first = false;
        print_value(os, q.front());
        q.pop();
    }
    os << "}";
}

template<typename... Args>
void print_args(const char* names, Args&&... args) {
    std::vector<std::string> namesVec = split_names(names);

    std::cout << "[DEBUG] ";
    int index = 0;
    ((std::cout << namesVec[index++] << " = ", print_value(std::cout, args), std::cout << "; "), ...);
    std::cout << "\n";
}

// Макрос для вывода переменных
#define watch(...) if (debug) { print_args(#__VA_ARGS__, __VA_ARGS__); }
const int debug = 1;

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//template<typename T>
//using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;


//const long double pi = 3.141592653589793238462643383279;

using ll =  long long;
using ld  = long double;
using i64 = int64_t;
using i32 = int32_t;
using str = string;
// pairs
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<typename T>
using V = vector<T>;
using vi = V<int>;
using vl = V<ll>;
using vpii = V<pii>;
using vpll = V<pll>;
using vb = V<bool>;
using vc = V<char>;
using vs = V<string>;
using vld = V<ld>;

using vvc = V<vc>;
using vvb = V<vb>;
using vvi = V<vi>;
using vvl = V<vl>;
using vvs = V<vs>;
using vvpii = V<vpii>;
using vvpll = V<vpll>;
using vvld = V<vld>;

using vvvi = V<vvi>;
using vvvl = V<vvl>;

using ull = unsigned long long;

using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
using pqsmalleststart = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using pqmaximumstart = priority_queue<T, vector<T>, less<T>>;


template<typename C> void reuniq(C& c) { c.erase(unique(all(c)), end(c));}


template <typename T>
T binpow(T a, T n) {
    T res = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = res * a ;
        a = a * a ;
        n >>= 1;
    }
    return res ;
}

template <typename T>
T binpow(T a, T n, T mod) {
    T res = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res % mod;
}


template <typename T>
vector<vector<T>> mul(const vector<vector<T>> &v1, const vector<vector<T>> &v2, const int mod) {
    vector<vector<T>> v(v1.size(), vector<T>(v1[0].size()));

    for (size_t row = 0; row < v.size(); ++row) {
        for (size_t k = 0; k < v.size(); ++k)  {
            for (size_t col = 0; col < v.size(); ++col) {
                v[row][col] += v1[row][k] * v2[k][col] % mod;
                v[row][col] %= mod;
            }
        }
    }

    return v;
}
template <typename T>
vector<vector<T>> binpow(vector<vector<T>> v, const int step, const int mod){
    if (step == 0) {
        for (size_t i = 0; i < v.size(); ++i) {
            for (size_t j = 0; j < v.size(); ++j) {
                v[i][j] = 0;
                if (i == j) v[i][j] = 1;
            }
        }
        return v;
    }
    else if (step == 1) {
        return v;
    } else {
        if (step % 2) {
            return mul(v, binpow(v, step - 1, mod), mod);
        } else {
            vector<vector<T>> v2 = binpow(v, step/2, mod);
            return mul(v2, v2, mod);
        }
    }
}


long long mysqrt (long long x) {
    long long ans = 0;
    for (ll k = 1LL << 30; k != 0; k /= 2) {
        if ((ans + k) * (ans + k) <= x) {
            ans += k;
        }
    }
    return ans;
}


__int128 mysqrt (__int128 x) {
    __int128 ans = 0;
    __int128 one = 1;
    for (__int128 k = one << 63; k != 0; k /= 2) {
        if ((ans + k) * (ans + k) <= x) {
            ans += k;
        }
    }
    return ans;
}


string bin(auto x, int len = 0) {
    auto s = bitset<sizeof(x) * 8>(x).to_string();
    s = s.substr(min(s.size(), s.find('1')));
    if (len == 0) {
        if (s.empty()) s = "0";
        return s;
    }
    str res(len, '0');
    if (s.empty()) return res;
    res.replace(max(0, len - isz(s)), s.size(), s);
    return res;
}

template <typename T>
T perm(T n, T k){
    T answ = 1;
    T dif = n - k;
    for (T i = 1; i < k + 1; ++i) {
        answ += answ * dif / i;
    }
    return answ;
}

template <typename T>
T perm(T n, T k, T mod){
    T answ = 1;
    T dif = n - k;
    for (T i = 1; i < k + 1; ++i) {
        answ += (answ * dif % mod ) * binpow(i, mod-2, mod);
        answ %= mod;
    }
    return answ;
}


__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void setmax(T &a, T b) {
    a = std::max(a, b);
}

template <typename T>
void setmin(T &a, T b) {
    a = std::min(a, b);
}

template <typename T>
vector<T> compress(vector<T> vec) {
    vector<T> nvec = vec;
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < nvec.size(); ++i) {
        nvec[i] = lower_bound(vec.begin(), vec.end(), nvec[i]) - vec.begin() + 1;
    }
    return nvec;
}

// dot product
// |a||b|cos(a,b) = a.x * b.x + a.y * b.y

// cross product
// |a||b|sin(a,b) = a.x * b.y - a.y * b.x
// > 0 = left turn
// < 0 =right turn

// atan2(x,y)

//struct comp{
//    bool operator ()(const int& lhs, const int& rhs) const {
//        return isz(can[lhs]) < isz(can[rhs]);
// }

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
void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        tree[v] = 1-tree[v];
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v * 2, tl, tm, pos);
    else
        update(v * 2 + 1, tm + 1, tr, pos);
    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

// Запрос к-ой ед-цы
ll get(int v, int tl, int tr, int k) {
    if (tl == tr)
        return tl; // дошли до нужного листа
    ll tm = (tl+tr) >> 1;
    if (tree[v*2] >= k) return get(v*2, tl, tm, k); // если в правом поддереве больше ед-ц, чем нам нужно идем туда
    else return get(v*2+1, tm+1, tr, k-tree[v*2]); // если меньше, то зачеркиваем его, вычитаем кол-во ед-ц из к (тк их уже прошли) и идем в правое под-во
}

int solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);

    fin(a);

    build(1, 0, n - 1, a);

    forn(i,0,m) {
        int type, x, k;
        cin >> type >> k;
        if (type == 1) {
            // обновление: a[x] = y
            update(1, 0, n - 1, k);
        } else {
            // найти утую ед-цу
            cout << get(1, 0, n - 1, k+1) << en;
        }
    }

    return 0;
}

void multiSolve() {
    int t_; cin >> t_; while(t_--) {
        solve();
    }
}

void brute() {
    cyes;
}

void trash() {
}

void foo() {
}

i32 main(){

#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    cout.setf(ios::fixed); cout.precision(20);

//    foo();
//    trash();
//    brute();
    solve();
//    multiSolve();
}
