#include <iostream>
#include <Windows.h>
#include <string>
#include<algorithm>
using namespace std;
string a = "йцукенгшщзхъфывапролджэячсмитьбю";
const char* ar[] = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с",
        "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я" };
struct Product
{
public:
    string title;
    int code;
    string namePr = "";
    string unit;
    int price;

};
void heapify(Product* arr, int n, int i)
{
    int most = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if (left < n && arr[left].code > arr[most].code)
        most = left;


    if (right < n && arr[right].code > arr[most].code)
        most = right;


    if (most != i)
    {
        swap(arr[i], arr[most]);


        heapify(arr, n, most);
    }
}
void heapSort(Product* arr, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}



void fillProduct(Product* arr, int size) {

    for (int i = 0; i < size; i++) {
        arr[i].code = i + 100001;
        for (int i1 = 0; i1 < 8; i1++)
            arr[i].title += ar[rand() % (sizeof ar / sizeof(char*))];
        for (int i1 = 0; i1 < 3; i1++)
            arr[i].namePr += ar[rand() % (sizeof ar / sizeof(char*))];
        for (int i1 = 0; i1 < 2; i1++)
            arr[i].unit += ar[rand() % (sizeof ar / sizeof(char*))];
        arr[i].price = rand() % 100 + 1;
        cout << arr[i].title << "   " << arr[i].code << "   " << arr[i].namePr << "   " << arr[i].unit << "   " << arr[i].price << endl;

    }
}
void Search(Product* arr, int size, int query) {
    bool flag = true;
    for (int i = 0; i < size; i++)
        if (arr[i].code == query) 
        {
            cout << "Найденный товар" << endl;
            cout << arr[i].title << "   " << arr[i].code << "   " << arr[i].namePr << "   " << arr[i].unit << "   " << arr[i].price << endl;
            flag = false;
            break;
        }
    if (flag)
        cout << "Код не найден" << endl;
}
void barrierSearch(Product* arr, int size, int query) {
    Product last = arr[size - 1];
    arr[size - 1].code = query;
    int i = 0;
    for (i; arr[i].code != query; i++);
    if (i != size - 1 or last.code == query)
        cout << "Найденный товар" << endl << arr[i].title << "   " << arr[i].code << "   " << arr[i].namePr << "   " << arr[i].unit << "   " << arr[i].price << endl;
    else
        cout << "Код не найден" << endl;


}
void binary_search(Product* arr, int size, int query)
{
    int left = 0;
    int right = size;
    int midd = 0;
    heapSort(arr, size);
    while (1)
    {
        midd = (left + right) / 2;

        if (query < arr[midd].code)       // если искомое меньше значения в ячейке
            right = midd - 1;      // смещаем правую границу поиска
        else if (query > arr[midd].code)  // если искомое больше значения в ячейке
            left = midd + 1;    // смещаем левую границу поиска
        else {                       // иначе (значения равны)
            cout << "Найденный товар" << endl << arr[midd].title << "   " << arr[midd].code << "   " << arr[midd].namePr << "   " << arr[midd].unit << "   " << arr[midd].price << endl;           // функция возвращает индекс ячейки
            break;
        }
        if (left > right) {       // если границы сомкнулись 
            cout << "Код не найден" << endl;
            break;
        }

    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Product* arr;
    int size;
    int query;
    cin >> size;
    // TO DO   binarySearch without tables
    arr = new Product[size];
    fillProduct(arr, size);
    cin >> query;
    cout << "Main" << endl;
    unsigned int start_time = clock();
    //Search(arr, size, query);
    //barrierSearch(arr, size, query);
    binary_search(arr, size, query);
    cout << "Time: " << clock() - start_time;
    delete[]arr;
}
