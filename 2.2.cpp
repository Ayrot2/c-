#include <iostream>

int c = 0;
int two(int n, int m);

int main()
{
	int n, m, N;
	std::cout << "amount of numbers: ";
	std::cin >> N;

	std::cin >> n;
	m = n;
	c = 1;

	for (int i = 0; i < N - 1; i++) {
		std::cin >> n;
		m = two(n, m);
	}

	std::cout << "min element: " << m << "\n";
	std::cout << "count: " << c;
}

int two(int n, int m) {
	if (n < m) {
		m = n;
		c = 1;
	}
	else {
		if (n == m) {
			c += 1;

		}
	}
	return m;
}