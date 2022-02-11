#include <iostream>

int five(int a1, int b1, int c1, int a2, int b2, int c2);

int main() {
	int a1, b1, c1, a2, b2, c2;

	std::cout << "a1: ", '\n';
	std::cin >> a1;

	std::cout << "b1: ", '\n';
	std::cin >> b1;

	std::cout << "c1: ", '\n';
	std::cin >> c1;

	std::cout << "a2: ", '\n';
	std::cin >> a2;

	std::cout << "b2: ", '\n';
	std::cin >> b2;

	std::cout << "c2: ", '\n';
	std::cin >> c2;

	int x, y;

	if (five(a1, b1, c1, a2, b2, c2) != 0) {
		x = five(a1, b1, c1, a2, b2, c2);
		y = (-c1 - a1 * x) / (b1);
		std::cout << "x: " << x << "\n";
		std::cout << "y: " << y << "\n";
	}
}


int five(int a1, int b1, int c1, int a2, int b2, int c2) {
	if (a2 * b1 - a1 * b2 == 0) {
		if (c1 == c2) {
			std::cout << "lines are equal", '\n';
			return 0;
		}
		else {
			std::cout << "NO", '\n';
			return 0;
		}
	}
	else {
		return (c2 * b1 - b2 * c1) / (a1 * b2 - a2 * b1);
	}
}