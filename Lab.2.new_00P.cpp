
#include <iostream>
using namespace std;

struct Rectangle {
    int height;
    int width;
};

template< typename T>
class Comparator {
    
};


template<>
class Comparator<double> {
    double rha, lha;
public:
    Comparator(double rha, double lha) : rha(rha), lha(lha) {};
    bool operator () (double lha, double rha)  {
        return lha < rha;
    }
};

template<>
class Comparator<Rectangle> {
    Rectangle rha, lha;
public:
    Comparator(Rectangle rha, Rectangle lha) : rha(rha), lha(lha) {};
    bool operator () (Rectangle lha, Rectangle rha){
        return lha.height * lha.width < rha.height* rha.width;
    }
};

template <typename T>
void my_swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void q_sort(T array[], int size, int low, int height, Comparator <T> C)
{
    
}

template<>
void q_sort< double > (double array[], int size, int low, int height, Comparator<double> C) {
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
    if (j > low) q_sort(array, j - low + 1,  low, j, C);
    if (i < height) q_sort(array, height - i + 1,  i , height, C);
}

template<>
void q_sort< Rectangle >(Rectangle array[], int size, int low, int height, Comparator<Rectangle> C) {
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
    double d_sort_elements[10] = { 3,4,1,7,8,5,6,10,2,9 };
    Comparator<double> D (0,0);
    q_sort(d_sort_elements, 10,  0, 9, D);
    for (int i = 0; i < 10; i++) 
    {
        cout << d_sort_elements[i] << " ";
    }
}

