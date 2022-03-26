#include <iostream>
using namespace std;



void input(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i * n + j];
		}
		cout << "\n";
	}
}

int determinant(int matrix[], int n) {
	if (n == 1) {
		return (matrix[0]);
	}
	else {
		int det = 0;
		int k = 1;
		int* matrix_1 = new int[(n - 1) * (n - 1)];
		for (int i = 0; i < n; i++) {
			int j = 0;
			for (int p = 0; p < n * n; p++) {
				if (p > n - 1 && p % n != i) {
					matrix_1[j] = matrix[p];
					j += 1;
				}
			}
			det += determinant(matrix_1, n - 1) * k * matrix[i];
			k *= -1;
		}
		delete[]matrix_1;
		return(det);
	}
}

int main() {
	int det = 0;
	int n;
	cin >> n;
	int* matrix = new int[n * n];
	input(matrix, n);
	cout << determinant(matrix, n);
}