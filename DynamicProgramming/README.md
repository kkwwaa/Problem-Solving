# Задачка про бросание 2ух яиц
<img width="1773" height="898" alt="image" src="https://github.com/user-attachments/assets/27e03039-fde5-4944-a1f6-adfe65d5a8c0" />
```cpp
vector<vi> dp;

int ss(int F, int cnt){
    if (F==0 || F==1) // если на малой высоте
        return F;

    if (cnt==1) // если осталось 1 яйцо
        return F; // далее только так

    if (dp[F][cnt]!=-1) // если уже посчитано
        return dp[F][cnt]; // возв-ем

    int ans=1e9;
    forn(f,1,F+1){ // ищем на оставшейся высоте ф
        // собираем ответ, +1 тк истрачена попытка
        // f-1-если яйцо разбилось,  F-f - если нет
        ans = min(ans, 1 + max(ss(f-1, cnt-1), ss(F-f, cnt)));  // макс тк мы должны быть certain, мин тк ищем minimum number of moves
    }
    dp[F][cnt] = ans; // сохраняем знач-ие для высоты, чтобы после не пересч-ть
    return ans;
}

void solve(){
    int n;
    cin>>n;

    dp.resize(n+1,vi(3, -1));
    cout<<ss(n,2);
}
```
