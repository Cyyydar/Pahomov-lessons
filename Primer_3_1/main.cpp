#include <iostream>

using namespace std;

int main()
{
    int k;
    int *M = nullptr;
    cout << " Введите размер массива (k>0): " << endl;
    cin >> k;
    M = new int[k]; //выделение динамической памяти
    cout << " Динамический массив: \n";

    for(int i=0; i<k; i++){
        cout << " " << M[i];
    }
    cout << "\n M=" << M << endl;


    for(int i=0; i<k; i++){
        M[i] = (-1)*i*(k-2*i);
    }

    cout << " Динамический массив: \n";

    for(int i=0; i<k; i++){
        cout << " " << M[i];
    }
    cout << "\n M=" << M << endl;

    delete[]M; //освобждение динамической памяти
    M = nullptr; //указывает на "ноль"

    return 0;
}
