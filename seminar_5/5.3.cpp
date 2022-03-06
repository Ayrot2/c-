#include <iostream>
using namespace std;
void rec_3(int& count, double& average) {
    int n;
    cin >> n;
    count += 1;
    if (n != 0) {
        if (count == 1) {
            average = n;
            rec_3(count, average);
        }
        else {
            average = (average * (count - 1) + n) / count;
            rec_3(count, average);
        }
    }
    else return;
}

int main()
{
    int count = 0;
    double average = 0.0;
    rec_3(count, average);
    cout << average;
}


