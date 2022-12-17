#include <iostream>

using namespace std;

int createMatrix(int**& M);
void deleteMatrix(int**& M, int Size);
void printMatrix(int**& M, int Size);
void fillMatrix(int**& M, int Size);

void spiralSort(int**& M, int Size);
void matrixInArray(int**& M, int Size, int* A);
void sortArray(int* A, int Size);

int main()
{
    int** Matrix = nullptr;
    int Size = createMatrix(Matrix);
    fillMatrix(Matrix,Size);
    printMatrix(Matrix,Size);

    spiralSort(Matrix,Size);
    return 0;
}

int createMatrix(int**& M){
    if(M != nullptr){
        cout << "Matrix already created\n";
    }

    int Size;
    cout << "Enter matrix size\n";
    cin >> Size;
    M = new int*[Size];

    for (int i = 0;i < Size;i++){
        M[i] = new int[Size];
    }
}

void deleteMatrix(int**& M, int Size) {
    for (int i = 0;i < Size;i++){
        delete M[i];
    }
    delete []M;
}

void printMatrix(int**& M, int Size){
    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            cout << M[i][j] << " ";
        }
    cout << endl;
    }
}

void fillMatrix(int**& M, int Size){
    cout << "Fill integer matrix: \n";
    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            cin >> M[i][j];
        }
    }
}


void spiralSort(int**& M, int Size){
    int* Array = new int[Size*Size];
    matrixInArray(M, Size, Array);
    sortArray(Array,Size);
}


void matrixInArray(int**& M, int Size,int* A){
    int k = 0;
    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            A[k] = M[i][j];
            k++;
        }
    }
}

void sortArray(int* A, int Size) {
    for (int i = Size*Size;i > 0; i--){
        for (int j = 1; j < i; j++){
            if(A[j-1] > A[j]){
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
}


