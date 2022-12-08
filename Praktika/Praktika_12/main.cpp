#include <iostream>

using namespace std;

class dynamicArray {
    int Size = 0;
    int* Array = nullptr;
public:
    void createArray();
    void fillArray();
    void deleteArray();
    void printArray();
};


int main()
{
    dynamicArray DA;

    DA.printArray();
    DA.createArray();
    DA.printArray();
    DA.fillArray();
    DA.printArray();
    return 0;
}

void dynamicArray::createArray() {
    cout << "Введите размер массива: \n";
    cin >> Size;
    if (Array == nullptr) {
        Array = new int[Size];
        return;
    }
    cout << "Массив не был создан!\n\n";
}

void dynamicArray::deleteArray() {
    delete []Array;
}

void dynamicArray::printArray() {
    if (Array == nullptr) {
        cout << "Массив не был создан\n\n";
        return;
    }
    cout << "Массив:\n";
    for(int i = 0; i < Size; i ++) {
        cout << Array[i] << " ";
    }
    cout << endl << endl;
}

void dynamicArray::fillArray() {
    if(Array == nullptr) {
        cout << "Массив не был создан\n\n";
        return;
    }
    cout << "Заполните массив размера " << Size << endl;
    for(int i = 0; i < Size; i++) {
        cin >> Array[i];
    }
}
