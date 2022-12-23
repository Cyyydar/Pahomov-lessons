#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream input("input.txt"); //открываем файл ввода
	int** M = nullptr;
    int Size;

    input >> Size; // достаем первое число - размер матрицы

    M = new int*[Size];
    for (int i = 0;i < Size;i++){
        M[i] = new int[Size];
    }

    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            input >> M[i][j]; // достаем все остальные числа
        }
    }
    input.close(); // закрываем файл

    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    ofstream output("output.txt"); //открываем файл вывода

    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            output << M[i][j] * 2 << " "; // печатаем числа в файл
        }
        output << endl;
    }

    output.close();
}
