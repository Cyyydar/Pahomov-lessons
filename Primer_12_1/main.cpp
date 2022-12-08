#include <iostream>

using namespace std;

struct Student{
    string FIO;
    string group;
    int birthYear;
} Ivanov, Petrov;

int main()
{
    const int K{5};
    Student mas_students[K];


    Ivanov.FIO = "Иванов Иван Иванович";
    Ivanov.birthYear = 1833;
    Ivanov.group = "МСО-205-Б-21";
    cout << Ivanov.FIO << endl;
    cout << Ivanov.birthYear << endl;
    cout << Ivanov.group << endl;

    cout << "Введите данные " << K << " студентов :\n";
    for(int i = 0; i < K; i++) {
        cout << " " << i+1 << " )" << " Введите ФИО ";
        getline(cin, mas_students[i].FIO);
        cout << " " << i+1 << " )" << " Введите год рождения ";
        cin >> mas_students[i].birthYear;
        cin.ignore(1000, '\n');
        cout << " " << i+1 << " )" << " Введите Группу";
        getline(cin, mas_students[i].group);
    }

    for(int i = 0; i < K; i++) {
        cout << mas_students[i].FIO << endl;
        cout << mas_students[i].birthYear << endl;
        cout << mas_students[i].group << endl;
    }
    return 0;
}
