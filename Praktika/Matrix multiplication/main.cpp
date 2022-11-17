#include <iostream>

using namespace std;

void createArr(int**& M, int K[]);
void showMass(int**& M, int K[]);
void matrixMultiplication(int**& M1, int**& M2, int K1[], int K2[]);

int** Result = nullptr;
int ResultSize[2];

int main()
{
    setlocale (LC_ALL, "Russian");
    int** Arr1 = nullptr;
    int Size1[2] = {0,0};
    int** Arr2 = nullptr;
    int Size2[2] = {0,0};

    createArr(Arr1,Size1);
    createArr(Arr2,Size2);
    if( Size1[1] != Size2[0]){
        cout << "������� ������ �����������\n";
        cout << "������ �������� ������ ������� �� ��������� � �������� ����� �� ������\n";
        return 0;
    }

    ResultSize[0] = Size1[0];
    ResultSize[1] = Size2[1];
    Result = new int*[ResultSize[0]];
    for(int i = 0; i < ResultSize[0]; i++) {
        Result[i] = new int[ResultSize[1]];
    }


    matrixMultiplication(Arr1,Arr2,Size1,Size2);
    return 0;
}

// ������������
void matrixMultiplication(int**& M1, int**& M2, int K1[], int K2[]){
    //����������� ������ ������� �������
    for (int i = 0; i < ResultSize[0]; i++){
        for(int j = 0; j < ResultSize[1]; j++){

            int sum = 0;
            for (int k = 0; k < K1[1]; k++)
                sum += M1[i][k] * M2[k][j];
            Result[i][j] = sum;
        }
    }

    showMass(Result,ResultSize);
}

// �������� � ���� ������
void createArr(int**&M, int K[2]) {
    delete[]M;
    cout << "������� ���-�� ����� �������\n";
    int a;
    //cin >> a;
    while(!(cin>>a) || cin.get() != '\n')
    {
        cout<<"IDIOT !! Enter again !\n";
        cin.clear(); // ���������� ��� ���� ������, ������ ����� ���������� "�������"
        cin.sync();//������ ������ �� �������
        cout<<"Enter int : ";
    }
    if(a < 1) {
        cout << "�������� ������\n";
        return;
    }


    K[0] = a;

    cout << "������� ���-�� �������� �������\n";
    cin >> a;
    if(a < 1) {
        cout << "�������� ������\n";
        return;
    }
    K[1] = a;

    M = new int*[K[0]];
    for(int i = 0; i < K[0]; i++) {
        M[i] = new int[K[1]];
    }

    cout << "������� " << K[0] * K[1] << " ����� ����� (�������)\n";
    for (int i = 0; i < K[0]; i++){
        for(int j = 0; j < K[1]; j++){
            cin >> M[i][j];
        }
    }
}

// �����
void showMass(int**& M, int K[]) {
    if(M == nullptr){
        cout << " ������� �� ��� ������\n";
        return;
    }
    cout << " �������: \n";
    for(int i = 0; i < K[0]; i++){
        for (int j = 0; j < K[1]; j++){
            cout << "\t" << M[i][j];
        }
     cout << endl;
    }
}

