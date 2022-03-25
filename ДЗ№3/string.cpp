//Дано предложение, состоящее из слов, разделенных запятой или пробелами, 
//среди которых есть группы цифр, определяющих целые числа из диапазона int.
//Удалить из предложения те целые числа, в десятичной записи 
//которых есть цифры 5, 6, 7, а остальные числа увеличить на 2.

#include <iostream>
#include <Windows.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool it_digit(char s) // Проверяет, является ли подстрока числом
{
    if (!(int(s) <= int('9') && int(s) >= int('0')))
        return false;
    return true;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char str[100];
    int len = 0;
    char a[10][10]{};
    cout << "Введите предложение:" << endl;
    cin.getline(str, 100);
    int k = -1;
    char norm_num[10][10]{};

    for (int i = 0; i < 100; i++)
    {
        if (str[i] != '\0')
            len += 1;
        else
            break;
    }
    int cnt = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (it_digit(str[i]))
        {
            k += 1;
            int t = 1;
            int j = i;
            int len_number = 0;
            bool flag = true;
            while (str[j] != ' ' && str[j] != '\0')
            {
                if (str[j] == '5' || str[j] == '6' || str[j] == '7')
                {
                    flag = false;
                    a[k][t] = str[j];
                    str[j] = '%';
                }
                t += 1;
                j += 1;
                len_number++;
            }
            if (!flag)
            {
                for (int b = j - 1; b > j - len_number - 1; b--)
                {
                    str[b] = ' ';
                }
            }
            else
            {
                int c = 0;
                for (int b = j - len_number; b < j; b++)
                {
                    norm_num[cnt][c] = str[b];
                    str[b] = '*';
                    c++;
                }
                cnt++;
            }
        }
    }    
    int* int_numbers = new int[10];
    for (int i = 0; i < 10; i++)
         int_numbers[i] = atoi(norm_num[i]);
    
    for (int i = 0; i < 10; i++)
        int_numbers[i] += 2;
    int cunt = 0;
    cout << "Готовая строка:" << endl;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '*' and (str[i + 1] == ' ' or str[i + 1] == 'М' or str[i + 1] == '\0'))
        {
            cout << int_numbers[cunt];
            cunt++;
        }
        else if (str[i - 1] == ' ' and str[i] == ' ') continue;
        else if (str[i] != '*') cout << str[i];
    }
}
