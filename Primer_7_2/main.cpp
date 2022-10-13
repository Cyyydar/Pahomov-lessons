#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // ifstream используется для чтения содержимого файла.
    // Попытаемся прочитать содержимое файла Text.txt
    ifstream inf("Text.txt");

    // Если мы не можем открыть этот файл для чтения его содрежимого,
    if (!inf) {
        // то выводим сообщение об ошибке и выходим
        cout << " Text.txt не открылся!" << endl;
        return 1;
    }

    // Пока есть данные, которые можем прочитать,
    while(inf){
        // то перемещаем эти данные в строку,
        // которую затем выводим на экран
        string strInput;
        inf >> strInput;
        cout << strInput << endl;
    }

    return 0;

    // Когда outf выйдет из области видимости,
    // то деструктор класса ofstream автоматически закроет файл
}
