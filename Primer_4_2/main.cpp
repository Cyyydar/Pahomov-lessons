#include <iostream>

using namespace std;

int* Mass = nullptr;
int Razmer_Mass = 0;

void create_Mass();
void show_Mass();
void delete_Mass();

int main()
{
    show_Mass();
    create_Mass();
    show_Mass();
    delete_Mass();
    show_Mass();

    return 0;
}

void delete_Mass() {
    delete[]Mass;
    Mass = nullptr;
}

void create_Mass() {
    delete_Mass();
    cout << "Введите длину массива\n";
    int a;
    cin >> a;
    if(a < 1) {
        cout << "Неверный размер\n";
        return;
    }

    Razmer_Mass = a;
    Mass = new int[Razmer_Mass];

    cout << "Введите " << Razmer_Mass << " целых чисел\n";
    for(int i = 0; i < Razmer_Mass; i++){
        cin >> Mass[i];
    }
}

void show_Mass() {
    if(Mass == nullptr){
        cout << " Массив не создан\n";
        return;
    }

    cout << " Массив:\n";
    for(int i = 0; i < Razmer_Mass; i++){
        cout << " " <<Mass[i];
    }
    cout << endl;
}

