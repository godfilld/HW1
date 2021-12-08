#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


void print(FILE *file, int** g, int n) {
    bool b = 0;
    fprintf(file, "graph table {\n");

    for (int i = 0; i < n; i++) {
        b = 1;
        for (int j = 0; j <= i; j++)
        if (g[i][j] > 0) {
            b = 0;
            for (int k = 0; k < g[i][j]; k++)
                fprintf(file, "%d -- %d;\n", i, j);
        }
        if (b) fprintf(file, "%d\n", i);
    }

    fprintf(file, "}");
}

void print_array(int **ar, int apex) {
    for (int v = 0; v < apex; v++) {
        for (int p = 0; p < apex; p++) {
            printf("%d ",ar[v][p]);
        }
        printf("\n");
    }
}

int main(void) {
       
    FILE *fp1 = fopen("open.txt", "r");
    if (!fp1) {
        printf("%s\n", "Файл не был открыт open.txt, создайте файл или проверьте название");
        return 2;
    }

    int apex = 1;
    char c;
    while ((c = fgetc(fp1))!='\n') {
        if (c ==' ') {
            apex++;
        }  
    }

    rewind(fp1);

    int **ar = (int**)malloc((apex)*sizeof(int*));
    int i = 0, j = 0;

    for (int k = 0; k < apex; k++) {
        ar[k] = (int*)malloc((apex)*sizeof(int));
    }

    while (j < apex) {
        while (i < apex) {
            c = fgetc(fp1);
            if (isdigit(c)) {
                if ((c-'0') > 0) {
                    ar[j][i] = c-'0';
                    i++;
                }
                else {
                    ar[j][i] = 0;
                    i++;
                }
            } 
        }
        i = 0;
        j++;
    }
    
    fclose(fp1);
    FILE *fp3 = fopen("start.gv","w");

    print_array(ar, apex);
    print(fp3, ar, apex);
    fclose(fp3);
    system ("dot -Tpng start.gv -o kei.png");
    system ("wslview kei.png");

    
    int top = 0;
    printf("%s\n", "От какой вершины убрать рёбра?");
    while ((c = getchar()) !='\n') {
        top = c-'0' + top;
    }

    if (top > apex) {
        printf("%s\n", "Такой вершины не существует");
        return 1;
    }
    
    for (int v = 0; v < apex; v++) {
        ar[top][v] = 0;
        ar[v][top] = 0;
    }

    print_array(ar, apex);
    
    FILE *fp2 = fopen("graph.gv", "w");
    print(fp2, ar, apex);
    fclose(fp2);

    int *degree = (int*)malloc((apex)*sizeof(int));

    top = 0;
    int max = 0;
    for (int v = 0; v < apex; v++) {
        for (int p = 0; p < apex; p++) {
            if (ar[v][p]) {
                top+= ar[v][p];
            }
            if ((ar[v][p]) && (v == p)) {
                top++;
            }
            if (max < top) {
                max = top;
            }
            degree[v] = top;
        }
        top = 0;
    }

    printf("%s\n", "Вершины по степени(от большей к меньшей):");
    while (max != -1) {    
        for (int v = 0; v < apex; v++) {
            if (max == degree[v]) {
                printf("%d Степень - %d\n", v, degree[v]);
            }
        }
        max--;
    }
    
    free(ar);
    free(degree);
    system ("dot -Tpng graph.gv -o gr.png");
    system ("wslview gr.png");

    return 0;
}
