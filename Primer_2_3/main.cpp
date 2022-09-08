#include <iostream>

using namespace std;

const int COUNT_STROK{3};
const int COUNT_STOLB{4};
int Matrix[COUNT_STROK][COUNT_STOLB];


int main()
{
    for(int j = 0; j < COUNT_STROK; j++){
        for(int i = 0; i < COUNT_STOLB; i++) {
            Matrix[j][i] = i + 1 + COUNT_STOLB * j;
        }
    }

    for(int j = 0; j < COUNT_STROK; j++){
        for(int i = 0; i < COUNT_STOLB; i++) {
            cout << "/t"<< Matrix[j][i];
        }
        cout << endl;
    }
    return 0;
}
