#include <iostream>
#include <limits>

using namespace std;

void createArray(int*& A, int S);
void deleteArray(int*& A, int S);
void printArray(int*& A, int S);
void sortArray(int*& A, int S);
int getInt();

int main()
{
    int* Array = nullptr;
    int Size;

    cout << "Enter size of Array:\n";
    Size = getInt();

    createArray(Array,Size);
    printArray(Array,Size);
    sortArray(Array,Size);
    printArray(Array,Size);

    deleteArray(Array,Size);
    return 0;
}

void createArray(int*& A, int S){
    A = new int[S];

    cout << "Fill array:\n";
    for(int i = 0; i < S; i++){
        cout << i <<")\n";
        A[i] = getInt();
    }
}
void printArray(int*& A, int S) {
    for(int i = 0; i < S; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
void deleteArray(int*& A, int S){
    delete []A;
}

void sortArray(int*& A, int S){
    int D[S];
    for(int i = 0; i < S; i++){
        int sum = 0;
        D[i] = A[i];
        while(abs(D[i]) > 0){
            sum += abs(D[i]) % 10;
            D[i] /= 10;
        }
        D[i] = sum;
    }
    for(int i = S; i > 0; i--){
        for(int j = 1; j < i; j++){
            if(D[j-1] > D[j]){
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                temp = D[j];
                D[j] = D[j-1];
                D[j-1] = temp;
            }
        }
    }
}

int getInt(){
    int i;
    while(1){
        cout << "Enter integer number:\n";

        cin >> i;

        if(cin.fail()){
            cout << "Error, try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        if(cin.peek() != '\n'){
            cout << "Error, try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        return i;
    }
}

