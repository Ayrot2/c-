#include <iostream>
using namespace std;

void input(int n, int* seq)
{
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
}

int dyn_solve(int n, int* h_platforms)
{
	int result = 0;
	int i = 0;
	while (i < n - 1)
	{
		if (i < n - 2 && abs(h_platforms[i] - h_platforms[i + 1]) + abs(h_platforms[i + 1] - h_platforms[i + 2]) >
			3 * abs(h_platforms[i] - h_platforms[i + 2]))
		{
			result += 3 * abs(h_platforms[i] - h_platforms[i + 2]);
			i += 2;
		}
		else
		{
			result += abs(h_platforms[i] - h_platforms[i + 1]);
			i += 1;
		}

	}
	if (n == 1) return 0;
	return result;
}
int main()
{
	int n;
	cin >> n;
	int* h_platforms = new int[n];
	input(n, h_platforms);
	cout << dyn_solve(n, h_platforms);
	return 0;
}