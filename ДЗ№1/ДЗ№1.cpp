/*
1.	Найти индекс элемента массива цифры которого упорядочены по возрастанию. Считать, что такое число одно.
2.	Вставить новый элемент после элемента, цифры которого упорядочены по возрастанию.
3.	Удалить число, которое расположено перед числом, цифры которого упорядочены по возрастанию.
*/
#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream> 
using namespace std;

void create_mass(int* a) //Функция создания случайного статического или динамического массива
{
	int i;
	srand(time(0)); // инициализация генерации случайных чисел
	for (i = 0; i < 10; i++)
		a[i] = -1000 + rand() % 2000;
}

void show_mass(int* arr) { //Функция вывода статического или динамического массива
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void create_vect(vector<int>& v) //Функция создания случайного вектора
{
	srand(time(0)); 
	for (int i = 0; i < 10; i++)
		v[i] = (-1000 + rand() % 2000);
}

void show_vect(vector<int>& v) //Функция вывода вектора
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

bool check(int element) { //Функция проверки элемента на порядок цифр по возрастанию
	int x;
	element = abs(element);
	if (element < 10) return false;
	x = element % 10;
	element /= 10;
	bool yes = true;
	while (element > 0)
	{
		if (element % 10 < x)
		{
			x = element % 10;
			element /= 10;
			continue;
		}
		yes = false;
		break;
	}
	return yes;
}

int index(int* arr, int n) //Функция нахождения индекса элемента массива,
						  //цифры которого упорядочены по возрастанию (для статического или динамического массива)
{
	bool flag = false;
	int index;
	int i = 0;
	while (!flag && i <= n) {
		if (check(arr[i]) == true) {
			index = i;
			flag = true;
			break;
		}
		i++;
	}
	if (flag == true)
	{
		return index;
	}
	else
	{
		return -5;
	}
}

void insert_and_delete_in_mass(int* mass, vector<int>& v,int s) // Функция вставки и удаления элемента для статического и динамического массивов
{
	for (int i = 0; i < 10; ++i)
		v.push_back(mass[i]); //Все элементы из неизменённого массива в вспомогательный вектор
	int x = 1 + rand() % 1000;
	v.insert(v.begin() + s + 1, x);
	cout << "Случайное число, которое будет вставлено в массив: " << x << endl;
	cout << "Массив после добавления элемента: " << endl;
	show_vect(v);
	v.erase(v.begin() + s - 1);
	cout << "Итоговый массив: " << endl;
	show_vect(v);
}

int index(vector <int>& a, int n) //Функция нахождения индекса элемента вектора, цифры которого упорядочены по возрастанию
{
	bool flag = false;
	int index;
	int i = 0;
	while (!flag && i <= n) {
		if (check(a[i]) == true) {
			index = i;
			flag = true;
			break;
		}
		i++;
	}
	if (flag == true)
	{
		return index;
	}
	else
	{
		return -5;
	}
}

void insert_and_delete_in_mass(vector<int>& v, int s) // Функция вставки и удаления элемента для векторов
{
	int x = 1 + rand() % 1000;
	v.insert(v.begin() + s + 1, x);
	cout << "Случайное число, которое будет вставлено в массив: " << x << endl;
	cout << "Массив после добавления элемента: " << endl;
	show_vect(v);
	v.erase(v.begin() + s - 1);
	cout << "Итоговый массив: " << endl;
	show_vect(v);
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Практическая работа №1 Вайдов Максим " << endl;
	cout << "Выберите массив:" << endl << "1 - статический" << endl << "2 - динамический" << endl << "3 - вектор" << endl;
	int mode, size;
	do
	{
		cin >> mode;
		if (mode < 1 || mode > 3) cout << "Такого режима нет. Введите число от 1 до 3: ";
	} while (mode < 1 || mode > 3);

	switch (mode)
	{
	case 1:
	{//Статический массив
		int s;
		int arr[10];
		vector<int> help_vect; //Пустой вектор для добавления в массив
		create_mass(arr); //Создали и заполнили целочисленный массив размера 10
		show_mass(arr); //Вывели сгенерированный массив
		s = index(arr, 10);
		if (s >= 0)
		{
			insert_and_delete_in_mass(arr, help_vect, s);  //Добавление и удаление элементов, вывод полученного массива
		}
		else cout << "В массиве нет элемента, цифры которого упорядочены по возрастанию!" << endl;
		cout << endl << "Программа завершила свою работу успешно. " << endl;
		break;
	}
	case 2:
	{ //Динамический массив
		int s;
		int* din_arr = new int[10];
		vector<int> help_vect; //Пустой вектор для добавления в массив
		create_mass(din_arr); //Создали и заполнили динамический массив размера 10
		show_mass(din_arr); //Вывели сгенерированный массив
		s = index(din_arr, 10);
		if (s >= 0)
		{
			insert_and_delete_in_mass(din_arr, help_vect, s); //Добавление и удаление элементов, вывод полученного массива
		}
		else cout << "В массиве нет элемента, цифры которого упорядочены по возрастанию!" << endl;
		cout << endl << "Программа завершила свою работу успешно. " << endl;
		break;
	}
	case 3:
	{//вектор
		int s;
		vector<int> a(10); //Инициализируем вектор
		cout << "Изначальный сформированный рандомно массив: " << endl;
		create_vect(a); //Создали и заполнили вектор размера 10
		show_vect(a); //Вывели сгенерированный вектор
		s = index(a,10);
		if (s >= 0)
		{
			insert_and_delete_in_mass(a, s); //Добавление и удаление соответствующих элементов, вывод полученного массива
		}
		else cout << "В массиве нет элемента, цифры которого упорядочены по возрастанию!" << endl;
		cout << endl << "Программа завершила свою работу успешно. " << endl;
		break;
	}
	}
}