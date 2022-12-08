#include <iostream>

using namespace std;

int** Mass = nullptr;
int lines = 0;
int column = 0;

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
    cout << "Введите количество строк массива\n";
    int a;
    cin >> a;
    if(a < 1) {
        cout << "Неверный размер\n";
        return;
    }

    lines = a;

    cout << "Введите количество столбцов массива\n";
    cin >> a;
    if(a < 1) {
        cout << "Неверный размер\n";
        return;
    }

    column = a;
    Mass = new int*[lines];

    for(int i = 0; i < lines; i++) {
        Mass[i] = new int[column];
    }

    cout << "Заполните матрицу целых чисел " << lines << " на " << column << endl;
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < column; j++) {
            cin >> Mass[i][j];
        }
    }
}

void show_Mass() {
    if(Mass == nullptr){
        cout << " Массив не создан\n";
        return;
    }

    cout << " Массив:\n";
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < column; j++) {
            cout << " " <<Mass[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
