#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void map_creation(int n, int width, int hight, int coord_x[], int coord_y[], char map[], bool m_death[]);
int iteration_of_moving(int n, int death, int width, int hight, int coord_x[], int coord_y[], char map[], bool m_death[]);
bool neighborhood(int n, int x1, int x2, int y1, int y2);
bool border(int n, int x, int y, int hight, int width);
int death_counter(int n, bool m_death[]);

int main()
{
    srand(time(NULL));
    int width, hight, n,death;
    cin >> width;
    cin >> hight;
    cout << '\n';
    death = 0;
    n = rand() % (width * hight); //Остаток от деления, чтобы n было меньше width * hight
    int* coord_x = new int[n];
    int* coord_y = new int[n]; //Координаты точек по x и по y;
    char* map = new char[width * hight]; // Отображение на экране;
    bool* m_death = new bool[n]; //Если клетка живая, то элемент массива - true; иначе false.

    map_creation(n, width, hight,coord_x,coord_y,map,m_death);
    cout << iteration_of_moving(n,death, width, hight,coord_x,coord_y,map,m_death);
}

void map_creation(int n, int width, int hight, int coord_x[], int coord_y[], char map[],bool m_death[]) {


    for (int i = 0; i < width * hight; i++)
        map[i] = '*'; // Заполняю поле звёздочками - пустыми местами (ни живыми, ни мёртвыми клетками)
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        do {
            coord_x[i] = rand() % width;
            coord_y[i] = rand() % hight;
        } while (map[coord_y[i] * width + coord_x[i]] == '@');
        map[coord_y[i] * width + coord_x[i]] = '@';
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

int iteration_of_moving(int n, int death, int width, int hight,int coord_x[],int coord_y[],char map[],bool m_death[]) {
    int count = 0;
    while (death < n) {
        death = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (neighborhood(n, coord_x[i], coord_x[j], coord_y[i], coord_y[j])==true) {
                    map[coord_y[i] * width + coord_x[i]] = 'X';
                    map[coord_y[j] * width + coord_x[j]] = 'X'; //означает, что клетка умерла.
                    m_death[i] = m_death[j] = true;
                }
        for (int i = 0; i < n; i++) {
            if (border(n, coord_x[i], coord_y[i], hight, width) == true) {
                m_death[i] = true;
                map[coord_y[i] * width + coord_x[i]] = 'X';
            }
        }

        death = death_counter(n,m_death);

        for (int i = 0; i < n; i++) {
            if (m_death[i] == false) {
                int vect = rand() % 4;
                if (vect == 0) {
                    map[coord_y[i] * width + coord_x[i]] = '*';
                    coord_y[i] -= 1;
                    if (map[coord_y[i] * width + coord_x[i]] == '@')
                        coord_y[i] += 1;
                    map[coord_y[i] * width + coord_x[i]] = '@';
                }
                if (vect == 1) {
                    map[coord_y[i] * width + coord_x[i]] = '*';
                    coord_x[i] += 1;
                    if (map[coord_y[i] * width + coord_x[i]] == '@')
                        coord_x[i] -= 1;;
                    map[coord_y[i] * width + coord_x[i]] = '@';
                }
                if (vect == 2) {
                    map[coord_y[i] * width + coord_x[i]] = '*';
                    coord_y[i] += 1;
                    if (map[coord_y[i] * width + coord_x[i]] == '@')
                        coord_y[i] -= 1;
                    map[coord_y[i] * width + coord_x[i]] = '@';
                }
                if (vect == 3) {
                    map[coord_y[i] * width + coord_x[i]] = '*';
                    coord_x[i] -= 1;
                    if (map[coord_y[i] * width + coord_x[i]] == '@')
                        coord_x[i] += 1;
                    map[coord_y[i] * width + coord_x[i]] = '@';
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
}

bool border(int n, int x, int y, int hight, int width) { //Если живая клетка добралась до границы
    if (x * y == 0 || x == width - 1 || y == hight - 1) {
        return true;
    }
}
int death_counter(int n, bool m_death[]) { // Считаем количество умерших клеток
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (m_death[i]==true) {
            c++;
        }
    return c;
}

