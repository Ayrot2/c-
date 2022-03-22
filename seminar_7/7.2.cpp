#include <iostream>
using namespace std;

void input(int slippers[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> slippers[i];
	}
}

void output(int sequence[], int N) {
	int even, uneven;
	if (N % 2 == 0) {
		even = N - 1;
		uneven = N - 2;
	}
	else {
		even = N - 2;
		uneven = N - 1;
	}
	for (int i = uneven; i >= 0; i -= 2) {
		cout << sequence[i] << " ";
	}
	for (int i = even; i >= 0; i -= 2) {
		cout << sequence[i] << " ";
	}
}
