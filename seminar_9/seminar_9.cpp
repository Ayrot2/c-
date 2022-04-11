using namespace std;
#include <string>
#include <iostream>
/*написать следующие функции для работы с односвязным списком.
* добавление записи в начало списка
* удаление списка
* распечатка списка
* добавление записи в упорядоченный список
* Удаление из списка записи по ключу, если такая запись существует
*/
struct List {
    int key = 0;
    List* next = nullptr;
};

List* add_in_the_beginning(List* begin) {
    List* x = new List;
    x->next = begin;
    cin >> x->key;
    return x;
}

List* input() {
    List* p; //previous 
    int k; //key of current element
    List* x0 = new List;
    cin >> x0->key;
    if (x0->key != -1) {
        p = x0;
        while (cin >> k, k != -1) {
            List* x = new List;
            x->key = k;
            p->next = x; //предыдущий (previous) элемент ссылается на вновь введённый
            p = x; //вновь введённый становится предыдущим (приравниваем указатель на пр эл и указатель
            //на новый элемент)
        }
    }
    else {
        x0->next = nullptr;
    }
    return (x0);
}

void output(List* begin) {
    List* p = begin;
    while (p) {
        cout << p->key << " ";
        p = p->next;
    }
}

void del(List* begin) {
    List* c = begin;
    List* p = nullptr;
    while (c) {
        p = c;
        c = c->next;
        delete p;
    }

}

List* add(int a, List* begin) {
    bool check = false;
    List* c = begin;
    List* p = nullptr;
    while (c) {
        if (a <= c->key) {
            if (c != begin) {
                List* ok = new List;
                ok->key = a;
                ok->next = c;
                p->next = ok;
                check;
                return(begin);
            }
            else {
                List* ok = new List;
                ok->key = a;
                ok->next = c;
                check;
                return(ok);
            }
        }
        p = c;
        c = c->next;
    }
    if (check == false) {
        List* ok = new List;
        ok->key = a;
        p->next = ok;
        ok->next = nullptr;
        return begin;
    }
}

void del_by_key(int k, List*& begin) {
    bool check = true;
    List* c = begin;
    List* p = nullptr;
    while (c) {
        if (c->key == k) {
            if (c != begin) {
                p->next = c->next;
                delete c;
                c = p->next;
                check = false;
            }
            else {
                p = c;
                begin = begin->next;
                c = begin;
                delete p;
                check = false;
            }
        }
        if (check) {
            p = c;
            c = c->next;
        }
        check = true;
    }
}

int main()
{
    List* begin = input();
    begin = add_in_the_beginning(begin);
    output(begin);
    //int a;
    cout << "\n";
    //del(begin);
    //cin >> a;
    //new_begin = add(a,begin);
    //output(begin);
    int k;
    cin >> k;
    del_by_key(k, begin);
    output(begin);
    return 0;
}

