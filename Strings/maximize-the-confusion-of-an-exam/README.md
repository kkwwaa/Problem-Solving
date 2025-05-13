# 2024. Maximize the Confusion of an Exam

[Description!](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/)

A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

[My Solution](https://github.com/kkwwaa/Problem-Solving/blob/main/Strings/maximize-the-confusion-of-an-exam/solution.py)
***
### Ru Notes

1. Инициализация:
- maxf = 0: Хранит максимальную частоту символа в окне.
- i = 0: Указатель на начало окна.
- count = Counter(): Словарь для подсчёта, сколько раз встретился каждый символ (например, {'T': 3, 'F': 2}).
2. Скользящее окно:
- Перебираем j (конец окна) от 0 до len(s)-1.
- Для каждого j:
  - Увеличиваем частоту символа s[j] в count.
  - Обновляем maxf, если частота s[j] больше текущего maxf.
  - Проверяем условие: если длина окна (j - i + 1) больше maxf + k, окно недопустимо.
- Сужаем окно: уменьшаем частоту символа s[i] и сдвигаем i вправо.
3. Результат:
- После цикла длина максимального допустимого окна — это len(s) - i.
- Это работает, потому что i останавливается на первом индексе, где окно становится недопустимым, а len(s) - i — длина последнего допустимого окна.

**Каждое последующее окно больше предыдущего. Последнее удовлетворяющее условию - наибольшее.**
