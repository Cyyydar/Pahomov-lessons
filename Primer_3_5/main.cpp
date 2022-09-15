#include <iostream>

using namespace std;

int main()
{
    const int a = 3;
    int *pA;
    //pA = &a;
    const int *pB;

    pB = &a;
    // a = 5;
    // *pB = 5;
    pB = nullptr;

    return 0;
}
