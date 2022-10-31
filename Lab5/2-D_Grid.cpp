#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
T default_value();

template<>
float default_value() {
    return 0.f;
}


template <typename T>
class Grid final {
private:
    using value_type = T;
    using size_type = unsigned;
    T* data;
    size_type y_size, x_size;
public:
    using type = size_type;

    //data-making method
    T* make_data() {
        data = new T[y_size * x_size];
        if (data != nullptr) {
            return data;
        }
        else {
            cout << "Error" << "\n";
        }

    }

    //defaul constructor
    Grid() : y_size(1), x_size(1) {
        make_data();
        data[0] = default_value<float>();
    }

    //advanced default constructor
    Grid(size_type y_size, size_type x_size) : y_size(y_size), x_size(x_size) {
        make_data();
        if (data != nullptr) {
            for (size_type i = 0; i < y_size * x_size; i++) {
                data[i] = Grid().data[0];
            }
        }       
    }

    //type conventer constructor
    Grid(T const& t) : y_size(1), x_size(1) {
        make_data();
        data[0] = t;
    }
    
    //constructor with only one value
    Grid(size_type y_size, size_type x_size, T const& t) : y_size(y_size), x_size(x_size) {
        make_data();
        if (data != nullptr) {
            for (size_type i = 0; i < y_size * x_size; i++) {
                data[i] = t;
            }
        }       
    }

    //destructor
    ~Grid() {
        delete[] data;
    }

    //copy-constructor
    Grid(Grid<T> const& src) : Grid(src.y_size, src.x_size, src.data[0]) {
        if (src.data != nullptr) {
            for (size_type i = 0; i < y_size; i++) {
                for (size_type j = 0; j < x_size; j++) {
                    data[i * y_size + j] = src.data[i * y_size + j];
                }
            }
        }
    }

    //move-constructor banned
    Grid(Grid<T>&& src) = delete;

    //copy-assign with copy-and-swap idiom
    Grid& operator=(Grid<T> const& src) {
        if (src.data != nullptr) {
            Grid<T> tmp(src);
            swap(this->x_size, tmp.x_size);
            swap(this->y_size, tmp.y_size);
            swap(this->data, tmp.data);
            return *this;
        }
    }
    //move-assign banned
    Grid<T>& operator=(Grid<T>&& src) = delete;

    T* operator[](size_type y_idx) {
        return data + y_idx * x_size;
    }


    T operator() (size_t y_idx, size_t x_idx) const {
        return data[y_idx * x_size + x_idx];
    }

    T& operator() (size_type y_idx, size_type x_idx) {
        return data[y_idx * x_size + x_idx];
    }

    Grid<T>& operator = (T const& t) {
        for (auto it = data, end = data + x_size * y_size; it != end; it++) *it = t;
        return *this;
    }


    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }

    void print() {
        for (int i = 0; i < y_size; i++) {
            for (int j = 0; j < x_size; j++) {
                cout << data[i * x_size + j] << " ";
            }
            cout << "\n";
        }
    }
};

template<typename T>
void Lector_check(Grid<T> &g) {
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());
    using gsize_t = Grid<int>::type;


    for (int y_idx = 0; y_idx != g.get_y_size(); ++y_idx) {
        for (int x_idx = 0; x_idx != g.get_x_size(); ++x_idx) {
            assert(0.0f == g[y_idx][x_idx]);
        }
    }

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx) {
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx) {
            g[y_idx][x_idx] = 1.0f;
        }
    }
    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx) {
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx) {
            assert(1.0f == g(y_idx, x_idx));
        }
    }
}

int main()
{
    Grid<float> g(3, 2, 0.0f);
    Lector_check(g);
}


