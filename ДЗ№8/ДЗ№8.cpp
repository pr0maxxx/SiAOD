// Простой вставки ----- Шелла со смещением Р. Седжвика. ----- Быстрая сортировка (опорный элемент в середине)
//

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <ctime>
using namespace std;

void random_arr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = 1+ rand() % 100;
	}
}

void arr_out(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void selection_sort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			swap(arr[j - 1], arr[j]);
		}
	}
}

int sedgwicks_step(int inc[], int size) {
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}

void shell_sort(int* a, int size) {
	int inc,j, seq[40], size_seq;
	size_seq = sedgwicks_step(seq, size);
	while (size_seq >= 0) {
		inc = seq[size_seq--];
		for (int i = inc; i < size; i++) {
			int temp = a[i];
			for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
				a[j + inc] = a[j];
			a[j + inc] = temp;
		}
	}
}

void quick_sort(int* mas, int size) {
	
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];

	do {
		while (mas[i] < mid) 
			i++;
		
		while (mas[j] > mid) 
			j--;

		if (i <= j) {
			swap(mas[i],mas[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) quick_sort(mas, j + 1);
	if (i < size) quick_sort(&mas[i], size - i);
	
}

int main() 
{
	setlocale(LC_ALL, "Rus");
	int n;
	cin >> n;
	int* arr = new int[n];
	
	random_arr(arr, n);
	arr_out(arr, n);

	unsigned int start_time = clock();
	//selection_sort(arr, n);
	//shell_sort(arr, n);
	quick_sort(arr, n);
	arr_out(arr, n);

	cout << clock() - start_time;
}
