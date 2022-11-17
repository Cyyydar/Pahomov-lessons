#include <iostream>

using namespace std;
/*
Краткое описание алгоритма:
    * Переводим матрицу в строку
    * Заполняем массив разниц между элементами
    * Сортируем его
    * Вынимаем оттуда 4 пары чисел из начала, но так, чтобы они не повторялись
    * Раскидываем их по разным группам так, чтобы разницы не накладывались, а компенсировали друг друга
    * Записываем обратно в матрицу
*/


int matrix[5][5] = {{6,7,8,9,10},
                    {21,24,25,22,23},
                    {1,2,3,4,5},
                    {16,17,18,19,20},
                    {11,12,13,14,15}}; //< Изначальная матрица
int outMatrix[5][5]; //< Выходная матрица
int inLineMatrix[25]; //< Строка, образованная из матрицы
int diffArray[25][3]; //< Массив разниц
int diff; //< Минимальная разница между диагоналями
int first[4]; //< Основная диагональ
int second[4]; //< Побочная диагональ


void print(int (*m)[5]);
void matrixInLine();
void findDif();
void twoGroups();
void fillMatrix();

int main() {
    print(matrix);
    matrixInLine();
    findDif();
    twoGroups();
    fillMatrix();
    cout << endl;
    print(outMatrix);


    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < 4; i++){
        sum1 += inLineMatrix[first[i]];
        sum2 += inLineMatrix[second[i]];
    }

    cout << outMatrix[0][0] << " " << outMatrix[1][1] << " " << outMatrix[2][2] << " " << outMatrix[3][3] << " " << outMatrix[4][4] << " = " << sum1 + outMatrix[2][2] << endl;
    cout << outMatrix[4][0] << " " << outMatrix[3][1] << " " << outMatrix[2][2] << " " << outMatrix[1][3] << " " << outMatrix[0][4] << " = " << sum2 + outMatrix[2][2] << endl;
    cout << "difference = " << diff << endl;



    return 0;
}
/**
 * Заполняем матрицу обратно
 */
void fillMatrix(){
    int lineindx = 0;
    int diagindx = 0;
    bool inc = true;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if (!(i == j || i + j == 4 )|| i == 2) {
                while(1) {
                    for(int k = 0; k < 4; k++) {
                        if(first[k] ==  lineindx || second[k] == lineindx){
                            inc = true;
                            lineindx++;
                            break;
                        } else {
                            inc = false;
                        }
                    }
                    if(!inc){
                        break;
                    }

                }
                outMatrix[i][j] = inLineMatrix[lineindx];
                lineindx++;
                inc = true;
            } else {
                if (i == j) {
                    outMatrix[i][j] = inLineMatrix[first[diagindx%4]];
                } else if (i + j == 4) {
                    outMatrix[i][j] = inLineMatrix[second[diagindx%4]];
                }
                diagindx++;
            }
        }
    }
}

/**
 * Распределяем
 */
void twoGroups(){
    int sum1 = 0, sum2 = 0;
    int include[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    int inclindx = 0;
    bool inc = true;

    // пока обе группы не заполнятся мы будем идти по массиву разниц
    for(int i = 0; inclindx < 4; i++){
        // Проверяем на повторы
        for(int j = 0; j < 8; j++) {
            if(include[j] == diffArray[i][1] || include[j] == diffArray[i][2]){
                inc = false;
                break;
            }
        }
        // если повторов не было, то раскидываем по нужным группам
        if (inc){
            include[inclindx] = diffArray[i][1];
            include[inclindx+4] = diffArray[i][2];
            // раскидываем так, чтобы разницы компенсировали друг друга
            if(inLineMatrix[diffArray[i][1]] > inLineMatrix[diffArray[i][2]]) {
                if(sum1 > sum2) {
                    first[inclindx] = diffArray[i][2];
                    second[inclindx] = diffArray[i][1];
                } else {
                    first[inclindx] = diffArray[i][1];
                    second[inclindx] = diffArray[i][2];
                }
            } else {
                if(sum1 > sum2 ) {
                    first[inclindx] = diffArray[i][2];
                    second[inclindx] = diffArray[i][1];
                } else {
                    first[inclindx] = diffArray[i][1];
                    second[inclindx] = diffArray[i][2];
                }
            }
            sum1 += first[inclindx];
            sum2 += second[inclindx];
            inclindx++;
        }
        inc = true;
    }
    diff = abs(sum1 - sum2);
    /*for(int i = 0; i < 4; i++) {
        cout << first[i] << " " << second[i] <<endl;
    }*/
}

/**
 * Находит минимальную разницу для элементов
 */
void findDif() {
    int min = -1;
    int minindx = -1;
    int myindx = -1;
    // находим и записываем минимальную разницу
    for(int i = 0; i < 25; i++){
        for (int j = 0; j < 25; j++){
            if((abs(inLineMatrix[i] - inLineMatrix[j]) < min || min == -1 ) && i != j) {
                min = abs(inLineMatrix[i] - inLineMatrix[j]);
                myindx = i;
                minindx = j;
            }
            if(min == 0){
                break;
            }
        }
        diffArray[i][0] = min;
        diffArray[i][1] = minindx;
        diffArray[i][2] = myindx;
        min = -1;
    }

    //Сортируем матрицу
    for(int i = 0; i < 24; i++){
        for(int j = i+1; j < 25; j++){
            if(diffArray[j-1][0] > diffArray[j][0]){
                int Temp = diffArray[j][0];
                int Temp1 = diffArray[j][1];
                int Temp2 = diffArray[j][2];
                diffArray[j][0] = diffArray[j-1][0];
                diffArray[j][1] = diffArray[j-1][1];
                diffArray[j][2] = diffArray[j-1][2];
                diffArray[j-1][0] = Temp;
                diffArray[j-1][1] = Temp1;
                diffArray[j-1][2] = Temp2;
            }
        }
    }
}

/**
 * Вытягивает матрицу изначальную в строку
 */
void matrixInLine() {
    int indx = 0;
    for(int i = 0; i < 5; i++){
        for (int j = 0;j < 5 ;j++){
            inLineMatrix[indx] = matrix[i][j];
            indx++;
        }
    }
}


/**
 * Вывод матрицы на экран
 */
void print(int (*m)[5]) {
    for(int i = 0; i < 5; i++){
        for (int j = 0;j < 5 ;j++){
                cout << '\t' << m[i][j];
        }
    cout << "\n";
    }
}
