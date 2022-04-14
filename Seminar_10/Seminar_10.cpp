#include <iostream>
#include <algorithm>
using namespace std;

struct application
{
    int num;
    int begin =0 ;
    int end = 0;
};
void input(application ap[], int number) {
    for (int i = 0; i < number; i++) {
        ap[i].num = i + 1;
        cout << "begin: ";
        cin >> ap[i].begin;
        cout << "end: ";
        cin >> ap[i].end;
        cout << "\n";
    }
}
void output(application ap[], int n) {
    for (int i = 0; i < n; i++) {
        cout << ap[i].num << "  " << ap[i].begin << "  " << ap[i].end << "\n";
    }
}
bool comp(application a, application b) {
    return a.end < b.end;
}

void solve(application ap[], int n) {
    int k = 0;
    cout << ap[0].num << " ";
    for (int i = 0; i < n-1; i++) {
        if (ap[k].end <= ap[i + 1].begin) {
            cout << ap[i+1].num << " ";
            k = i + 1;
        }
   }
    cout << "\n";
}

int main()
{
    int number;
    cout << "number of applications: " << "\n";
    cin >> number;
    application* ap = new application[number];
    input(ap, number);
    sort(ap, ap + number, comp);
    cout << "applications: " << "\n";
    solve(ap, number);
    cout << "\n" << "sorted array:" << "\n";
    output(ap, number);
    delete[] ap;
}