# Некоторые программы для успешной сдачи экзамена по программирования на языках высокого уровня (C++)

 ### Программы и шпаргалки:

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
	#include <fstream> // чтобы использовать файловый вывод нужно подключить это

	ifstream input("input.txt"); // открываем файл ввода
		
    input >> Size; // достаем из файла числа аналогично cin

    input.close(); // закрываем файл
		
		
		
    ofstream output("output.txt"); // открываем файл вывода
	
    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            output << M[i][j] * 2 << " "; // печатаем числа в файл аналогично cout
        }
        output << endl;
    }

    output.close();
	```
