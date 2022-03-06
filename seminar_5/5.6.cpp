#include <iostream>
using namespace std;

int F(int n);

int M(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n - F(M(n - 1));
    }
}

int F(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n - M(F(n - 1));
    }
}
