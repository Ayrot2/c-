#include <iostream>
#include <cstdlib>
#include <valarray>
#include <cstring>


using namespace std;

struct Rect
{
    int width = 0;
    int height = 0;
    int area = width * height;
};

bool comparator(const void* x1, const void* x2)
{

    if (*(double*)x1 - *(double*)x2 > 0)   //для типа double
        return true;

    //для типа Rect
    /*
    if ((((Rect*)x1)->width) * (((Rect*)x1)->height) > (((Rect*)x2)->width) * (((Rect*)x2)->height))
        return true;
    */

    else
        return false;
}

void swap(void* lha, void* rha, size_t elemByteSize) {
    void* tmp = malloc(elemByteSize);
    memcpy(tmp, lha, elemByteSize);
    memcpy(lha, rha, elemByteSize);
    memcpy(rha, tmp, elemByteSize);
    free(tmp);
}


int partition(void* arrBegin, int low, int high, size_t elemByteSize, void (*swap)(void*, void*, size_t))
{
    void* pivot = (char*)arrBegin + (low + high) / 2 * elemByteSize;
    int i = low;
    int j = high;

    while (true)
    {
        while (comparator(pivot, (char*)arrBegin + i * elemByteSize))
            i += 1;
        while (comparator((char*)arrBegin + j * elemByteSize, pivot))
            j -= 1;
        if (i >= j)
            return j;
        swap((char*)arrBegin + elemByteSize * (i++), (char*)arrBegin + elemByteSize * (j--), elemByteSize);
    }
}


void qsort(void* arrBegin, int elemNumber, size_t elemByteSize, bool (*comparator)(const void*, const void*), void (*swap)(void*, void*, size_t))
{
    int low = 0, high = elemNumber - 1;
    int pivot;


    if (low < high)
    {
        pivot = partition(arrBegin, low, high, elemByteSize, swap);
        qsort(arrBegin, (size_t)(pivot + 1), elemByteSize, comparator, swap);
        qsort((char*)arrBegin + (pivot + 1) * elemByteSize, (size_t)(elemNumber - pivot - 1), elemByteSize, comparator, swap);
    }
}


int main()
{

    double arr[] = { 58 ,33 ,18 ,59 ,74 ,84 ,97 ,58 ,43 ,18 ,61 };  //вариант для типа double
    int arrLength = 11;

    qsort(arr, arrLength, sizeof(double), comparator, swap);

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << ' ';

    /*
    const int arrLength = 5;                                    //вариант массива
    Rect arr[arrLength];                                        //для типа
    for (int i = 0; i < arrLength; i++){                        //Rect
        cin >> arr[i].width;
        cin >> arr[i].height;
    }
    cout << "input is over";

    qsort(arr, arrLength, sizeof(Rect), comparator, swap);

    for (int i = 0; i < arrLength; i++)
        cout << "(" << arr[i].width << "," << arr[i].height << ")" << " ";
    */
    return 0;
}

