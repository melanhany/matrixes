# matrix-diagonals-swap

op1(X) - строку с номером N / 3 округляет вверх и умножает на -3 (все значения в строке)

op2(X) - cортирует все строки матрицы в лексикографическом порядке.

EA(X) - x[i][j]: x[i][j] > 0 && x[i][j] лежит в отрезке [0, 100] && x[i][j] - четное.

Дано две матрицы A и B размерности N*N

Если (EA(A) == True) тогда
op1(7*A+B)
иначе
op2(-A*4*B)+A
