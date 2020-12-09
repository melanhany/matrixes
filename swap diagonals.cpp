#include <iostream>

using namespace std;

void swap_diagonals(int **matrix, int n)
{
	for (int i = 0, j = 0, k = n - 1; j < n; j++, i++, k--) {
		int temp = matrix[i][j];
		matrix[i][j] = matrix[i][k];
		matrix[i][k] = temp;
	}
}

void output(int **matrix, int n)
{
	cout << "Your matrix:" << endl;
	for (int i = 0; i < n; i++, cout << endl)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
	
}
void input(int **matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a" << "[" << i + 1 << "][" << j + 1 << "]" << ": ";
			cin >> matrix[i][j];
		}
	}
}



int main()
{
	int n;
	cout << "The size of matrix: ";
	cin >> n;
	int **matrix = new int*[n];
	input(matrix, n);
	swap_diagonals(matrix, n);
	output(matrix, n);

}