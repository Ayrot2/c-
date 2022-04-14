#include <iostream>
using namespace std;

bool input(int n, int* coins) {
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		if (coins[i] % coins[i - 1] != 0 && i > 1) {
			cout << "non-canonical system";
			return false;
		}
	}
	return true;
}

void exchange(int* coins, int n, int m) {
	int k = 0;
	cout << "exchange: ";
	for (int i = n - 1; i >= 0; i--) {
		while (m >= coins[i]) {
			m = m - coins[i];
			cout << coins[i] << " ";
			k += 1;
		}
	}
	cout << "\n" << "amount of coins: " << k;
}

int main() {
	int quantity, money;
	cout << "quanity of coin nominals: ";
	cin >> quantity;
	int* coins = new int[quantity];
	cout << "nominals: " << "\n";
	if (input(quantity, coins) == true) {
		cout << "money to change: ";
		cin >> money;
		exchange(coins, quantity, money);
	}
}