# Некоторые программы для успешной сдачи экзамена по программирования на языках высокого уровня (C++)

 ### Список программ:

* **Secure input**: Безопасный ввод, который принимает от пользователя только корректные данные

	```C++
	double getDouble() {
		double x;
		while(true) {
	
		cin >> x; // пытаемся ввести данные

		if(cin.fail()) { // если если ошибка ввода, то сообщаем об этом
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, try again\n";
			continue; // и пробуем еще раз
		}
		if(cin.peek()!='\n') { // если в буфере осталось что-то, выдаем ошибку
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера
			cout << "Error, try again\n";
			continue;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return x; // возвращаем число
    }

	```

* **Files**: Работа с файлами

	```C++
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
	```
