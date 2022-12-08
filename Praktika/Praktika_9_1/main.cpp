#include <iostream>
#include <limits>

using namespace std;

int createArray(int*& arr);
int safeEnter();
void fillArray(int* arr, int sizeArr);

void findTriple(int* arr, int sizeArr);
void deleteArray(int* arr);

int main()
{
    while(1) {
        int* arr = nullptr;
        int arrSize = createArray(arr);
        fillArray(arr, arrSize);
        findTriple(arr, arrSize);
        cout << "\n";
    }
    return 0;
}

int createArray(int*& arr) {
    cout << "Задайте размер массива:\n\n";
    int N = safeEnter();
    while(N <= 0) {
        cout << "Введите число больше нуля\n";
        N = safeEnter();
    }
    arr = new int[N];
    return N;
}

void fillArray(int* arr, int sizeArr) {
    while (1) {
        cout << "Заполните массив числами:\n\n";
        for(int i = 0; i < sizeArr; i++){
            int x = safeEnter();
            if (x == NULL) {
                continue;
            }
            arr[i] = x;
        }
        break;
    }
}

pair<int,bool> safeEnter(){
    int num;
    //cout << " Введите целочесленное значение\n";
    cin >> num;
    if (cin.fail()) {
        cout << " Введено неверное значение\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return NULL;
    }
    return num;
}

void findTriple(int* arr,int arrSize) {
    int maxsum = 0;
    int maxindex = 0;
    for(int i = 2; i < arrSize; i++) {
        if(arr[i-2] + arr[i-1] + arr[i] > maxsum){
            maxsum = arr[i-2] + arr[i-1] + arr[i];
            maxindex = i;
        }
    }

    cout << "Максимальная тройка:\n";
    cout << arr[maxindex - 2] << " " << arr[maxindex - 1] << " " << arr[maxindex] << " ";
    cout << "Сумма " << maxsum << endl;
}

/*
    1 создание массива
    2 поиск max тройки
    3 удаление массива

    _._ Безопасный ввод
    1.1 запрос размера
    1.2 заполнение массива

*/
