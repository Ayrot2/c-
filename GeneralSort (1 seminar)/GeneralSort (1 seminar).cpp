#include <iostream>
#include <cstdlib>
using namespace std;
struct Rectangle
{
    double height;
    double width;
};

int comparator_double(void * x1, void * x2)
{
    if (( * (double*)x2 - *(double*)x1) > 0) return 0;
    if ((*(double*)x2 - *(double*)x1) == 0) return 1;
    if ((*(double*)x2 - *(double*)x1) < 0) return 2;
}

int comparator_rectangle(void* x1, void* x2)
{
    if (((Rectangle*)x2)->height * (((Rectangle*)x2)->width)
        - ((Rectangle*)x1)->height * (((Rectangle*)x1)->width) > 0) return 0;
    if (((Rectangle*)x2)->height * (((Rectangle*)x2)->width)
        - ((Rectangle*)x1)->height * (((Rectangle*)x1)->width) == 0) return 1;
    if (((Rectangle*)x2)->height * (((Rectangle*)x2)->width)
        - ((Rectangle*)x1)->height * (((Rectangle*)x1)->width) < 0) return 2;
}

void swap_void (void* x1, void* x2, size_t element_size)
{
    void* tmp = malloc(element_size);
    memcpy(tmp, x1, element_size);
    memcpy(x1, x2, element_size);
    memcpy(x2, tmp, element_size);
    free(tmp);
    
}

void q_sort(void* array, size_t element_size, int size, int (*comparator) (void*, void*),
   int low, int high) 
{
    int i = low;
    int j = high;

    void* pivot = (char*)array + ((i+j)/2)*element_size;

    while (i <= j)
    {
        while (comparator((char*)array + i * element_size, pivot) == 0)
            i++;
        while (comparator((char*)array + j * element_size, pivot) == 2)//true
            j--;
        if (i <= j)
        {
            swap_void((char*)array + i * element_size, (char*)array + j * element_size,
                element_size);
            if ((char*)array + i * element_size == (char*)pivot)
            {
                pivot = (char*)array + j * element_size;
            }
            else if ((char*)array + j * element_size == (char*)pivot)
            {
                pivot = (char*)array + i * element_size;
            }
            i++;
            j--;
            
        }
    }
    if (j > low)
        q_sort(array, element_size, j - low+1, comparator, low, j);//left
    if (i < high)
        q_sort(array, element_size, high-i+1, comparator, i, high);//right
}

int question()
{
    cout << "choose type:" << '\n' << "0 - double" << '\n' << "1 - Rectangle" << '\n';
    int n;
    cin >> n;
    return n;
}

void input_array(void * array, int type, int size)
{
    if (type == 0)//double type
    {
        for (int i = 0; i < size; i++)
        {
            cin >> *(double*)((char*)array + i * sizeof(double));
        }
    }
    else if (type == 1)//Rectangle type
    {
        for (int i = 0; i < size; i++)
        {
            cin >> (* (Rectangle*)((char*)array + i * sizeof(Rectangle))).height;
            cin >> (*(Rectangle*)((char*)array + i * sizeof(Rectangle))).width;
        }
    }
}

void output_array(void* array, int type, int size)
{
    if (type == 0)//double type
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(double*)((char*)array + i * sizeof(double)) << " ";
        }
    }
    else if (type == 1)//Rectangle type
    {
        for (int i = 0; i < size; i++)
        {
            cout << ((*(Rectangle*)((char*)array + i * sizeof(Rectangle))).height )*((*(Rectangle*)((char*)array + i * sizeof(Rectangle))).width) << " ";
        }
    }
}


int main()
{
    int n;
    cout << "print number of elements: ";
    cin >> n; //number of elements


    if (question() == 0)
    {
        double* array = new double[n];
        input_array(array, 0, n);
        q_sort(array, sizeof(double), n, comparator_double, 0, n - 1);
        output_array(array, 0, n);
    }
    else 
    {
        Rectangle* array = new Rectangle[n];
        input_array(array, 1, n);
        q_sort(array, sizeof(Rectangle), n, comparator_rectangle, 0, n - 1);
        output_array(array, 1, n);
        }

}
