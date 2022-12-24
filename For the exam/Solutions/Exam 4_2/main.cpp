#include <iostream>
#include <limits>

using namespace std;

void createMatrix(int**& M, int S);
void printMatrix(int**& M, int S);
void deleteMatrix(int**& M, int S);
void shift(int**& M, int S);
int getInt();

int main()
{
    int **matrix = nullptr;
    int Size;
    cout << "Enter matrix size:\n";
    Size = getInt();

    createMatrix(matrix, Size);
    cout << "Entered matrix: \n";
    printMatrix(matrix, Size);

    shift(matrix, Size);
    cout << "Shifted matrix: \n";
    printMatrix(matrix, Size);

    deleteMatrix(matrix, Size);
    return 0;
}

void createMatrix(int**& M, int S){
    if(M != nullptr){
        deleteMatrix(M, S);
    }
    M = new int*[S];
    for(int i = 0; i < S; i++){
        M[i] = new int[S];
    }

    cout << "Fill the matrix:\n";
    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            cout << "[" << i << "][" << j << "]\n";
            M[i][j] = getInt();
        }
    }
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
void shift(int**& M, int S){
    int c;
    cout << "Enter number of column (" << 1 << " - " << S << "):\n";

    do{

        c = getInt();

    }while(!c > 0 && !c <= S);
    c--;

    int sh;
    cout << "Enter the value of shift:\n";
    sh = getInt();

    sh += S; //Чтобы не писать для отрицательных чисел, мы будет просто полностью проворачивать матрицу

    for(int i = 0; i < sh; i++){
        int temp = M[0][c];
        M[0][c] = M[S-1][c];
        for(int j = 1; j < S; j++){
            int tmp = M[j][c];
            M[j][c] = temp;
            temp = tmp;
        }
    }
}

int getInt() {
    int i;
    while(1){
        cout << "Enter integer number:\n";
        cin >> i;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Error, try again\n";
            continue;
        }
        if(cin.peek() != '\n'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Error, try again\n";
            continue;
        }
        return i;
    }
}
