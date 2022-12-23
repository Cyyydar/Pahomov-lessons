#include <iostream>
#include <fstream>

using namespace std;

int createMatrix(int**& M);
void printMatrix(int**& M, int S);
void deleteMatrix(int**& M, int S);
void rotateMatrix(int**& M, int S);

int main()
{
    int **matrix = nullptr;
    int Size = createMatrix(matrix);


    rotateMatrix(matrix, Size);
    printMatrix(matrix, Size);

    deleteMatrix(matrix, Size);
    return 0;
}

int createMatrix(int**& M){

    ifstream input("input.txt");
    if(!input){
        cout << "Error\n";
    }
    int S;
    input >> S;

    //создание матрицы
    M = new int*[S];
    for(int i = 0; i < S; i++){
        M[i] = new int[S];
    }
    //запись в матрицу
    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            input >> M[i][j];
        }
    }
    input.close();
    return S;
}
void printMatrix(int**& M, int S){
    ofstream output("output.txt");
    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            output << M[i][j] << " ";
        }
        output << endl;
    }
    output.close();
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
