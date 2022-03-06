#include <iostream>
using namespace std;
void rec_2() {
    int n, m;
    cin >> n;
    if (n != 0) {
        cin >> m;
        if (m != 0) {
            cout << "   " << n << "\n";
        }
        else return;
        rec_2();
    }
    else
        return;
}

int main()
{
    rec_2();
}
