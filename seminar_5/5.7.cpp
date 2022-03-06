#include <iostream>
using namespace std;


void arr_in(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void arr_out(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void fun(int arr[], int i, int j) {
    int largest = j;
    int left = j * 2 + 1;
    int right = j * 2 + 2;
    if (arr[largest] < arr[right] && right < i + 1) {
        largest = right;
    }
    if (arr[largest] < arr[left] && left < i + 1) {
        largest = left;
    }
    if (largest != j) {
        swap(arr[j], arr[largest]);
        fun(arr, i, largest);

    }
}

void Heap_sort(int arr[], int n) {

    for (int i = n - 1; i >= 1; i--) {
        if (i % 2 == 0) {
            for (int j = i / 2 - 1; j >= 0; j--) {
                fun(arr, i, j);
            }
        }
        else {
            for (int j = i / 2; j >= 0; j--) {
                fun(arr, i, j);
            }
        }
        swap(arr[i], arr[0]);
    }
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    arr_in(arr, n);
    Heap_sort(arr, n);
    arr_out(arr, n);
}