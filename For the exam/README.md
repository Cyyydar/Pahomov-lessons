# Некоторые программы для успешной сдачи экзамена по программирования на языках высокого уровня (C++)
[![Donate](https://static.goodgame.ru/files/logotypes/ch_123719_yM3Y.jpg "Пожертвования")](https://www.tinkoff.ru/collectmoney/crowd/nepakharev.aleksey1/yNycm59514/?short_link=1FPWhkyr38D&httpMethod=GET)
 ### Программы и шпаргалки:

* **Secure input**: Безопасный ввод, который принимает от пользователя только корректные данные

	```C++
	#include <limits>
	
	...
	
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
		
	```	
	
	```C++
    ofstream output("output.txt"); // открываем файл вывода
	
    for (int i = 0;i < Size; i++){
        for (int j = 0; j < Size; j++){
            output << M[i][j] * 2 << " "; // печатаем числа в файл аналогично cout
        }
        output << endl;
    }

    output.close();
	```
* **Динамические массивы**:   
	Чтобы создать динамический массив, нужно создать указатель (двойной, если это двумерный массив)
	```C++
	int** Matrix = nullptr;
	```
	Чтобы передать массив в функцию нужно использовать **& или *& (в зависимости от размерности массива)
	```C++
	printMatrix(int**& M, int S){
		...
	}
	```
* **Структуры**:
	Чтобы создать структуру используется следующий синтаксис:
	```c++
	struct student{
        string Name; // Поля структуры
        int age;
    ;
	```
	
	```c++
	student ArrayOfStudents[3];
    /*
        Массив студентов создается также, как и любой другой массив
        Указывается тип и размер массива
    */

    ArrayOfStudents[0].Name = "Ivan"; // Обращаться к полям можно через точку

    cout << ArrayOfStudents[0].Name << endl;

    student* A = nullptr; // Также можно создавать ссылки на структуры

    A = new student[4]; // Таким образом обеспечив создание динамических массивов

    for(int i = 0; i < 4; i++) {
        A[i].age = 18 + i;
    }

    for(int i = 0; i < 4; i++) {
        cout << A[i].age << " ";
    }
    ```
	
	
