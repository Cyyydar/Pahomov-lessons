#include <iostream>
#include <limits>

using namespace std;

int createMatrix(int**& M);
void printMatrix(int**& M, int S);
void deleteMatrix(int**& M, int S);
void rotateMatrix(int**& M, int S);

int getInt();

int main()
{
    int **matrix = nullptr;
    int Size = createMatrix(matrix);
    cout << "Entered matrix:\n";
    printMatrix(matrix, Size);

    rotateMatrix(matrix, Size);
    cout << "Rotated matrix:\n";
    printMatrix(matrix, Size);

    deleteMatrix(matrix, Size);
    return 0;
}

int createMatrix(int**& M){
    cout << "Enter matrix size:\n";
    int S = getInt();


    //создание матрицы
    M = new int*[S];
    for(int i = 0; i < S; i++){
        M[i] = new int[S];
    }

    //запись в матрицу
    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            cout << "[" << i << "][" << j << "]\n";
            M[i][j] = getInt();
        }
    }
    return S;
}
void printMatrix(int**& M, int S){
    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
void deleteMatrix(int**& M, int S){
    for(int i = 0; i < S; i++){
        delete M[i];
    }
    delete []M;
    M = nullptr;
}

void rotateMatrix(int**& M, int S){
    int temp[S][S];
    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            temp[j][S-1-i] = M[i][j];
        }
    }

    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            M[i][j] = temp[i][j];
        }
    }
}

int getInt(){
    int i;
    while(1){
        cout << "Enter integer number:\n";
        cin >> i;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error, try again\n";
            continue;
        }
        if(cin.peek() != '\n'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error, try again\n";
            continue;
        }

        return i;
    }
}
