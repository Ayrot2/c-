using namespace std;
#include <string>
#include <iostream>

struct Student {
    string name;
    string second_name;
    int age = 0;
    int grade = 0;
    int m_number = 0;
    int* marks = nullptr;
};

void input(Student arr[5]) {
    for (int i = 0; i < 5; i++) {
        cin >> arr[i].name >> arr[i].second_name >> arr[i].age >> arr[i].grade
            >> arr[i].m_number;
        arr[i].marks = new int[arr[i].m_number];
        for (int j = 0; j < arr[i].m_number; j++) {
            cin >> arr[i].marks[j];
        }
    }
}

void new_mark(Student& s, int mark) {
    int* marks_new = new int[s.m_number + 1];
    for (int i = 0; i < s.m_number; i++) {
        marks_new[i] = s.marks[i];
    }
    marks_new[s.m_number] = mark;
    s.marks = marks_new;
    s.m_number += 1;
}

void add_mark(Student& s, int mark) {
    double mark_sum = 0;
    for (int i = 0; i < s.m_number; i++) {
        mark_sum += s.marks[i];
    }
    int k = 0;
    while ((mark_sum + k * mark) / (s.m_number) < 4.5) {
        k += 1;
        new_mark(s, mark);
    }
    cout << s.name << " " << s.second_name << " ";
    for (int i = 0; i < s.m_number; i++) {
        cout << s.marks[i] << " ";
    }
    cout << "\n";
}


int main()
{
    Student s[5];
    input(s);
    for (int i = 0; i < 5; i++) {
        add_mark(s[i], 5);
        delete s[i].marks;
    }
}
