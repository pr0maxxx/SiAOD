// ������� 1,2
//���� ���������� �������.����������, ����������� �� ��� ������������ ������� ���������.
// ������� 3
//���� ��� ��������� ����� �� ���������. ����� ������ � ����� ����������, ���������� ����� n (n>=3) ����� 
//������� ��������� � ���������� ������ ������ ���� ������ ����� ����� ������� � ������� ���������.

#include <iostream>
#include <ctime>
using namespace std;

void input(int** arr, int n)
{
    int mode;
    cout << "��� ��������� ������: � ���������� - 1 ��� ��������� ������� - 2?" << endl;
    cin >> mode;
    switch (mode)
    {
    case 1:
        cout << "������� �������� �������: " << endl;
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
    cout << "����������� ������:" << endl;
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
    cout << "������� ������ ���������� ������� n: ";
    int n;
    cin >> n;
    int** array = new int* [n];
    for (int i = 0; i < n; i++) 
    {
        array[i] = new int[n];
    }
    input(array,n);
    output(array,n);
    if (check_symmetry(array,n)) cout << "������� �����������";
    else cout << "������� �� �����������";
}
