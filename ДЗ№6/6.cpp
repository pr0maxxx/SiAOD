/*
1.	Сколько квадратов можно отрезать от прямоугольника со сторонами a и в.
2.	Удаление стека, реализованного на однонаправленном списке.
*/
#include <iostream>
using namespace std;

int count(int a, int b, int n = 0) {
    if (a == b)
        return n + 1;

    if (a < b)
        return count(a, b - a, n + 1);

    return count(a - b, b, n + 1);
}

struct Node {
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(string _val) {
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
        remove_last();
    }
};
int main()
{
    setlocale(LC_ALL,"Ru");
    list l;
    int a, b;
    cout << "Введите стороны прямоугольника: ";
    cin >> a >> b;
    cout << "Количество квадратов: " << count(a, b) << endl;
    l.push_back("3");
    l.push_back("123");
    l.push_back("8");
    l.push_back("1234");
    cout << "Список до удаления" << endl << "L: ";
    l.print();
    l.remove_last();
    cout << "Список после удаления" << endl << "L: ";
    l.print();
    return 0;
}
