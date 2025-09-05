<img width="1336" height="246" alt="image" src="https://github.com/user-attachments/assets/598c15fb-d66e-4e0d-8061-6eb1d89321e7" />


В этой задаче ты можешь:

- заменить x на x + k
- заменить x на |x - k|

Это значит, что ты можешь двигать число вверх и вниз по шагу k, пока не получишь нужный результат.

**Но важно:**
ты не можешь получить любое число — только те, которые эквивалентны по модулю k, либо те, чья сумма с другим числом делится на k.

<img width="1118" height="628" alt="image" src="https://github.com/user-attachments/assets/02079965-19c5-49b3-8773-5be8cdb9da58" />

min(...) получаем универсальное представление, которое одинаково работает для всех чисел, которые можно привести друг к другу по правилам задачи.

<img width="1270" height="369" alt="image" src="https://github.com/user-attachments/assets/7ec1070f-b77e-4966-8621-c8dbcafeeb20" />

```cpp
ll normx(ll x, ll k){
    return min(x%k, (k- x%k)%k);
}

void solve(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vl t(n), s(n);
        forn(i,0,n){
            ll a;
            cin>>a;
            s[i] = normx(a, k);
        }
        forn(i,0,n){
            ll a;
            cin>>a;
            t[i] = normx(a,k);
        }
        sort(all(s));
        sort(all(t));
        bool ok=true;
        forn(i,0,n){
            if (t[i]!=s[i]){ // можем ли мы с помощью прохода по числовой прямой
                ok=false;    // с шагом К получить каждое число
                break;
            }
        }
        ifyn(ok);
    }
}
```


