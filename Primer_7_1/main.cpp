#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Класс ofstream, используется для записи данных в файл.
    // Создаем файл Text.txt
    ofstream outf("Text.txt");

    // Если мы не можем открыть этот файл для записи данных,
    if (!outf) {
        // то выводим сообщение об ошибке и выходим
        cout << " Text.txt не открылся!" << endl;
        return 1;
    }

    // Записываем в файл существующие две строки
    outf << "Строка 1" << endl;
    outf << "Строка 2" << endl;

    return 0;

    // Когда outf выйдет из области видимости,
    // то деструктор класса ofstream автоматически закроет файл
}
