#include <iostream>
#include <cstdlib>

#include <ctime>
using namespace std;

const int max_lenght = 100;
int coord_x[max_lenght * max_lenght];
int coord_y[max_lenght * max_lenght];
int map[max_lenght * max_lenght];
bool m_death[max_lenght * max_lenght];

void map_creation(int n, int width, int hight, int coord_x[], int coord_y[], int map[], bool m_death[]);
int iteration_of_moving(int n, int death, int width, int hight, int coord_x[], int coord_y[], int map[], bool m_death[]);
bool neighborhood(int n, int x1, int x2, int y1, int y2);
bool border(int n, int x, int y, int hight, int width);
int death_counter(int n, bool m_death[]);


int main() {

    srand(static_cast<unsigned int>(time(0)));
    int width, hight, n, death;
    cin >> width;
    cin >> hight;
    if (width < max_lenght && hight < max_lenght) {
        cout << '\n';
        death = 0;
        n = rand() % (width * hight); //Остаток от деления, чтобы n было меньше width * hight
        map_creation(n, width, hight, coord_x, coord_y, map, m_death);
        cout << iteration_of_moving(n, death, width, hight, coord_x, coord_y, map, m_death);
    }
}

void map_creation(int n, int width, int hight, int coord_x[], int coord_y[], int map[], bool m_death[]) {

    for (int i = 0; i < width * hight; i++)
        map[i] = 0; // Заполняю поле нулями - пустыми местами (ни живыми, ни мёртвыми клетками)
    for (int i = 0; i < n; i++) {
        do {
            coord_x[i] = rand() % width;
            coord_y[i] = rand() % hight;
        } while (map[coord_y[i] * width + coord_x[i]] == 1);
        map[coord_y[i] * width + coord_x[i]] = 1;
        m_death[i] = false; // Живые клетки - не мёртвые клетки.
    }
    for (int i = 0; i < width * hight; i++) { //Интеллектуально выводим массив на экран.
        if ((i + 1) % width != 0)
            cout << map[i] << " ";
        else
            cout << map[i] << '\n';
    }
    cout << " " << '\n';
}

int iteration_of_moving(int n, int death, int width, int hight, int coord_x[], int coord_y[], int map[], bool m_death[]) {
    int count = 0;
    while (death < n) {
        death = 0;
        /* for (int i = 0; i < n; i++)
             for (int j = 0; j < n; j++)
                 if (neighborhood(n, coord_x[i], coord_x[j], coord_y[i], coord_y[j]) == true) {
                     map[coord_y[i] * width + coord_x[i]] = -1;
                     map[coord_y[j] * width + coord_x[j]] = -1; //означает, что клетка умерла.
                     m_death[i] = m_death[j] = true;
                 }
         */
        for (int i = 0; i < n; i++) {
            if (border(n, coord_x[i], coord_y[i], hight, width) == true) {
                m_death[i] = true;
                map[coord_y[i] * width + coord_x[i]] = -1;
            }
        }

        death = death_counter(n, m_death);

        for (int i = 0; i < n; i++) {
            if (m_death[i] == false) {
                if (hight != 1) {
                    int vect = rand() % 4;
                    if (vect == 0) {
                        map[coord_y[i] * width + coord_x[i]] -= 1;
                        coord_y[i] -= 1;
                        map[coord_y[i] * width + coord_x[i]] += 1;
                        /* if (map[coord_y[i] * width + coord_x[i]] == '@')
                             coord_y[i] += 1;
                         map[coord_y[i] * width + coord_x[i]] = '@';
                         */
                    }
                    if (vect == 1) {
                        map[coord_y[i] * width + coord_x[i]] -= 1;
                        coord_x[i] += 1;
                        map[coord_y[i] * width + coord_x[i]] += 1;
                        /*if (map[coord_y[i] * width + coord_x[i]] == '@')
                            coord_x[i] -= 1;;
                        map[coord_y[i] * width + coord_x[i]] = '@';
                        */
                    }
                    if (vect == 2) {
                        map[coord_y[i] * width + coord_x[i]] -= 1;
                        coord_y[i] += 1;
                        map[coord_y[i] * width + coord_x[i]] += 1;
                        /* if (map[coord_y[i] * width + coord_x[i]] == '@')
                             coord_y[i] -= 1;
                         map[coord_y[i] * width + coord_x[i]] = '@';
                         */
                    }
                    if (vect == 3) {
                        map[coord_y[i] * width + coord_x[i]] -= 1;
                        coord_x[i] -= 1;
                        map[coord_y[i] * width + coord_x[i]] += 1;
                        /* if (map[coord_y[i] * width + coord_x[i]] == '@')
                             coord_x[i] += 1;
                         map[coord_y[i] * width + coord_x[i]] = '@';
                         */
                    }
                }
                else {
                    int vect = rand() % 2;
                    if (vect == 0) {
                        map[coord_y[i] * width + coord_x[i]] -= 1;
                        coord_x[i] -= 1;
                        map[coord_y[i] * width + coord_x[i]] += 1;
                        /* if (map[coord_y[i] * width + coord_x[i]] == '@')
                             coord_x[i] += 1;
                         map[coord_y[i] * width + coord_x[i]] = '@';
                         */
                    }
                    if (vect == 1) {
                        map[coord_y[i] * width + coord_x[i]] -= 1;
                        coord_x[i] += 1;
                        map[coord_y[i] * width + coord_x[i]] += 1;
                        /*if (map[coord_y[i] * width + coord_x[i]] == '@')
                            coord_x[i] -= 1;;
                        map[coord_y[i] * width + coord_x[i]] = '@';\
                        */
                    }
                }
            }
        }
        for (int i = 0; i < width * hight; i++) {
            if ((i + 1) % width != 0)
                cout << map[i] << " ";
            else
                cout << map[i] << '\n';
        }
        count += 1;
        cout << '\n';
    }
    return count;
}

bool neighborhood(int n, int x1, int x2, int y1, int y2) { //если две живые клекти находятся по-соседству
    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == 1) {
        return true;
    }
    return false;
}

bool border(int n, int x, int y, int hight, int width) { //Если живая клетка добралась до границы
    if (hight != 1) {
        if (x * y == 0 || x == width - 1 || y == hight - 1) {
            return true;
        }
    }
    else {
        if (x == 0 || x == width - 1) {
            return true;
        }
    }
    return false;
}
int death_counter(int n, bool m_death[]) { // Считаем количество умерших клеток
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (m_death[i] == true) {
            c++;
        }
    return c;
}

