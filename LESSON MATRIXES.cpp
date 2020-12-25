#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("result.txt");

void in(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> matrix[i][j];
}

void out(int **matrix, int n)
{
	for(int i = 0; i < n; i++, fout << endl)
		for(int j = 0; j < n; j++)
			fout << matrix[i][j] << " ";
	fout << endl;
}

int op1(int **matrix, int n)
{
	int stroka;
	if (n % 3 != 0)
		stroka = n / 3 + 1;
	else
		stroka = n / 5;
	for (int j = 0; j < n; ++j)
	{
		matrix[stroka - 1][j] = matrix[stroka - 1][j] * -3;
	}
	return **matrix;
}

/*int bubblesort(string *s, int n, int *temp)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			if (s[j] > s[j + 1]) {
				string temporary = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temporary;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{

		temp[i] = stoi(s[i]);
	}
	return *temp;
}

// Here I used method that converts line of numbers to string array and use function that sorts that string array:
// 1. We convert numbers from line to string and add string elements into string array
// 2. We use bubblesort sorting method to lexicographically sort string array
// 3. In the function we convert sorted string elements into integers and add them into one-dimensional int array
// 4. We return one-dimensional array into op2 function
// 5. We change numbers of matrices line to already sorted line of one-dimensional array
// This method does not work, I do not why, but it always crushes
int op2(int **matrix, int n)
{
	string *s = new string[n];
	int *temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			stringstream ss;
			ss << matrix[i][j];
			ss >> s[j];
		}
		bubblesort(s, n, temp);
		for (int l = 0; l < n; l++)
		{
			
			matrix[i][l] = temp[l];
		}
	}
	return **matrix;
}
*/

// I used method that uses next steps:
// 1. Simply bubble sorts the line
// 2. Than I compare numbers by dividing them to 10
// 3. If there is number that lexicographically smaller than 
//    the number we are comparing with, we just swap them
// definitely not effective method
int op2(int **matrix, int n)
{	
	int a;
	// simple bubble sort
	for (int l = 0; l < n; l++) {
		for (int i = 0; i < n - 1; i++) {
			// Last i elements are already in place  
			for (int j = 0; j < n - i - 1; j++)
				if (matrix[l][j] > matrix[l][j + 1]) {
					int temp = matrix[l][j];
					matrix[l][j] = matrix[l][j + 1];
					matrix[l][j + 1] = temp;
				}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] < 9 && matrix[i][j + 1] > 9)
			{
				a = matrix[i][j + 1] / 10;
				if (a < matrix[i][j])
				{
					int temp = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = temp;
				}
			}
			if (matrix[i][j] < 99 && matrix[i][j + 1] > 99)
			{
				a = matrix[i][j + 1] / 100;
				if (a < matrix[i][j])
				{
					int temp = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = temp;
				}
			}
		}
	}
	return **matrix;
}


bool EA(int **matrix, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] <= 0 || matrix[i][j] > 100 || matrix[i][j] % 2 != 0) {
				j = n;
			}
			else
			{
				count += 1;
			}
		}
		if (count == n)
		{
			return true;
		}
		else
		{
			count = 0;
		}
	}
	return false;
}

int statement_true(int **A, int **B, int **C, int n)
{
	int i, j;
	// multiplication by 7 and summ of A and B
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = A[i][j] * 7;
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	op1(C, n);
	
	return **C;
}

int statement_false(int **A, int **B, int **C, int n)
{
	int i, j, k;
	// multiplication by -1
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i][j] = A[i][j] * -1;
		}
	}
	// multiplication by 4
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			B[i][j] = B[i][j] * 4;
		}
	}
	// multiplication of A and B
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				C[i][j] += (A[i][k] * B[k][j]);
			}
		}
	}

	op2(C, n);
	// summ of C and A
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] += A[i][j];
		}
	}

	return **C;
}


int main()
{
	int n, m, i = 0, j = 0;
	
	cout << "Type in n: " << endl;
	cin >> n;

	int **A;
	A = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		A[i] = new int[n];
	}
	// input of elements of matrix a
	in(A, n);

	int **B;
	B = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		B[i] = new int[n];
	}
	// input of elements of matrix a
	in(B, n);

	int **C;
	C = new int*[n];
	// filling up array a with memory
	for (i = 0; i < n; i++) {
		C[i] = new int[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}

	op2(A, n);
	out(A, n);
	/*if (EA(A, n))
	{
		statement_true(A, B, C, n);
		out(C, n);
	}
	else 
	{
		statement_false(A, B, C, n);
		out(C, n);
	}*/
}