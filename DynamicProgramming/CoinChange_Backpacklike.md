<img width="1768" height="971" alt="image" src="https://github.com/user-attachments/assets/f79c22c3-adb7-4879-85e7-dfb8a2bd0a8c" />


```cpp
int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0]=0;
        for (int i=1;i<=amount;i++){               //заполняем все суммы оптимальным способом
            for (auto coin: coins){                //проходимся по всем имеющимся монеткам
                if (i>=coin)                       //выбираем наименьшее кол-во монет, поэтому смотрим оптимальное заполнение предыдущего такого,
                dp[i] = min(dp[i], dp[i-coin]+1);  // что при добавлении монетки выходит нужная сумма i
            }
        }
        if (dp[amount]<1e9) return dp[amount];
        else return -1;
    }
```
