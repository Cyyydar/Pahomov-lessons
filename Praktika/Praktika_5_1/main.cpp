#include <iostream>

using namespace std;

int** Mass = nullptr;
int* temp = nullptr;
int matrixSize;
int currentStep = 1;

int X, Y = 0;

void create_Mass();
void show_Mass();
void delete_Mass();
int centerMatrix();
void spiralSort();
void left(int&);
void up(int&);
void right(int&);
void down(int&);

int main()
{
    create_Mass(); //создание матрицы
    show_Mass(); //вывод матрицы на экран

    spiralSort();
    return 0;
}

// влево - вверх - вправо - вниз

void spiralSort(){
    X = centerMatrix();
    Y = X;
    int fillarray = 0;
    for(int i = 0; i < matrixSize; i ++){
    left(fillarray);
    }
    for(int i = 0; i < matrixSize*matrixSize; i++) {
        cout << " " <<temp[i];
    }


}

void left(int &Pos){
    for(int i = 0; i <= currentStep; i++){
        cout << "Left "<< X << " " << Y << " " <<Mass[Y][X] << endl;
        temp[Pos] = Mass[Y][X];
        Pos++;
        if(X-1 >= 0){
            X--;
        }
    }
    up(Pos);
}

void up(int &Pos){
    for(int i = 0; i < currentStep; i++){
        cout << "Up "<< X << " " << Y << " " << Mass[Y][X] << endl;
        if(Y-1 >= 0)
            Y--;
        temp[Pos] = Mass[Y][X];
        Pos++;
        if(currentStep > Y - currentStep){
            currentStep++;
            X++;
            return;
        }
    }
    X++;
    currentStep++;
    right(Pos);
}

void right(int &Pos){
    for(int i = 0; i < currentStep; i++){
        cout << "Right "<< X << " " << Y << " " << Mass[Y][X] << endl;
        temp[Pos] = Mass[Y][X];
        Pos++;
        if(X+1 < matrixSize){
            X++;
        }
    }
    Y++;
    down(Pos);
}

void down(int &Pos){
    for(int i = 0; i < currentStep; i++){
        cout << "Down "<< X << " " << Y << " " << Mass[Y][X] << " " << currentStep<< endl;
        temp[Pos] = Mass[Y][X];
        Pos++;
        Y++;
    }
    currentStep++;
    left(Pos);
}

int centerMatrix(){
    return matrixSize/2;
}

void create_Mass() {
    delete_Mass();
    cout << "Введите размер квадратной матрицы(одно целое число)\n";
    int a;
    cin >> a;
    if(a < 1) {
        cout << "Неверный размер\n";
        return;
    }

    matrixSize = a;

    Mass = new int*[matrixSize];
    temp = new int[matrixSize*matrixSize];

    for(int i = 0; i < matrixSize; i++) {
        Mass[i] = new int[matrixSize];
    }

    cout << "Заполните матрицу целых чисел " << matrixSize << " на " << matrixSize << endl;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++) {
            cin >> Mass[i][j];
        }
    }
}

void show_Mass() {
    if(Mass == nullptr){
        cout << " Матрица не создана\n";
        return;
    }

    cout << " Матрица:\n";
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++) {
            cout << " " <<Mass[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void delete_Mass() {
    delete[]Mass;
    Mass = nullptr;
}
