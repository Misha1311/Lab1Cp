#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


struct students // структура для 1 задания
{
    char Surname[56];
    char Group[20];
    int BirthdayYear;
    int PhysicMark;
    int MathMark;
    int CompScienceMark;
};


void task1()
{
    //Привязал дату с компьютера для того что бы программа коректно работала через некоторое время (например через год)
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);

    const int N = 2;
    students group[N];

    for (int i = 0; i < N; i++) // Ввод данных
    {
        cout << "\nВведите Фамилию: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(group[i].Surname, 56);

        cout << "\nВведите группу: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(group[i].Group, 20);

        cout << "\nВведите год рождения: ";
        cin >> group[i].BirthdayYear;

        cout << "\nВведите оценку по Физике: ";
        cin >> group[i].PhysicMark;

        cout << "\nВведите оценку по Математике: ";
        cin >> group[i].MathMark;

        cout << "\nВведите оценку по Информатике: ";
        cin >> group[i].CompScienceMark;

    }

    cout << "\n----------------------------------------------------------\n";
    int year19 = 0;
    for (int i = 0; i < N; i++) // проверка на возвраст 
    {
        if (group[i].BirthdayYear <= nowLocal.tm_year + 1882)
        {
            cout << "\nФамилия " << group[i].Surname << "\n";
            cout << "\nГруппа " << group[i].Group << "\n";
            cout << "\nГод рождения " << group[i].BirthdayYear << "\n";
            cout << "\nОценка по физике " << group[i].PhysicMark << "\n";
            cout << "\nОценка по математике " << group[i].MathMark << "\n";
            cout << "\nОценка по информатике " << group[i].CompScienceMark << "\n";
            year19++;
        }
    }
    cout << "\nКоличество студентов старше 19 лет : " << year19 << "\n\n";
}

struct worker //cтруктура для 2 задания
{
    char Surname[56];
    char Position[40];
    int Year;
    int Month;
    int Day;
    int ContractTime;
    int Salary;
};

void task2()
{
    //Привязал дату с компьютера для того что бы программа коректно работала через некоторое время (например через год либо месяц)
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);

    const int N = 2;
    worker workers[N];

    for (int i = 0; i < N; i++) // Ввод данных
    {
        cout << "\nВведите Фамилию: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(workers[i].Surname, 56);

        cout << "\nВведите Должность: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(workers[i].Position, 40);

        cout << "\nВведите дату подписания контракта (Год,Mecяц,День): ";
        cin >> workers[i].Year;
        cin >> workers[i].Month;
        cin >> workers[i].Day;

        cout << "\nВведите срок действия контракта: ";
        cin >> workers[i].ContractTime;

        cout << "\nВведите оклад: ";
        cin >> workers[i].Salary;
    }

    cout << "\n----------------------------------------------------------\n";
    for (int i = 0; i < N; i++) //Проверка и вывод работников подписавших контракт менее года назад
    {
        if ((workers[i].Year <= nowLocal.tm_year + 1900) && (workers[i].Year >= nowLocal.tm_year + 1898) && (nowLocal.tm_mon + 1 <= workers[i].Month) && (nowLocal.tm_mday <= workers[i].Day))
        {
            cout << "\nФамилия " << workers[i].Surname << "\n";
            cout << "\nДолжность " << workers[i].Position << "\n";
            cout << "\nДата подписания контракта " << workers[i].Year << "." << workers[i].Month << "." << workers[i].Day << "\n";
            cout << "\nСрок действия контракта " << workers[i].ContractTime << "\n";
            cout << "\nОклад " << workers[i].Salary << "\n";
        }
    }
}


void task3()
{


}

int main()
{
    setlocale(LC_ALL, "Russian");
    int select = 0;
    do { // Выбора задания
        cout << "Выберите номер задания :1) Легкий уровень 2) Средний уровень 3) Сложный уровень. Если вы хотите выйти введите 0. \n";
        cin >> select;
        switch (select)
        {
        case 0: break;
        case 1:task1(); break;
        case 2:task2(); break;
        case 3:task3(); break;
        default: cout << "Вы ввели не правильное число(Введите от 1-3). "; break;
        }
    } while (select != 0);

}