#include <iostream>

int fourMax(int m, int& max1, int& max2);
int fourMin(int m, int& min1, int& min2);

int main()
{
	int n, m, max1, max2, min1, min2, N, sumMin, sumMax;
	std::cout << "Amount of numbers: ";
	std::cin >> N;
	std::cin >> n >> m;
	if (m >= n) {
		max1 = m;
		max2 = n;
		min1 = n;
		min2 = m;
		sumMin = min1 + min2;
		sumMax = max1 + max2;
	}
	else {
		max1 = n;
		max2 = m;
		min1 = m;
		min2 = n;
		sumMin = min1 + min2;
		sumMax = max1 + max2;
	}

	for (int i = 0; i < N - 2; i++) {
		std::cin >> m;
		sumMin = fourMin(m, min1, min2);
		sumMax = fourMax(m, max1, max2);
	}
	std::cout << "sum of 2 highest: " << sumMax << "\n";
	std::cout << "sum of 2 lowest: " << sumMin << "\n";
}

int fourMax(int m, int& max1, int& max2) {
	if (m >= max1) {
		max2 = max1;
		max1 = m;
	}
	else {
		if (m >= max2) {
			max2 = m;
		}
	}
	return max1 + max2;
}

int fourMin(int m, int& min1, int& min2) {
	if (m <= min1) {
		min2 = min1;
		min1 = m;
	}
	else {
		if (m <= min2) {
			min2 = m;
		}
	}
	return min1 + min2;
}