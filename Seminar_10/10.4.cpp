#include <iostream>
using namespace std;

void input(int** cities, int number) {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cin >> cities[i][j];
		}
	}
}

int mem(int* memoization, int number) {
	for (int i = 0; i < number; i++) {
		if (memoization[i] == 0) return 1;
	}
	return 0;
}

int min(int* arr, int number, int* memoization) {
	int m;
	int index;
	for (int k = 0; k < number; k++) {
		if (memoization[k] == 0) {
			m = arr[k];
			index = k;
		}
	}
	for (int j = 1; j < number; j++) {
		if (arr[j] < m && arr[j] != 0) {
			if (memoization[j] == 0) {
				m = arr[j];
				index = j;
			}
		}
	}
	cout << index + 1;
	memoization[index] = 1;
	return index;
}

void solve(int** cities, int number, int* memoization, int city) {
	if (mem(memoization, number) != 0) {
		solve(cities, number, memoization, min(cities[city], number, memoization));
	}
}

int main() {
	int number;
	cin >> number;
	int** cities;
	cities = new int* [number];
	for (int i = 0; i < number; i++) {
		cities[i] = new int[number];
	}
	input(cities, number);
	int* memoization = new int[number];
	for (int i = 0; i < number; i++) {
		memoization[i] = 0;
	}
	memoization[0] = 1;
	cout << 1;
	solve(cities, number, memoization, 0);
}