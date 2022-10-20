#include <iostream>
#include <limits>

using namespace std;

double getDouble();
char getOperator();
void printResult(double x, char operation, double y);

int main()
{
    double x, y;
    char operation;

    x = getDouble();
    operation = getOperator();
    y = getDouble();

    printResult(x, operation, y);
    return 0;
}

double getDouble(){
    double x;
    while (true) {  // Цикл, пока пользователь
                    // не введет допустимые даанные
        cout << "Enter a double value: ";
        cin >> x;
        // Проверяем на неудачное извлечение
        if(cin.fail()) { // предыдущее извлечение не удалось?
            // да, давайте разберемся с ошибкой
            cin.clear(); // возвращаем программу в "нормальный" режим работы

            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                // и удаляем неверные входные данные
            cout << "Error, that input is invalid. Please try again.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                // удаляем любые посторонние входные данные
                // пользователь не может ввести бессмысленное значение double
                // поэтому не нужно предусматривать его проверку
            return x;
        }
    }
}

char getOperator() {

    while(true) { // Цикл, пока пользователь не введет допустимые даннные
    cout << "Enter one of the following:";
    cout << "+, -, *, /\n";
    char operation;
    cin >> operation;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // Проверяем, ввел ли пользователь
    // осмысленные данные

    switch(operation){
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;   // возвращаем символ
                                // вызывающей функции
        default:    // в противном случае сообщим
                    // пользователю, что пошло не так
            cout << "Error, that input is invalid.";
            cout << " Please try again.\n";
        }
    } //  и пробуем еще раз
}

void printResult(double x, char operation, double y){
    switch (operation) {
        case '+':
            cout << x << " + " << y << " = " << x + y;
            break;
        case '-':
            cout << x << " - " << y << " = " << x - y;
            break;
        case '*':
            cout << x << " * " << y << " = " << x * y;
            break;
        case '/':
            cout << x << " / " << y << " = " << x / y;
            break;
        default:    // Надежность означает также обработку неожиданных параметров,
                    // даже если getOperator() гарантирует, что ор
                    // в этой конкретной программе коректн
            cout << "Something went wrong: printResult()";
            cout << " got an invalid operator. \n";
    }
}
