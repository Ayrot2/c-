#include <iostream>
using namespace std;
void rec_1() {
    int n;
    cin >> n;
    if (n != 0) {
        if (n % 2 != 0) {
            cout << "   " << n << "\n";
        }
        rec_1();
    }
    else
        return;
}

int main()
{
    rec_1();
}
