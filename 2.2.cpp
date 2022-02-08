#include <iostream>

int c = 0;
int two(int n, int m);

int main()
{
	int n, m;
	std::cin >> n;
	m = n;
	c = 1;
	while (n != 0) {
		std::cin >> n;
		if (n != 0) {
			m = two(n, m);
		}
	}
	std::cout << "min element: ";
	std::cout << m << "\n";
	std::cout << "count: ";
	std::cout << c;
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
