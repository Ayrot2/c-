#include <iostream>
int one(int n, int m);
int main () {
	int n, m;
	m = 0;
	do {
		std::cin >> n;
		m = one(n, m);
	} while (n != 0);

	std::cout << m;
}

int one(int n, int m) {
	if (n % 2 == 0) {
		if (n > m) {
			m = n;
		}
	}
	return m;
}