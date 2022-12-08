#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//void input();
//void sortm();
//void output();

int main()
{
    ifstream inf("InputMatrix.txt");

    if (!inf) {
        cout << " InputMatrix.txt не открылся!" << endl;
        return 1;
    }

    ifstream countf("InputMatrix.txt");

    if (!countf) {
        cout << " InputMatrix.txt не открылся!" << endl;
        return 1;
    }

    ofstream outf("SortedMatrix.txt");

    if (!outf) {
        cout << " SortedMatrix.txt не открылся!" << endl;
        return 1;
    }

    int N = -1;
    int _;
    while(countf) {
        countf >> _;
        N++;
    }

    N = sqrt(N);

    /* define */
    int matrix[N][N], x, y, sort[N*N], sortedm[N][N];

    /*center*/
    if(N%2 == 0){
        x = N/2+1;
        y = N/2;
    }else{
        x = N/2;
        y = x;
    }

    /* input */
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            inf >> matrix[i][j];
        }
    }


    /* Matrix to array*/
    int idx = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sort[idx] = matrix[i][j];
            idx++;
        }
    }

    /* Sorting array*/
    for(int i = N*N; i > 0; i--){
        for(int j = 1; j < i; j++){
            if(sort[j - 1] > sort[j]){
                int temp = sort[j - 1];
                sort[j - 1] = sort[j];
                sort[j] = temp;
            }
        }
    }

    /* Sorted array to matrix */
    int step = 1, flag = 0;
    idx = 0;
    for(int k = 0; k < N*N; k++){
        /* down */
        for(int i = 0; i < step; i++){
            sortedm[y][x] = sort[idx];
            cout << sort[idx] << " " << step << " ";
            idx++;
            y++;
            if((x == N - 1 && y == N - 1) && N % 2 != 0 || (x == 0 && y == 0) && N % 2 == 0)
                flag = 1;
        }
        if(flag == 1)
            break;
        /* left */
        for(int i = 0; i < step; i++){
            sortedm[y][x] = sort[idx];
            idx++;
            x--;
            if((x == N - 1 && y == N - 1) && N % 2 != 0 || (x == 0 && y == 0) && N % 2 == 0)
                flag = 1;;
        }
        step++;
        /* up */
        for(int i = 0; i < step; i++){
            sortedm[y][x] = sort[idx];
            idx++;
            y--;
            if((x == N - 1 && y == N - 1) && N % 2 != 0 || (x == 0 && y == 0) && N % 2 == 0)
                flag = 1;
        }
        if(flag == 1)
            break;
        /* right */
        for(int i = 0; i < step; i++){
            sortedm[y][x] = sort[idx];
            idx++;
            x++;
            if((x == N - 1 && y == N - 1) && N % 2 != 0 || (x == 0 && y == 0) && N % 2 == 0)
                flag = 1;
        }
        step++;
    }

    /* Sorted matrix output*/
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            outf << "\t" << sortedm[i][j];
        }
        outf << endl;
    }
    return 0;
}
