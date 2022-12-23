#include <iostream>
#include <limits>

using namespace std;


int createArray(int**& Array);
void fillMatrix(int**& Array, int Size);
void deleteArray(int**& Array, int Size);
void rotateArray(int**& Array, int Size);
void printArray(int**& Array, int Size);
void print(string str);
int getInt();


int main()
{
    int** matrix = nullptr;
    int Size;
    Size = createArray(matrix);
    fillMatrix(matrix,Size);
    print("Entered array:\n");
    printArray(matrix,Size);
    rotateArray(matrix,Size);
    print("\n");
    printArray(matrix,Size);

	deleteArray(Matrix,Size);
    return 0;
}
void print(string str){
    cout << str << endl;
}
int createArray(int**& Array){
    if(Array != nullptr){
        print("Array already created");
        return 0;
    }
    int Size;
    Size = getInt();
    Array = new int*[Size];
    print("Enter matrix Size:");


    for (int i = 0;i < Size ;i++ ){
            Array[i] = new int[Size];
    }
    return Size;
}

void fillMatrix(int**& Array, int Size){
    print("Fill integer Matrix:\n");
    for (int i = 0;i < Size ;i++){
        for (int j = 0;j < Size ;j++){
            cout << "[" << i << "][" << j << "]\n";
            Array[i][j] = getInt();
        }
    }
}

void printArray(int**& Array, int Size){
    for (int i = 0;i < Size ;i++){
        for (int j = 0;j < Size ;j++){
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteArray(int**& Array, int Size){
    for (int i = 0;i < Size ;i++){
        delete Array[i];
    }
    delete[]Array;
}

void rotateArray(int**& Array, int Size) {
    int temp[Size][Size];
    for (int i = 0;i < Size ;i++){
        for (int j = 0;j < Size ;j++){
            temp[Size-j-1][i] = Array[i][j];
        }
    }
    for (int i = 0;i < Size ;i++){
        for (int j = 0;j < Size ;j++){
            Array[i][j] = temp[i][j];
        }
    }
}

int getInt(){
    int x;
    while(1) {
        cout << "Enter integer numbers\n";
        cin >> x;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            print("Error, try again!");
            continue;
        }
        if(cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            print("Error, try again!");
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return x;
    }
}
