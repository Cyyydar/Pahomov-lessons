#include <iostream>
#include <limits>

using namespace std;

void createMatrix(int**&, int&, int&);
void deleteMatrix(int**&, int&, int&);
void shiftMatrix(int*const*const, const int, const int);
void showMas(const int*const*const Matrix, const int N, const int K);

int get_size(const int maxSize, const string s);
short get_int(int&a);
void fullCleanCin();
void partialCleaningCin();
void getMatrix(int*const*const Matrix, const int N, const int K);

int main()
{
    int** Matrix = nullptr;
    int N = 0;
    int K = 0;

    createMatrix(Matrix, N, K);
    showMas(Matrix, N, K);
    shiftMatrix(Matrix, N, K);
    showMas(Matrix, N, K);

    deleteMatrix(Matrix, N, K);
    return 0;
}

void deleteMatrix(int**&Matrix, int&N, int&K) {
    if( Matrix != nullptr) {
        for(int i = 0; i < N; i++) {
            delete[]Matrix[i];
        }
        delete[]Matrix;
        Matrix = nullptr;
        N=0;
        K=0;
    }
}

void createMatrix(int**&Matrix, int&N, int&K) {
    deleteMatrix(Matrix,N,K);
    const string REQUEST_N {"Введите количество строк матрицы"};
    const string REQUEST_K {"Введите количество столбцов матрицы"};
    const int MAX_N {15};
    const int MAX_K {15};

    N = get_size(MAX_N, REQUEST_N);
    K = get_size(MAX_K, REQUEST_K);
    Matrix = new int*[N];
    for(int i = 0; i < N; i++){
        Matrix[i] = new int[K];
    }
    getMatrix(Matrix, N, K);
}

int get_size(const int maxSize, const string s) {
    const int minSize = 1;
    short flag_get_int;
    int a;
    cout << s;
    cout << "(от " << minSize << " до " << maxSize << "):";
    while(true) {
        flag_get_int = get_int(a);
        fullCleanCin();
        if(flag_get_int == 0) {
            if(a < minSize || a > maxSize) {
                cout << "Число не входит в диапозон от" << minSize << " до " << maxSize << endl;
                continue;
            }
            return a;
        }
        if(flag_get_int == 3) {
            cout << " Число слишком большое для int.";
            cout << "\n Введите заново:";
            continue;
        }
        if(flag_get_int == 1) {
            cout << " Символы не удалось преобразовать в целые числа (много для одного целого числа).\n Введите заново:";
            continue;
        }
        cout << " Символы не удалось преобразовать в целые числа (много для одного целого числа).\n Введите заново:";
    }
}

short get_int(int&a) {
    cin >> a;
    if(cin.fail()){
        cin.clear();
        if(a == numeric_limits<int>::max() || a == numeric_limits<int>::min()){
            partialCleaningCin();
            return 3;
        }
        partialCleaningCin();
        return 2;
    }
    if(cin.peek() != ' ' && cin.peek() != '\n') {
        a = 0;
        partialCleaningCin();
        return 2;
    }
    partialCleaningCin();
    if(cin.peek() != '\n') {
        return 1;
    }
    return 0;
}

void fullCleanCin() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void partialCleaningCin() {
    while(cin.peek() != ' ' && cin.peek() != '\n') {
        cin.ignore(1);
    }
}

void shiftMatrix(int*const*const Matrix, const int N, const int K) {
    for(int i = 0; i < K; i++){
        cout << i << endl;
    }
}

void showMas(const int*const*const Matrix, const int N, const int K) {
    if(Matrix == nullptr) {
        cout << "Массив не был создан\n";
        return;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cout << "\t" << Matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void getMatrix(int*const*const Matrix, const int N, const int K) {
    int*stroka_N = new int[N];
    bool errorGet = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cin >> stroka_N[j];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Неверный ввод" << j+1 << "-го числа в строке. Введите всю строку заново:\n";
                errorGet = true;
                break;
            }
        }
        if(errorGet) {
            i--;
            errorGet = false;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for(int j = 0; j < K; j++) {
            Matrix[i][j] = stroka_N[j];
        }
    }
    delete[]stroka_N;
}
