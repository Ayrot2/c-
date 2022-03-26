#include <iostream>
using namespace std;


int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new) {
	int* arr = new int[n_new]; // адрес на n_new интов в куче
	if (source != NULL) {
		for (int i = 0; i < n_new && i < n_old; i++) {
			arr[i] = source[i];
		}
		delete[]source;
	}
	//for (int i = 0; i < n_new; i++) {
		//cout << "mark!! " << arr[i]<< " "<<"\n"; для проверки
	//}
	return arr;
}

int main() {
	unsigned int n, i;
	cin >> n;
	int* a = my_slightly_dumb_reallocation(NULL, 0, n / 2);
	for (i = 0; i < n / 2; i++)
		cin >> a[i];
	a = my_slightly_dumb_reallocation(a, n / 2, n);
	for (; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	cout << sum << endl;
	a = my_slightly_dumb_reallocation(a, n, n / 2);
	a = my_slightly_dumb_reallocation(a, n / 2, 0);
	a = my_slightly_dumb_reallocation(a, 0, 0);
}