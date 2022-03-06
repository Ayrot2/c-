#include <iostream>
using namespace std;
void rec_4(int& max, int& count) {
    int n;
    cin >> n;
    if (n != 0) {
        if (count == 0) {
            max = n;
            ++count;
            rec_4(max, count);
        }
        else {
            if (n > max) {
                max = n;
                count = 1;
            }
            else if (n == max) {
                count += 1;
            }
            rec_4(max, count);
        }
    }
    else return;
}

int main()
{
    int max = 0;
    int count = 0;
    rec_4(max, count);
    cout << count;
}
