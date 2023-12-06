#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

struct Employee {
    string surname;
    string initials;
    string position;
    int year;
    double salary;
};

void AddEmployee(Employee*& p, int& N);
void DeleteEmployee(Employee*& p, int& N);
void EditEmployee(Employee* p, const int N);
void SortBySurname(Employee* p, const int N);
void SortBySalary(Employee* p, const int N);
void SortByYear(Employee* p, const int N);
void PrintEmployee(Employee* p, const int N);
void DisplayEmployeesTable(Employee* p, const int N);
int SearchEmployee(Employee* p, const int N, const string surname);

int main() {
    SetConsoleCP(1251); // Встановлення кодування win-cp1251 для вводу
    SetConsoleOutputCP(1251); // Встановлення кодування win-cp1251 для виводу

    int N = 3;
    Employee* p = new Employee[N];

    // Ініціалізація деяких працівників
    p[0] = { "Яворський", "І.І.", "Java розробник", 2020, 2000.0 };
    p[1] = { "Мельник", "П.П.", "Python розробник", 2019, 1600.0 };
    p[2] = { "Ільницький", "С.С.", "С++ розробник", 2021, 1800.0 };

    int menuItem;
    string surname;
    do {
        DisplayEmployeesTable(p, N);
        cout << "\n\n\nМеню:\n\n";
        cout << " [1] - Додати співробітника\n";
        cout << " [2] - Видалити співробітника\n";
        cout << " [3] - Редагувати дані співробітника\n";
        cout << " [4] - Сортувати за прізвищем\n";
        cout << " [5] - Сортувати за зарплатою\n";
        cout << " [6] - Сортувати за роком прийняття на роботу\n";
        cout << " [7] - Пошук за прізвищем\n";
        cout << " [0] - Вийти з програми\n\n";
        cout << "Оберіть пункт: "; cin >> menuItem;
        cout << "\n\n\n";

        switch (menuItem) {
        case 1:
            AddEmployee(p, N);
            break;
        case 2:
            DeleteEmployee(p, N);
            break;
        case 3:
            EditEmployee(p, N);
            break;
        case 4:
            SortBySurname(p, N);
            break;
        case 5:
            SortBySalary(p, N);
            break;
        case 6:
            SortByYear(p, N);
            break;
        case 7:
            cout << "Введіть прізвище працівника: "; cin >> surname;
            PrintEmployee(p, SearchEmployee(p, N, surname));
            break;
        default:
            cout << "Немає такої опції! Оберіть щось інше..." << endl;
            break;
        }
    } while (menuItem != 0);

    return 0;
}


void AddEmployee(Employee*& p, int& N) {
    Employee* tmp = new Employee[N + 1];
    for (int i = 0; i < N; i++)
        tmp[i] = p[i];
    cout << "Введіть прізвище працівника: "; cin >> tmp[N].surname;
    cout << "Введіть ініціали працівника: "; cin >> tmp[N].initials;
    cout << "Введіть посаду працівника: "; cin >> tmp[N].position;
    cout << "Введіть рік прийняття на роботу: "; cin >> tmp[N].year;
    cout << "Введіть зарплату працівника: "; cin >> tmp[N].salary;
    N++;
    delete[] p;
    p = tmp;
}

void DeleteEmployee(Employee*& p, int& N) {
    int k;
    cout << "Введіть номер працівника, якого потрібно видалити: "; cin >> k;
    if (k < 1 || k > N) {
        cout << "Помилка вводу! Такого працівника не існує!" << endl;
        return;
    }
    Employee* tmp = new Employee[N - 1];
    for (int i = 0; i < k - 1; i++)
        tmp[i] = p[i];
    for (int i = k - 1; i < N - 1; i++)
        tmp[i] = p[i + 1];
    N--;
    delete[] p;
    p = tmp;
}


void EditEmployee(Employee* p, const int N) {
    int k;
    cout << "Введіть номер працівника, якого потрібно редагувати: "; cin >> k;
    if (k < 1 || k > N) {
        cout << "Помилка вводу! Такого працівника не існує!" << endl;
        return;
    }
    cout << "Введіть прізвище працівника: "; cin >> p[k - 1].surname;
    cout << "Введіть ініціали працівника: "; cin >> p[k - 1].initials;
    cout << "Введіть посаду працівника: "; cin >> p[k - 1].position;
    cout << "Введіть рік прийняття на роботу: "; cin >> p[k - 1].year;
    cout << "Введіть зарплату працівника: "; cin >> p[k - 1].salary;
}

void SortBySurname(Employee* p, const int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (p[j].surname > p[j + 1].surname)
                swap(p[j], p[j + 1]);
}

void SortBySalary(Employee* p, const int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (p[j].salary > p[j + 1].salary)
                swap(p[j], p[j + 1]);
}

void SortByYear(Employee* p, const int N) {
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (p[j].year > p[j + 1].year)
                swap(p[j], p[j + 1]);
}

void PrintEmployee(Employee* p, const int N) {
    if (N < 0) {
        cout << "Помилка вводу! Неправильний номер працівника!" << endl;
        return;
    }
    cout << "Прізвище: " << p[N].surname << endl;
    cout << "Ініціали: " << p[N].initials << endl;
    cout << "Посада: " << p[N].position << endl;
    cout << "Рік прийняття на роботу: " << p[N].year << endl;
    cout << "Зарплата: " << p[N].salary << endl;
}

void DisplayEmployeesTable(Employee* p, const int N) {
    cout << setfill('=') << setw(85) << "=" << setfill(' ') << endl;
    cout << "|" << setw(15) << "Прізвище" << "|" << setw(15) << "Ініціали" << "|" << setw(20) << "Посада" << "|" << setw(15) << "Рік прийняття" << "|" << setw(10) << "Зарплата" << "|" << endl;
    cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(15) << p[i].surname << "|" << setw(15) << p[i].initials << "|" << setw(20) << p[i].position << "|" << setw(15) << p[i].year << "|" << setw(10) << p[i].salary << "|" << endl;
    }
    cout << setfill('=') << setw(85) << "=" << setfill(' ') << endl;
}

int SearchEmployee(Employee* p, const int N, const string surname) {
    for (int i = 0; i < N; i++)
        if (p[i].surname == surname)
            return i;
    return -1;
}
