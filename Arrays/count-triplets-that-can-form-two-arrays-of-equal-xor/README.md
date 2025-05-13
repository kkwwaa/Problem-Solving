# Count Triplets That Can Form Two Arrays of Equal XOR

[Description!](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/)

Given an array of integers arr. We want to select three indices **i, j and k** where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

**Return the number of triplets (i, j and k) Where a == b.**

[My Solution](https://github.com/kkwwaa/Problem-Solving/blob/main/Arrays/count-triplets-that-can-form-two-arrays-of-equal-xor/solution.py)
***
### Ru Notes

Разбор кода
1. Вставка 0 (A.insert(0, 0)):
- Добавляем 0 в начало массива, чтобы A[0] = 0 представлял пустой префикс.
- Это упрощает вычисление префиксных XOR и корректно обрабатывает случай, когда подмассив начинается с индекса 0.
2. Вычисление префиксных XOR (A[i + 1] ^= A[i]):
- Преобразуем массив так, чтобы A[i] стал равен XOR всех элементов оригинального массива от 0 до i-1.
- Например, для A = [2, 3, 1]:
- После вставки: A = [0, 2, 3, 1].
- После цикла: A = [0, 2, 2^3, 2^3^1].
3. Поиск пар (i, j):
- Перебираем все пары индексов (i, j), где i < j.
- Если A[i] == A[j], то XOR подмассива от i до j-1 равен 0.
- Для каждой такой пары добавляем j - i - 1 к результату, так как это количество индексов k между i и j.
4. Возврат результата:
- Суммируем все подходящие триплеты и возвращаем итог.
