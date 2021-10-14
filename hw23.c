#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * f = fopen("graph.gv", "w");
    int row, col;
    int i, j, m = 1;
    printf("Ввелите количество стобцов матрицы: ");
    scanf("%d", & row);
    printf("Введите количество строк матрицы: ");
    scanf("%d", & col);
    int a[row][col];
    printf("Введите данные матрицы\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            scanf("%d", & a[i][j]);
        }
    }
    fprintf(f, "graph {\n");
    for (j = 0; j < col; ++j) {
        for (i = 0; i < row; ++i) {
            if (a[i][j] == 1) {
                if (m % 2 != 0) {
                    fprintf(f, "%d", i + 1);
                    fprintf(f, "--");
                    m++;
                } else {
                    fprintf(f, "%d\n", i + 1);
                    m++;
                }
            }
        }
    }
    fprintf(f, "}");
    fclose(f);

    system("dot -Tpng graph.gv -o '2.png'");
    system("wslview 2.png");
    return 0;
}
