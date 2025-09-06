# Ликбез по XOR
<img width="908" height="350" alt="image" src="https://github.com/user-attachments/assets/f9e75b69-2327-4222-b183-7f730421cadf" />

# Применение а задачах
<img width="1008" height="867" alt="image" src="https://github.com/user-attachments/assets/ef1ef63c-f05d-4335-ab28-780118ca69d7" />


## Задача соседний XOR
<img width="1003" height="451" alt="image" src="https://github.com/user-attachments/assets/451d93f7-4364-4b5e-9003-733837a48a4f" />

```cpp
void solve(){
    int t;
    cin>>t;
    while(t--) {
        ll n;
        bool ok=true;
        cin >> n;
        vl a(n),b(n);
        fin(a);fin(b);
        forn(i, 0, n - 1) {
            if (!(b[i]==a[i] ||           // если итак равны
            b[i] == (a[i]^a[i + 1]) ||    // если после операции равны
            (a[i]^b[i+1]) == b[i])){      // если b[i+1] == a[i+1], а b[i] = a[i] ^ a[i+1], то
                ok=false;                 // b[i] = a[i] ^ a[i+1]
                break;
            }
        }
        ifyn(ok && b[n-1]==a[n-1]);
    }
}
```
