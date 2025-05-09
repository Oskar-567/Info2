#include <stdio.h>

void printMatrix(int x, int y, int M[y][x]) {
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            printf("%d ", M[j][i]);
        }
        printf("\n");
    }
}

int min4(int a, int b, int c, int d){
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}


void biggestPlus(int x, int y, int M[y][x]) {
    //, int top[x][y], int bottom[x][y], int left[x][y], int right [x][y]) {
    int top[y][x];
    for (int i = 0; i < x; i++)
    {
        top[0][i] = M[0][i];
    }
    for (int j = 1; j < y; j++) {
        for (int i = 0; i < x; i++) {
            if (M[j][i] == 0) {
                top[j][i] = 0;
            }
            else {
                top[j][i] = top[j - 1][i] + 1;
            }
        }
    }
    printf("Top Matrix \n");
    printMatrix(x,y, top);



    int bottom[y][x];
    for (int i = 0; i < x; i++)
    {
        bottom[y-1][i] = M[y-1][i];
    }
    for (int j = y-2; j >= 0; j--) {
        for (int i = 0; i < x; i++) {
            if (M[j][i] == 0) {
                bottom[j][i] = 0;
            }
            else {
                bottom[j][i] = bottom[j + 1][i] + 1;
            }
        }
    }
    printf("\nBottom Matrix \n");
    printMatrix(x,y, bottom);

    int left[y][x];
    for (int j = 0; j < y; j++)
    {
        left[j][0] = M[j][0];
    }
    for (int j = 0; j < y; j++) {
        for (int i = 1; i < x; i++) {
            if (M[j][i] == 0) {
                left[j][i] = 0;
            }
            else {
                left[j][i] = left[j][i - 1] + 1;
            }
        }
    }
    printf("\nLeft Matrix \n");
    printMatrix(x,y, left);

    int right[y][x];
    for (int j = 0; j < y; j++)
    {
        right[j][x - 1] = M[j][x - 1];
    }
    for (int j = 0; j < y; j++) {
        for (int i = x - 2; i >= 0; i--) {
            if (M[j][i] == 0) {
                right[j][i] = 0;
            }
            else {
                right[j][i] = right[j][i + 1] + 1;
            }
        }
    }
    printf("\nRight Matrix \n");
    printMatrix(x,y, right);


    int solution[y][x];
    int resulty = 0;
    int resultx = 0;
    int solutiontemp = 0;
    for (int j = 0; j < y; j++) {
        for (int i = 0 ; i < x; i++) {
            solution[j][i] = top[j][i] + bottom[j][i] + left[j][i]+ right[j][i];
            if (solution[j][i] > solutiontemp) {resultx = i; resulty = j; solutiontemp = solution[j][i];}
        }
    }

    printf("\nSolution Matrix \n");
    printMatrix(x,y, solution);

    //print area
    int result = min4(top[resulty][resultx], bottom[resulty][resultx], left[resulty][resultx], right[resulty][resultx]);
    printf("\nDie Area des Plus ist: %d", (result-1)*4 +1);

}




int main() {
    int m = 5;      //Zeilen -> y
    int n = 6;      //Spalten -> x
    int M[5][6] = { {0, 0, 0, 1, 0, 0},
                    {0, 1, 0, 1, 0, 0},
                    {1, 1, 1, 1, 1, 1},
                    {1, 1, 0, 1, 0, 1},
                    {1, 0, 0, 1, 1, 0}, };

    biggestPlus(n,m,M);




}