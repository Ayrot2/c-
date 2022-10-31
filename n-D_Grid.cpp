#include <iostream>
using namespace std;

template<typename T>
T default_value();

template<>
float default_value() {
	return 0.f;
}

template<typename T, unsigned N >
class Grid final {
public:
	using value_type = T;
	using size_type = unsigned;
	size_type size;
	T* data;
	Grid<T, N - 1> subgrid;
	using type = size_type;

	//finding full grid size to allocate memory correctly
	size_type full_size() {
		size_type full_size = 1;
		full_size = subgrid.full_size() * size;
		return full_size;
	}

	//making empty data of N grid and filling with values of N-1 grid
	void make_data() {
		data = new T[full_size()];
		if (data != nullptr) {
			data=
		}
		else {
			cout << "Error";
		}
	}

	//basic constructor
	Grid() :size(1) {
		make_data();
		data[0] = default_value<float>();
	}

	//default variadic constructor
	template<typename... Args>
	Grid(size_type size, Args... subgrid) : size(size), subgrid(subgrid...) {
		make_data();
		if (data != nullptr) {
			for (size_type i = 0; i < full_size(); i++) {
				data[i] = Grid().data[0];
			}
		}
	}

	//variadic constructor with only one value. Do not working (why...??)
	template<typename... Args>
	Grid(size_type size, Args... subgrid, T const &t) : size(size), subgrid(subgrid...) {
		make_data();
		if (data != nullptr) {
			for (size_type i = 0; i < full_size(); i++) {
				data[i] = t;
			}
		}
	}
	
	//destructor
	~Grid() {
		delete[] data;
	}

	//copy-constructor
	Grid(Grid<T, N> const& src) : Grid(src.size, src.subgrid, src.data[0]) {
		if (src.data != nullptr) {
			for (size_type i = 0; i < full_size(); i++) {
				data[i] = src.data[i];
			}
		}
	}

	//move-constructor banned
	Grid(Grid<T, N>&& src) = delete;

	//copy-assign with copy-and-swap idiom
	Grid& operator=(Grid<T, N> const& src) {
		if (src.data != nullptr) {
			Grid<T, N> tmp(src);
			swap(this->size, tmp.size);
			swap(this->subgrid, tmp.subgrid);
			swap(this->data, tmp.data);
			return *this;
		}
	}

	//move-assign banned
	Grid<T,N>& operator=(Grid<T,N>&& src) = delete;

	//access operator, returns N-1 grid
	Grid<T, N - 1>& operator[](size_type idx) const {
		return data[idx];
	}

	//getting value
	template<typename... Args>
	T operator ()(size_type idx, Args ... subgrid) const {
		return data[idx](subgrid ...);
	}


	//printing grid in a line
	void print() {
		for (size_type i = 0; i < full_size(); i++) {
			cout << data[i] << " ";
		}
	}

};

template<typename T>
class Grid<T, 1> {
public:
	using value_type = T;
	using size_type = unsigned;
	size_type size;
	T* data;
	using type = size_type;

	//finding full grid size to allocate memory correctly
	size_type full_size() {
		return size;
	}

	//making empty data of N grid and filling with values of N-1 grid
	void make_data() {
		data = new T[full_size()];
	}

	//basic constructor
	Grid() :size(1) {
		make_data();
		data[0] = default_value<float>();
	}

	//default variadic constructor
	Grid(size_type size) : size(size) {
		make_data();
		if (data != nullptr) {
			for (size_type i = 0; i < full_size(); i++) {
				data[i] = Grid().data[0];
			}
		}
	}

	//variadic constructor with only one value
	Grid(size_type size, T const& t) : size(size) {
		make_data();
		if (data != nullptr) {
			for (size_type i = 0; i < full_size(); i++) {
				data[i] = t;
			}
		}
	}

	//destructor
	~Grid() {
		delete[] data;
	}

	//copy-constructor
	Grid(Grid<T, 1> const& src) : Grid(src.size, src.data[0]) {
		if (src.data != nullptr) {
			for (size_type i = 0; i < full_size(); i++) {
				data[i] = src.data[i];
			}
		}
	}

	//move-constructor banned
	Grid(Grid<T, 1>&& src) = delete;

	//copy-assign with copy-and-swap idiom
	Grid& operator=(Grid<T, 1> const& src) {
		if (src.data != nullptr) {
			Grid<T, 1> tmp(src);
			swap(this->size, tmp.size);
			swap(this->data, tmp.data);
			return *this;
		}
	}

	//move-assign banned
	Grid<T, 1>& operator=(Grid<T, 1>&& src) = delete;


	//access operator
	T* operator[](size_type idx) {
		return data + idx;
	}

	//getting value
	T operator()(size_type idx) const {
		return(data[idx])
	}

	//getting ref of value
	T& operator ()(size_type idx) {
		return data[idx];
	}

};
int main()
{
	Grid<float, 3> g1(4, 2, 3);
	g1.print();
}