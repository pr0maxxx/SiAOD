// Задание 1,2
//Дана квадратная матрица.Определить, симметрична ли она относительно главной диагонали.
// Задание 3
//Даны два множества точек на плоскости. Найти радиус и центр окружности, проходящей через n (n>=3) точек 
//первого множества и содержащей строго внутри себя разное число точек первого и второго множества.

#include <iostream>
#include <ctime>
using namespace std;
#define Rows 10
#define Cols 10
int p;
void input(int x[][Cols])
{
    cout << "Введите размер квадратной матрицы n: ";
    int mode;
    cin >> p;
    cout << "Как заполнить массив: с клавиатуры - 1 или случайным образом - 2?" << endl;
    cin >> mode;
    switch (mode)
    {
    case 1:
        cout << "Введите элементы массива: " << endl;
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < p; j++)
                cin >> x[i][j];
        }
        break;
    case 2:
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < p; j++)
                x[i][j] = rand() % 100;
        }
        break;
    }
}

void output(int x[][Cols])
{
    cout << "Изначальный массив:" << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
}
bool check_symmetry(int x[][Cols]) 
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (x[i][j] != x[j][i])
                return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int x[Rows][Cols];
    input(x);
    output(x);
    if (check_symmetry(x)) cout << "Матрица симметрична";
    else cout << "Матрица не симметрична";
}
