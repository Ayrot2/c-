#include <iostream>

int three(int n, int m, int c);

int main()
{
	int n, m, c, x;
	c = 0;
	std::cin >> n;
	std::cin >> m;
	if (m != 0) {
		while (m != 0) {
			c = three(n, m, c);
			x = m;
			std::cin >> m;
			n = x;

		}
	}

	std::cout << c;
}

int three(int n, int m, int c) {
	if (n > m) {
		c += 1;
	}
	return c;
}