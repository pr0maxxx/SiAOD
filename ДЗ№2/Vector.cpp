// Задание 1,2
//Дана квадратная матрица.Определить, симметрична ли она относительно главной диагонали.
// Задание 3
//Даны два множества точек на плоскости. Найти радиус и центр окружности, проходящей через n (n>=3) точек 
//первого множества и содержащей строго внутри себя разное число точек первого и второго множества.
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int mass1[6] = {};
int mass2[6] = {};
int mass3[6] = {};
int mass4[6] = {};
double koord[8] = {};
double radius[4] = {};

void create_vect(vector <vector <int>>& v,int n)
{
	int mode;
	cout << "Как определить координаты: с клавиатуры (1) или случайным образом (2)?" << endl;
	cin >> mode;
	switch (mode)
	{
	case 1:
		cout << "Введите координаты точек в виде: x1 y1 x2 y2..." << endl;
		for (int i = 0; i < n; i++) // Цикл, который идёт по строкам
			for (int j = 0; j < 2; j++) // Цикл, который идёт по элементам
			{
				cin >> v[i][j]; // Заполнение вектора или массива (в данном случае ввод)
			}
		break;
	case 2:
		for (int i = 0; i < n; i++) // Цикл, который идёт по строкам
			for (int j = 0; j < 2; j++) // Цикл, который идёт по элементам
			{
				v[i][j] = rand() % 41 - 20; // Заполнение вектора или массива (в данном случае ввод)
			}
		break;
	}
}

void print_vect(vector <vector <int>>& v, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
			cout << v[i][j] << " ";
		cout << '\n';
	}

}

bool on_one_line(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (x3 * (y2 - y1) - y3 * (x2 - x1) != x1 * y2 - x2 * y1);
}

void ALLIsPointsOnLine(vector<vector<int>>& v) {

	if (on_one_line(v[1][0], v[1][1], v[2][0], v[2][1], v[3][0], v[3][1]))
	{
		mass1[0] = v[1][0];
		mass1[1] = v[1][1];
		mass1[2] = v[2][0];
		mass1[3] = v[2][1];
		mass1[4] = v[3][0];
		mass1[5] = v[3][1];
	}
	if (on_one_line(v[0][0], v[0][1], v[2][0], v[2][1], v[3][0], v[3][1])) 
	{
		mass2[0] = v[0][0];
		mass2[1] = v[0][1];
		mass2[2] = v[2][0];
		mass2[3] = v[2][1];
		mass2[4] = v[3][0];
		mass2[5] = v[3][1];
	}
	if (on_one_line(v[0][0], v[0][1], v[1][0], v[1][1], v[3][0], v[3][1])) 
	{
		mass3[0] = v[0][0];
		mass3[1] = v[0][1];
		mass3[2] = v[1][0];
		mass3[3] = v[1][1];
		mass3[4] = v[3][0];
		mass3[5] = v[3][1];
	}
	if (on_one_line(v[0][0], v[0][1], v[1][0], v[1][1], v[2][0], v[2][1])) 
	{
		mass4[0] = v[0][0];
		mass4[1] = v[0][1];
		mass4[2] = v[1][0];
		mass4[3] = v[1][1];
		mass4[4] = v[2][0];
		mass4[5] = v[2][1];
	}
}

bool no_null(int* a) 
{
	int cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		if (a[i] == 0) cnt += 1;
	}

	if (cnt == 6) return false;
	else return true;
}

void search_center(int* a, int cnt) 
{
	double x0, y0;
	if (no_null(a)) 
	{
		x0 = -0.5*(a[1] * (pow(a[2], 2) + pow(a[3], 2) - pow(a[4], 2) - pow(a[5], 2)) + a[3] * (pow(a[4], 2) + pow(a[5], 2) - pow(a[0], 2) - pow(a[1], 2)) + a[5]*(pow(a[0], 2) + pow(a[1], 2) - pow(a[2], 2) - pow(a[3], 2)))
			/(a[0] *(a[3] - a[5]) + a[2] * (a[5] - a[1]) + a[4] * (a[1] - a[3]));
		y0 = 0.5 *(a[0] * (pow(a[2], 2) + pow(a[3], 2) - pow(a[4], 2) - pow(a[5], 2)) + a[2] * (pow(a[4], 2) + pow(a[5], 2) - pow(a[0], 2) - pow(a[1], 2)) + a[4] * (pow(a[0], 2) + pow(a[1], 2) - pow(a[2], 2) - pow(a[3], 2)))
			/(a[0] * (a[3] - a[5]) + a[2] * (a[5] - a[1]) + a[4] * (a[1] - a[3]));
		koord[cnt] = x0;
		koord[cnt + 1] = y0;
	}
}

void search_radius(int* a, double* k, int cnt, int i) 
{
	double r;
	r = sqrt(pow(a[0] - k[cnt], 2) + pow(a[1] - k[cnt+1],2));
	radius[i] = r;
}
int in_circle(vector<vector<int>>& v,int n, double* k, int cnt, double* r, int j)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (sqrt(pow(v[i][0] - k[cnt], 2) + pow(v[i][1] - k[cnt + 1], 2)) < r[j])
			count++;	
	}
	return count;
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n1, n2;
	cout << "Введите количество точек в первом множестве: ";
	cin >> n1;
	cout << "Введите количество точек во втором множестве: ";
	cin >> n2;
	vector <vector <int>> points1(n1, vector <int>(2));
	vector <vector <int>> points2(n2, vector <int>(2));
	cout << "Заполните первое множество:" << endl;
	create_vect(points1, n1);
	cout << "Заполните второе множество:" << endl;
	create_vect(points2, n2);
	cout << "Значения вектора 1: \n";
	print_vect(points1, n1);
	cout << "Значения вектора 2: \n";
	print_vect(points2, n2);
	ALLIsPointsOnLine(points1);
	search_center(mass1,0);
	search_center(mass2, 2);
	search_center(mass3, 4);
	search_center(mass4, 6);
	search_radius(mass1, koord, 0, 0);
	search_radius(mass2, koord, 2, 1);
	search_radius(mass3, koord, 4, 2);
	search_radius(mass4, koord, 6, 3);
	int kolvo_points1_in_circle[4] = {};
	kolvo_points1_in_circle[0] = in_circle(points1, n1, koord, 0, radius, 0);
	kolvo_points1_in_circle[1] = in_circle(points1, n1, koord, 2, radius, 1);
	kolvo_points1_in_circle[2] = in_circle(points1, n1, koord, 4, radius, 2);
	kolvo_points1_in_circle[3] = in_circle(points1, n1, koord, 6, radius, 3);
	int kolvo_points2_in_circle[4] = {};
	kolvo_points2_in_circle[0] = in_circle(points2, n2, koord, 0, radius, 0);
	kolvo_points2_in_circle[1] = in_circle(points2, n1, koord, 2, radius, 1);
	kolvo_points2_in_circle[2] = in_circle(points2, n1, koord, 4, radius, 2);
	kolvo_points2_in_circle[3] = in_circle(points2, n1, koord, 6, radius, 3);
	int cnt = 0;
	bool s = 0;
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		if (kolvo_points1_in_circle[i] != 0 & kolvo_points2_in_circle[i] != 0 & kolvo_points1_in_circle[i] != kolvo_points2_in_circle[i])
		{
			cout << "Найдена подходящая окружность: радиус - " << radius[i] << ", координаты центра (в формате x0 y0) - "
				 << koord[cnt] << " " << koord[cnt + 1] << endl;
			s++;
		}
	}
	if (s == 0) cout << "Нет подходящей окружности" << endl;
}