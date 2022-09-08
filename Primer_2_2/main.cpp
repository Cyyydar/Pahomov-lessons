#include <iostream>

using namespace std;

const int RAZMER_MASSIVA {6}; //могут быть и круглые и равно и все вообще юниформ какой-то
int Mass[RAZMER_MASSIVA];

int main()
{ //ввод, сортировка по возрастанию и вывод массива
    cout << " Enter " << RAZMER_MASSIVA << " integer numbers "; // вывод
    for( int i = 0; i < RAZMER_MASSIVA; i++) {
        cin >> Mass[i]; //вводя
    }

    for(int j = 0; j<RAZMER_MASSIVA-1; j++){
        for(int i=0; i<RAZMER_MASSIVA-j-1; i++){
            if(Mass[i] > Mass[i+1]){
                int temp = Mass[i];
                Mass[i] = Mass[i+1];
                Mass[i+1] = temp;
            }
        }
    }

    cout << "Rezultat sortirovki po vozrastaniu\n";
    for(int i = 0; i < RAZMER_MASSIVA; i++) {
        cout << " " << Mass[i];
    }

    return 0;
}
