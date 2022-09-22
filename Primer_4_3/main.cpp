#include <iostream>

using namespace std;

void create_Mass(int*&M, int&K);
void show_Mass(const int * const M, const int K);

int main()
{
    int *Mass = nullptr;
    int Razmer_Mass = 0;
    show_Mass(Mass, Razmer_Mass);
    create_Mass(Mass, Razmer_Mass);
    show_Mass(Mass, Razmer_Mass);


    delete[]Mass;
    return 0;
}

void create_Mass(int*&M, int&K) {
    delete[]M;
    cout << "Введите длину массива\n";
    int a;
    cin >> a;
    if(a < 1) {
        cout << "Неверный размер\n";
        return;
    }

    K = a;
    M = new int[K];

    cout << "Введите " << K << " целых чисел\n";
    for(int i = 0; i < K; i++){
        cin >> M[i];
    }
}

void show_Mass(const int * const M, const int K) {
    if(M == nullptr){
        cout << " Массив не был создан\n";
        return;
    }
    cout << " Массив: \n";
    for(int i = 0; i < K; i++){
        cout << " " << M[i];
    }
     cout << endl;
}
