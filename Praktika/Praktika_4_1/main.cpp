#include <iostream>

using namespace std;

void create_Mass(int**&matrix, int&lines, int&column);
void show_Mass(const int *const* const M, const int lines, const int column);

int main()
{
    int **Mass = nullptr;
    int lines = 0;
    int column = 0;
    show_Mass(Mass, lines, column);
    create_Mass(Mass, lines, column);
    show_Mass(Mass, lines, column);


    delete[]Mass;
    return 0;
}

void create_Mass(int**&matrix, int&lines, int&column) {
    delete[]matrix;

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
    matrix = new int*[lines];

    for(int i = 0; i < lines; i++) {
        matrix[i] = new int[column];
    }

    cout << " Заполните массив " << lines <<" на " << column << endl;
    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < column; j++){
            cin >> matrix[i][j];
        }
    }
}

void show_Mass(const int *const* const M, const int lines, const int column) {
    if(M == nullptr){
        cout << " Массив не был создан\n";
        return;
    }
    cout << " Массив: \n";
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < column; j++){
            cout << " " << M[i][j];
        }
        cout << endl;
    }
     cout << endl;
}
