#include <iostream>
using namespace std;

void input(int slippers[], int N) {
	for (int i = 0; i < N; i++) {
		cin >> slippers[i];
	}
}

int search(int slippers[], int N) {
	int min = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (slippers[i] < 0 && slippers[i] + slippers[j] == 0) {
				min = j - i;
			}
		}
	}
	delete[] slippers;
	return (min);
}

int main()
{
	int N;
	cin >> N;
	int* slippers = new int[N];
	input(slippers, N);
	cout << "\n";
	cout << search(slippers, N);

}

