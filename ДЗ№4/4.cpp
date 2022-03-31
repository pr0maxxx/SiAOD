/*
Вариант 6
Аэропорт(расписание авиарейсов) : пункт назначения, номер рейса(целое число), 
день недели(номер), время вылета / прилета, , информация о задержке вылета / прилета в часах.
Примечание.Номер рейса нечетный – это рейс, вылетающий из аэропорта, четный номер рейса – это рейс, прилетающий в аэропорт.
Операции
1)	Добавить расписание по новому рейсу.
2)	Удалить информацию об отмененном рейсе и сохранить ее в архивной таблице.
3)	Сформировать список рейсов, вылетающих из аэропорта в заданный день недели и в заданный пункт назначения.
4)	Подсчитать количество рейсов, прилетающих в аэропорт в заданный день недели.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Schedule
{
    string destination;
    int flight_num;
    int day_num;
    string departure_time;
    string arrival_time;
    int delay;
};
vector<Schedule> table;
vector<Schedule> archive;

void insert_schedule(vector<Schedule>& table, string destination, int flight_num, int day_num, string departure_time, string arrival_time, int delay)
{
    Schedule new_flight = { destination, flight_num, day_num, departure_time, arrival_time, delay };
    table.push_back(new_flight);
}

void add_flight(vector<Schedule>& table)
{
    string destination, departure_time, arrival_time;
    int flight_num, day_num, delay;
    cout << "Добавьте расписание по новому рейсу:" << endl;
    cout << "Введите пункт назначения:" << endl;
    cin >> destination;
    cout << "Введите номер рейса:" << endl;
    cin >> flight_num;
    cout << "Введите день недели(номер):" << endl;
    cin >> day_num;
    cout << "Введите время вылета:" << endl;
    cin >> departure_time;
    cout << "Введите время прилета:" << endl;
    cin >> arrival_time;
    cout << "Введите задержка рейса:" << endl;
    cin >> delay;
    insert_schedule(table, destination, flight_num, day_num, departure_time, arrival_time, delay);
}

void print_flights(vector<Schedule>& table)
{
    for (int i = 0; i < table.size(); i++)
    {
        cout << setw(3) << left << table[i].flight_num << " ";
        cout << setw(13) << left << table[i].destination << " ";
        cout << setw(1) << left << table[i].day_num << " ";
        cout << setw(5) << left << table[i].departure_time << " ";
        cout << setw(5) << left << table[i].arrival_time << " ";
        cout << setw(2) << left << table[i].delay << endl;
    }
}

void delete_flight(vector<Schedule>& table,int num)
{
    bool flag = true;
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].flight_num == num)
        {
            archive.push_back(table[i]);
            table.erase(table.begin() + i);
            flag = false;
        }
    }
    if (flag) cout << "Рейса с таким номером не найдено!" << endl;
}

int count_to_airport_flights(vector<Schedule>& table, int n) 
{
    int count = 0;
    for (int i = 0; i < table.size(); i++) 
    {
        if (table[i].day_num == n && table[i].flight_num % 2 == 0) 
            count++;
    }
    return count;
}
void count_from_airport_flights(vector<Schedule>& table, int n, string to) 
{
    vector<Schedule> arr;
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].day_num == n && table[i].destination == to && table[i].flight_num % 2 == 1)
            arr.push_back(table[i]); 
    }
    if (arr.size() != 0)
    {
        cout << "Список рейсов, вылетающих из аэропорта в заданный день недели и в заданный пункт назначения" << endl;
        print_flights(arr);
    }
    else cout << "Нет подходящих рейсов!" << endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    
    insert_schedule(table, "Tyumen", 103, 1, "10:00", "15:00", 1);
    insert_schedule(table,"Moscow", 201, 1, "12:00", "15:00", 3);
    insert_schedule(table,"Smolensk", 400, 2, "11:00", "12:00", 2);
    insert_schedule(table,"Moscow", 57, 2, "11:00", "12:00", 1);
    insert_schedule(table, "Moscow", 633, 2, "13:00", "15:00", 0);
    insert_schedule(table, "St. Peterburg", 624, 2, "11:00", "12:00", 2);
    insert_schedule(table, "Sochi", 633, 3, "13:00", "15:00", 2);
    insert_schedule(table,"Moscow", 711, 3, "17:00", "19:00", 4);
    
    cout << "Практическая работа №4 Вайдов Максим " << endl;
    cout << "Текущее расписание рейсов: " << endl;
    print_flights(table);
    cout << "Выберите операцию над расписанием:" << endl << "1 - Добавить рейс" << endl << "2 - Удалить рейс"
         << endl << "3 - Сформировать список рейсов, вылетающих из аэропорта в заданный день недели и в заданный пункт назначения" << endl
         << "4 - Подсчитать количество рейсов, прилетающих в аэропорт в заданный день недели" << endl << "0 - Выйти из программы" << endl;
    int mode,N;
    cin >> mode;
    while (mode > 0 && mode < 5)
    {
        if (mode == 1)
        {
            add_flight(table);
            cout << "Новое расписание рейсов: " << endl;
            print_flights(table);

        }
        else if (mode == 2)
        {
            cout << "Введите номер рейса для удаления:" << endl;
            cin >> N;
            delete_flight(table, N);
            cout << endl << "Новое расписание рейсов: " << endl;
            print_flights(table);
            cout << endl << "Отмененные рейсы: " << endl;
            print_flights(archive);
        }
        else if (mode == 3)
        {
            int num;
            string to;
            cout << endl << "Введите день недели(номер от 1 до 7) и пункт назначения для формирования списка рейсов: " << endl;
            cin >> num >> to;
            count_from_airport_flights(table, num, to);
        }
        else if (mode == 4)
        {
            int num;
            cout << endl << "Введите день недели(номер от 1 до 7) для подсчета количества прилетающих в аэропорт рейсов: " << endl;
            cin >> num;
            cout << "Количество прилетающих в аэропорт рейсов: " << count_to_airport_flights(table, num) << endl;
        }
        else break;
        cout << endl << "Выберите операцию над расписанием:" << endl << "1 - Добавить рейс" << endl << "2 - Удалить рейс"
             << endl << "3 - Сформировать список рейсов, вылетающих из аэропорта в заданный день недели и в заданный пункт назначения" << endl
             << "4 - Подсчитать количество рейсов, прилетающих в аэропорт в заданный день недели" << endl << "0 - Выйти из программы" << endl; 
        cin >> mode;
    } 
}
