#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#include <locale.h>
using namespace std;


//���� ��� ������� A � B ����������� N*N
//����(EA(A) == True) �����
//op1(7 * A + B)
//�����
//op2(-A * 4 * B) + A

//op1(X) - ������ � ������� N / 3 ��������� ����� � �������� �� -3 (��� �������� � ������)
void op1(int **matrix, int n)
{
	int stroka;
	if (n % 3 != 0)
		stroka = n / 3 + 1;
	else
		stroka = n / 3;
	for (int j = 0; j < n; ++j)
	{
			matrix[stroka - 1][j] = matrix[stroka - 1][j] * -3;
		//a[i][j] ;
	}
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << " ";
		}
	cout << endl;
}

//op2(X) - c�������� ��� ������ ������� � ������������������ �������.
void op2(int **matrix, int n)
{
	
}

//EA(X) - x[i][j]: x[i][j] > 0 && x[i][j] ����� � �������[0, 100] && x[i][j] - ������.
bool EA(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] < 0 && matrix[i][j] > 100)
				return false;
		}
	}
}

int main()
{
	int n, m, i = 0, j = 0;
	int **a;
	cout << "Type in elements of first matrix " << endl;
	cin >> n;
	a = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	// input of elements of matrix a
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
		{
			cout << "Type in element a" << i + 1 << j + 1 << " : ";
			cin >> a[i][j];
		}
	//����(EA(A) == True) �����
	//op1(7 * A + B)
	//�����
	//op2(-A * 4 * B) + A
	if (EA(a, n))
		op1(7 * A + B)
	else
		op2((-A * 4 * B) + A)

}