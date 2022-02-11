#include <iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int x, y, c1, c2, c3, c4;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	c4 = 0;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		if (x > 0 && y > 0) {
			c1++;
		}
		if (x < 0 && y>0) {
			c2++;
		}
		if (x < 0 && y < 0) {
			c3++;
		}
		if (x > 0 && y < 0) {
			c4++;
		}
	}
	int amount;
	amount = max(max(c1, c2), max(c3, c4));
	if (amount == c1) {
		cout << "Firts qarter" << "\n";
	}
	if (amount == c2) {
		cout << "Second qarter" << "\n";
	}
	if (amount == c3) {
		cout << "Third qarter" << "\n";
	}
	if (amount == c4) {
		cout << "Forth qarter" << "\n";
	}
	cout << "amount of points: " << amount;
}
