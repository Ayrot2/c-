#include <iostream>;
using namespace std;

int fib(int n, int* mem) {
	if (mem[n] != 0) return mem[n];
	return fib(n - 1, mem) + fib(n - 2, mem);
}

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n == 2) {
		cout << 1;
		return 0;
	}
	int* mem = new int[n + 1]{ 0 };
	mem[1] = 1;
	mem[2] = 1;
	cout << fib(n, mem) << "\n";
	delete[] mem;
	return 0;
}