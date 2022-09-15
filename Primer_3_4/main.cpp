#include <iostream>

using namespace std;

int main()
{
    const int a = 3;
    //int &rA = a;
    const int &rB = a;

    int b = 5;
    int &rD = b;
    const int &rC = b;

    return 0;
}
