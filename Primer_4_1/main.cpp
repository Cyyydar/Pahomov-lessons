#include <iostream>

using namespace std;

int main()
{
    int** Mas = nullptr;
    int N = 0;
    int K = 0;

    cout << "Введите количество строк и столбцов:\n";
    cin >> N >> K;

    Mas = new int*[N];
    for(int i = 0; i < N; i++) {
        Mas[i] = new int[K];
    }

    cout << " Mas=" << Mas << endl << endl;
    for(int i = 0; i<N; i++) {
        cout << " Mas[" << i << "] =" << Mas[i] << endl;
    }
    cout << endl;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j < K; j++){
            cout << "\t" << Mas[i][j];
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j < K; j++){
            Mas[i][j] = (j+1)*100+i;
        }
    }


    for(int i = 0; i<N; i++) {
        for(int j = 0; j < K; j++){
            cout << "\t" << Mas[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // освобождение памяти

    for(int i = 0; i < N; i++) {
        delete[]Mas[i];
    }
    delete[]Mas;
    Mas = nullptr;

    return 0;
}
