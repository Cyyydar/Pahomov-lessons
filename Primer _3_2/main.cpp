#include <iostream>

using namespace std;

int main()
{
    int a;
    int&ra = a;
    cout << " a= " << a << endl;
    cout << " ra=" << ra << endl;
    a = 5;
    cout << " a= " << a << endl;
    cout << " ra=" << ra << endl;
    ra = 10;
    cout << " a= " << a << endl;
    cout << " ra=" << ra << endl;

    return 0;
}
