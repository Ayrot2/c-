#include <iostream>
using namespace std;

int reverse(int n, int N) {
    int c = 0;
    c = n % 10;
    n = (n - c) / 10;
    if (n != 0) {
        N = N * 10 + c;
        reverse(n, N);
    }
    else return (N * 10 + c);
}


int main()
{
    int n;
    int N = 0;
    cin >> n;
    cout << reverse(n, N);
}