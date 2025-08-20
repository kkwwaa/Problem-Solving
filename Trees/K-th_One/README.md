#  K-th one

[Description!](https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/B?locale=en)

In this task, you need to add to the segment tree the operation of finding the k
-th one.

[My Solution for C++](https://github.com/kkwwaa/Problem-Solving/blob/main/Trees/K-th_One/solution.cpp)
***
- если в правом поддереве больше единиц, чем нам нужно идем туда
- если меньше, то зачеркиваем его, вычитаем кол-во единиц из к (тк их уже прошли) и идем в правое поддерево
<img width="2672" height="1430" alt="image" src="https://github.com/user-attachments/assets/90cbb7f5-61d7-4e0e-b684-1abf689460e9" />
