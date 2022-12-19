#include <iostream>
#include <limits>

using namespace std;

int getInt();

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
    cout << "Entered matrix:\n";
    printMatrix(Matrix,Size);

    cout << "Sorted matrix:\n";
    spiralSort(Matrix,Size);

    printMatrix(Matrix,Size);
	deleteMatrix(Matrix,Size);
    return 0;
}

int createMatrix(int**& M){
    if(M != nullptr){
        cout << "Matrix already created\n";
    }

    int Size;
    cout << "Enter matrix size\n";
    do{
        Size = getInt();
        if(Size <= 1) {
            cout << "Its not a matrix, try again\n";
        }
    } while(Size <= 1);
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
            cout << "[" << i <<"][" << j << "] ";
            M[i][j] = getInt();
        }
    }
}


void spiralSort(int**& M, int Size){
    int* Array = new int[Size*Size];
    matrixInArray(M, Size, Array);
    sortArray(Array,Size);

    int X, Y;
    // Center
    if(Size%2 != 0) {
        X = Size/2;
        Y = X;
    } else {
        X = Size/2;
        Y = X-1;
    }

    /*заварачиваем матрицу обратно*/
    int k = 1; //шаг
    int j = 0;
    while(1){
        //down
        for(int i = 0; i < k; i++){
            if(X == Y && i < k && k != 1){
                M[Y][X] = Array[j];
                return;
            }
            M[Y][X] = Array[j];
            j++;
            Y++;
        }
        //left
        for(int i = 0; i < k; i++){
            M[Y][X] = Array[j];
            j++;
            X--;
        }
        k++;
        //up
        for(int i = 0; i < k; i++){
            if(X == Y && i < k && Y == 0){
                M[Y][X] = Array[j];
                return;
            }
            M[Y][X] = Array[j];
            j++;
            Y--;
        }
        //right
        for(int i = 0; i < k; i++){
            M[Y][X] = Array[j];
            j++;
            X++;
        }
        k++;
    }
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

int getInt(){
    while(1){
        int i;
        cout << "Enter int number:\n";
        cin >> i;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Error, please try again\n";
            continue;
        }
        if(cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Error, please try again\n";
            continue;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return i;
    }
}

