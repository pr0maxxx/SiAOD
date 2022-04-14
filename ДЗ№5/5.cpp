/*
Дан линейный однонаправленный список L(double)
1)	Разработать функцию, которая вставляет перед последним узлом два новых узла.
2)	Удаляет из списка L первое отрицательное значение, если оно присутствует в списке.
3)	Найти в списке L максимальное значение и перенести его узел в конец списка.
*/

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

struct Node {
    Node* pNext; 
    double data;

    Node(double s, Node* ptr = nullptr) : data(s), pNext(nullptr) {}
};
struct List {
    Node* first; 
    int size = 0;
};

void add_elem(List& list, double s) //Добавляет в список новый элемент
{
    Node* p = new Node(s);
    if (list.size == 0)
        list.first = p;
    else
    {
        Node* current = list.first;
        while (current->pNext != nullptr)
            current = current->pNext;
        current->pNext = p;
    }
    list.size++;
}
void print_list(List list)
{
    Node* current = list.first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->pNext;
    }
    cout << endl;
}

void insert(List& list) {    //Вставляет элементы перед последним узлом
    double x;
    cout << "----- Функция вставки двух новых узлов перед последним -----\n";
    for (int cnt = 0; cnt < 2; cnt++) {
        Node* current = list.first;
        int i = 0;
        while (current != nullptr) {
            if ((i >= list.size - 2) && (current->pNext != nullptr)) {
                cout << "Введите значение которое вы хотите вставить:\n";
                cin >> x;
                Node* new_elem = new Node(x);
                new_elem->pNext = current->pNext;
                current->pNext = new_elem;
                current = new_elem->pNext;
                list.size++;
            }
            else
                current = current->pNext;
            i++;
        }
    }
    cout << "Cписок после добаления элементов: \n";
    print_list(list);
}

void dell(List& list) {          //Удаляет первое отрицательное число
    Node* current = list.first;
    bool is_negative = false;
    cout << "----- Функция удаления первого отрицательного значения, если оно присутствует в списке -----\n";
    while (current != nullptr) {
        if (current->data < 0) is_negative = true;
        current = current->pNext;
    }
    current = list.first;

    if (is_negative) {
        if (current->data < 0) list.first = current->pNext;
        else {
            while (current != nullptr) {
                if (current->pNext->data < 0) {
                    if (current->pNext->pNext == nullptr) current->pNext = nullptr;
                    else {
                        current->pNext = current->pNext->pNext;
                        list.size--;
                    }
                    break;
                }
                else current = current->pNext;
            }
        }
    }
    cout << "Список после удаления: \n";
    print_list(list);
}

void find(List& list) {          //Ищет максимальное число и переносит в конец списка
    Node* current = list.first;
    double max = 0;
    cout << "----- Функция поиска максимального значения и перенос его в конец списка -----\n";


    while (current != nullptr) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->pNext;

    }
    current = list.first;
    cout << "Максимальное число: " << max << endl;
    if (current -> data == max) {
        list.first = current->pNext;
    }
    else {
        while (current != nullptr) {
            if (current -> pNext -> data == max) {
                if (current->pNext->pNext == nullptr) {
                    current->pNext = nullptr;
                }
                else
                {
                    current->pNext = current->pNext->pNext;
                    list.size--;
                }
                break;
            }
            else {
                current = current->pNext;
            }

        }
    }
    add_elem(list, max);
    print_list(list);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    List L;
    cout << "Введите количество элементов\n";
    int mode;
    double x;
    cin >> size;
    cout << "Выберите способ заполнения списка:\n1 - самостоятельный ввод элементов\n2 - заполнение рандомными числами\n";
    cin >> mode;

    if (mode == 1) {

        cout << "Введите элементы\n";
        for (int i = 0; i < size; i++) {
            cin >> x;
            add_elem(L, x);
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            x = (rand() % 101 - 50 ) / 10.0;
            add_elem(L, x);
        }
    }
    print_list(L);
    insert(L);
    dell(L);
    find(L);
}
