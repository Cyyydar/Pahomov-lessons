#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream input("input.txt"); //��������� ���� �����
	int** M = nullptr;
    int Size;

    input >> Size; // ������� ������ ����� - ������ �������

    M = new int*[Size];
    for (int i = 0;i < Size;i++){
        M[i] = new int[Size];
    }

    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            input >> M[i][j]; // ������� ��� ��������� �����
        }
    }
    input.close(); // ��������� ����

    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    ofstream output("output.txt"); //��������� ���� ������

    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            output << M[i][j] * 2 << " "; // �������� ����� � ����
        }
        output << endl;
    }

    output.close();
}
