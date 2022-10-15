#include <iostream>
using namespace std;

template <typename T>
struct Element {
	T element;
	double priority;
};

template <typename T>
void my_swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template< typename T>
struct Comparator {
	virtual bool operator() (T &, T &) = 0;
};

struct ComparatorDouble final : Comparator<double>
{
	bool operator() (double &rha, double &lha) override {
		return lha < rha;
	}
};


template<typename T>
class MaxHeap
{
	Element<T>* harr;
	int heap_size;
	Comparator<T> C;
public:
	MaxHeap(Comparator <T> &C) : C(C), heap_size(0), harr(nullptr) {};

	int parent(int i) { return ((i - 1) / 2); }

	void push(Element<T> key)
	{
		Element<T>* harr2 = new Element<T>[heap_size + 1];
		for (int j = 0; j < heap_size; j++)
		{
			harr2[j] = harr[j];
		}
		harr2[heap_size] = key;
		harr = harr2;
		heap_size++;
		int i = heap_size - 1;

		while (i != 0 && C(harr[parent(i)].priority, harr[i].priority))
		{
			my_swap(harr[parent(i)], harr[i]);
			i = parent(i);
		}
	}

	void poll()
	{
		Element<T>* harr2 = new Element<T>[heap_size - 1];
		for (int j = 1; j < heap_size; j++)
		{
			harr2[j - 1] = harr[j];
		}
		harr = harr2;
		heap_size--;
		int i = heap_size - 1;
		while (i != 0 && C(harr[parent(i)].priority, harr[i].priority))
		{
			my_swap(harr[parent(i)], harr[i]);
			i = parent(i);
		}
	}

	void output()
	{
		for (int i = 0; i < heap_size; i++)
		{
			cout << harr[i].element << "\n";
		}
	}

	void peek()
	{
		cout << harr[0].element << "\n";
	}

	bool is_empty()
	{
		return (heap_size == 0);
	}

	void free()
	{
		delete[] harr;
	}
};


int main()
{
	ComparatorDouble D;
	MaxHeap<double> heap(D);

	Element<double> one;
	one.element = 2;
	one.priority = 1;
	Element<double> two;
	two.element = 1;
	two.priority = 2;
	Element<double> three;
	three.element = 3;
	three.priority = 0;
	heap.push(three);
	heap.push(one);
	heap.push(two);
	heap.is_empty();
	heap.poll();
	heap.output();
	heap.free();
}