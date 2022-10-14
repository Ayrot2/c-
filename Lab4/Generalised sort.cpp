
#include <iostream>
using namespace std;

struct Rectangle {
    int height;
    int width;
};

template< typename T>
struct Comparator {
    virtual bool operator() (T, T) = 0;
};

struct DoubleComparator final : Comparator<double> {
    bool operator() (double lha, double rha) override {
        return lha < rha;
    }
};


template <typename T>
void my_swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void q_sort(T * array, int size,  int low, int height, Comparator<T>& C)
{
    int i = low;
    int j = height;

    int pivot = (i + j) / 2;

    while (i <= j) {
        while (C(array[i], array[pivot])) i++;
        while (C(array[pivot], array[j])) j--;
        if (i <= j) {
            my_swap(array[i], array[j]);
            if (i == pivot) pivot = j;
            if (j == pivot) pivot = i;
            i++;
            j--;
        }
    }
    if (j > low) q_sort(array, j - low + 1, low, j, C);
    if (i < height) q_sort(array, height - i + 1, i, height, C);
}


int main()
{
    double *d_sort_elements = new double[10];
    DoubleComparator D;
    for (int i = 0; i < 10; i++) {
        d_sort_elements[i] = 10 - i;
    }
    q_sort<double>(d_sort_elements, 10, 0, 9, D);
    for (int i = 0; i < 10; i++)
    {
        cout << d_sort_elements[i] << " ";
    }
}