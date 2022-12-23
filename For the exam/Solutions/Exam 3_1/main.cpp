#include <iostream>

using namespace std;

void createMatrix(int**& M, int S);
void deleteMatrix(int**& M, int S);
void printMatrix(int**& M, int S);
void shift(int**& M, int S);


int main()
{
    int Size;
    int** matrix;
    cout << "Enter matrix size:\n";
    cin >> Size;

    createMatrix(matrix, Size);
    cout << "Entered matrix:\n";
    printMatrix(matrix,Size);
    shift(matrix,Size);
    cout << "Shifted Matrix:\n";
    printMatrix(matrix,Size);

    deleteMatrix(matrix,Size);
    return 0;
}

void createMatrix(int**& M, int S) {
    M = new int*[S];
    for(int i = 0; i < S; i++){
        M[i] = new int[S];
    }

    cout << "Fill the matrix:\n";

    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            cin >> M[i][j];
        }
    }
}

void deleteMatrix(int**& M, int S) {
    for(int i = 0; i < S; i++){
        delete M[i];
    }
    delete []M;
}

void printMatrix(int**& M, int S) {
    for(int i = 0; i < S; i++){
        for(int j = 0; j < S; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void shift(int**& M, int S) {
    int l,sh;
    cout << "Enter number of line:\n";
    cin >> l;
    cout << "Enter the value of shift:\n";
    cin >> sh;
    l--;
    if(sh > 0){
    int temp = M[l][0];
        for(int i = 0; i < abs(sh); i++){
            for(int j = 1; j < S; j++){
                int temp1 = M[l][j];
                M[l][j] = temp;
                temp = temp1;
                if(j == S-1) {
                    M[l][0] = temp;
                }
            }
        }
    } else {
        int temp = M[l][S-1];
        for(int i = 0; i < abs(sh); i++){
            for(int j = S-2; j >= 0; j--){
                int temp1 = M[l][j];
                M[l][j] = temp;
                temp = temp1;
                if(j == 0) {
                    M[l][S-1] = temp;
                }
            }
        }
    }
}
