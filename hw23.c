#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE * f = fopen("graph.gv", "w");
    int row, col;
    int i, j, m = 0;
    int sum = 1;
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
                if (m % 2 == 0) {
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
    int* flag = (int*)malloc(col * sizeof(int));
	flag[0] = 1;
	for (int i = 1; i < col; i++)
		flag[i] = 0;
	for (int i = 0; i < col; i++){

		if (flag[i] == 1){
			for (int j = 0; j < col; j++){
				if (flag[j] != 1){

					for (int m = 0; m < row; m++){
					if ((a[i][m] == 1) && (a[j][m] == 1)){
					flag[j] = 1;
					sum++;
					break;
					}
				}
			}
		}
	}
 }
	if (sum == col)
		printf("Введенный граф связанный\n");
	else printf("Введенный граф не связанный");

    system("dot -Tpng graph.gv -o '2.png'");
    system("wslview 2.png");
    return 0;
}
