#include <iostream>

using namespace std;

struct student{
    string Name; // Поля структуры
    int age;
};

int main()
{
    student ArrayOfStudents[3];
    /*
        Массив студентов создается также, как и любой другой массив
        Указывается тип и размер массива
    */

    ArrayOfStudents[0].Name = "Ivan"; // Обращаться к полям можно через точку

    cout << ArrayOfStudents[0].Name << endl;

    student* A = nullptr; // Также можно создавать ссылки на структуры

    A = new student[4]; // Таким образом обеспечив создание динамических массивов

    for(int i = 0; i < 4; i++) {
        A[i].age = 18 + i;
    }

    for(int i = 0; i < 4; i++) {
        cout << A[i].age << " ";
    }

    return 0;
}
