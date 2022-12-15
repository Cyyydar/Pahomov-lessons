#include <iostream>
#include <limits>

using namespace std;

double getDouble();

int main()
{
    double x;
    x = getDouble();

    cout << x;
    return 0;
}

double getDouble() {
    double x;
    while(true) {

        cin >> x;

        if(cin.fail()) { // если если ошибка ввода, то сообщаем об этом
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error, try again\n";
            continue;
        }
        if(cin.peek()!='\n') { // если в буфере осталось что-то, выдаем ошибку
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера
            cout << "Error, try again\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return x;
    }
}
