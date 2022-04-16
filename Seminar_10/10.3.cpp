#include <iostream>
#include <algorithm>
using namespace std;

struct object
{
	int num = 0;
	double weight = 0;
	double utility = 0;
	double cpecific_utility = 0;
};

void input(object* knapsack, int number) {
	for (int i = 0; i < number; i++) {
		cout << i + 1 << ": " << "\n" << "weight: ";
		cin >> knapsack[i].weight;
		cout << "utility: ";
		cin >> knapsack[i].utility;
		knapsack[i].cpecific_utility = knapsack[i].utility / knapsack[i].weight;
		knapsack[i].num = i + 1;
	}
}

double selection(object* knapsack, int number, int capacity) {
	cout << "output: object_number(utility)" << "\n";
	int i = 0;
	double sum = 0;
	while (knapsack[i].weight <= capacity) {
		cout << knapsack[i].num << "(" << knapsack[i].utility << ")" << "\n";
		capacity -= knapsack[i].weight;
		sum += knapsack[i].utility;
		i += 1;
	}
	if (i < number) {
		cout << "fractional part: " << knapsack[i].num << "(" << knapsack[i + 1].cpecific_utility * capacity << ")" << "\n";
		sum += capacity * knapsack[i].cpecific_utility;
	}
	cout << "total utility: ";
	return sum;
}

bool comp(object a, object b) {
	return a.cpecific_utility > b.cpecific_utility;
}

int main() {
	int capacity, number;
	cout << "knapsack capasity: ";
	cin >> capacity;
	cout << "number of objects: ";
	cin >> number;
	object* knapsack = new object[number];
	input(knapsack, number);
	sort(knapsack, knapsack + number, comp);
	cout << "\n";
	cout << selection(knapsack, number, capacity);
	return 0;
}