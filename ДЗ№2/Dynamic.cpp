// Задание 1,2
//Дана квадратная матрица.Определить, симметрична ли она относительно главной диагонали.
// Задание 3
//Даны два множества точек на плоскости. Найти радиус и центр окружности, проходящей через n (n>=3) точек 
//первого множества и содержащей строго внутри себя разное число точек первого и второго множества.

#include <iostream>
#include <ctime>
using namespace std;

void input(int** arr, int n)
{
    int mode;
    cout << "Как заполнить массив: с клавиатуры - 1 или случайным образом - 2?" << endl;
    cin >> mode;
    switch (mode)
    {
    case 1:
        cout << "Введите элементы массива: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                arr[i][j] = rand() % 100;
        }
        break;
    }
}

void output(int** arr, int n)
{
    cout << "Изначальный массив:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
bool check_symmetry(int** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[j][i])
                return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    cout << "Введите размер квадратной матрицы n: ";
    int n;
    cin >> n;
    int** array = new int* [n];
    for (int i = 0; i < n; i++) 
    {
        array[i] = new int[n];
    }
    input(array,n);
    output(array,n);
    if (check_symmetry(array,n)) cout << "Матрица симметрична";
    else cout << "Матрица не симметрична";
}
