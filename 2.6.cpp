#include <iostream>
using namespace std;

void six(int ro, int r);

int main() {
	int x, y, a, b, r;
	cin >> x >> y >> a >> b >> r;
	int ro;
	ro = (x - a) * (x - a) + (y - b) * (y - b);

	six(ro, r);
}


void six(int ro, int r) {
	if (ro <= r * r) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}