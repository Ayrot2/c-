#include <iostream>
using namespace std;

void input(int n, int* seq)
{
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}
}

int dyn_solve(int n, int* seq, int* mem)
{
	if (n == 1)
	{
		mem[n] = 1;
		return mem[n];
	}
	if (n > 1 && seq[n - 1] > seq[n - 2])
	{
		mem[n - 1] = dyn_solve(n - 1, seq, mem) + 1;
		return mem[n - 1];
	}
	else mem[n - 1] = dyn_solve(n - 1, seq, mem);

}
int main()
{
	int n;
	cin >> n;
	int* seq = new int[n];
	input(n, seq);
	int* memoization = new int[n] {0};
	cout << dyn_solve(n, seq, memoization);
	return 0;
}