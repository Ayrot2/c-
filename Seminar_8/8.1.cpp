using namespace std;
#include <string>
#include <iostream>
struct Student {
    string second_name;
    string name;
    int group;
    int ses[5];

};

void input(Student arr[10]) {
    for (int i = 0; i < 10; i++) {
        cin >> arr[i].second_name >> arr[i].name >> arr[i].group;
        for (int j = 0; j < 5; j++) {
            cin >> arr[i].ses[j];
        }
    }
}

void sort(Student arr[10]) {
    int marks[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        // cout << "lox!! ";
        for (int j = 0; j < 10; j++) {
            if (arr[i].second_name.compare(arr[j].second_name) == 1) {
                marks[i] += 1;
            }
        }
    }
    cout << "\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                swap(marks[j], marks[j + 1]);
                swap(arr[j].second_name, arr[j + 1].second_name);
                swap(arr[j].name, arr[j + 1].name);
            }
        }
    }
}

void D_grade(Student arr[10]) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i].ses[j] <= 2) {
                count += 1;
                cout << arr[i].second_name << " " << arr[i].name << " " << arr[i].group << "\n";
                break;
            }
        }
    }
    if (count == 0) {
        cout << "NO";
    }
}

int main()
{
    Student stud1[10];
    input(stud1);
    sort(stud1);
    D_grade(stud1);
}
