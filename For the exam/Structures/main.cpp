#include <iostream>

using namespace std;

struct student{
    string Name; // ���� ���������
    int age;
};

int main()
{
    student ArrayOfStudents[3];
    /*
        ������ ��������� ��������� �����, ��� � ����� ������ ������
        ����������� ��� � ������ �������
    */

    ArrayOfStudents[0].Name = "Ivan"; // ���������� � ����� ����� ����� �����

    cout << ArrayOfStudents[0].Name << endl;

    student* A = nullptr; // ����� ����� ��������� ������ �� ���������

    A = new student[4]; // ����� ������� ��������� �������� ������������ ��������

    for(int i = 0; i < 4; i++) {
        A[i].age = 18 + i;
    }

    for(int i = 0; i < 4; i++) {
        cout << A[i].age << " ";
    }

    return 0;
}
