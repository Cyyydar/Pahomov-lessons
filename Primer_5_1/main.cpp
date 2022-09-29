#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    string s1; //объявление строки
    s1 = "Pervaya stroka";
    string s2("Vtoraya stroka");
    string s3(5, 'x');
    string s4(s3);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

    cin >> s3; // считывает до пробела
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //очистка стандартного буфера ввода
    cout << s3 << endl;

    getline(cin,s4); // теперь можно считать но конца строки getline(откуда считываем, куда считваем)
    cout << s4;
    return 0;
}
