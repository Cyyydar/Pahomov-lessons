#include <iostream>
#include <limits>
#include <stdlib.h>

using namespace std;

int getInt();

int main()
{
    int x = 0;
    x = getInt();
    return 0;
}

int getInt(){
    string temp;
    int x;
    cout << "Введите целочисленное значение:\n";
    while(1){
        cin >> temp;
        try {
        if(stoi(temp)) {
            x = stoi(temp);
            break;
        }
        } catch(std::out_of_range) {
            cout << "Слишком большое число\n";
            cout << "Попробуйте еще раз:\n";
            continue;
        } catch(std::invalid_argument) {
            cout << "Можно вводить только числа\n";
            cout << "Попробуйте еще раз:\n";
        }
        //cout << "Ошибка: неверное значение\n";
        //cout << "Попробуйте еще раз\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout << "Введенное число:" << x;

    return x;
}
