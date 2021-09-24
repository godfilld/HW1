#include<stdio.h>

#include <ctype.h>

int main() {
    printf("Введите число с плавающей точкой(float) \n");
    char c;
    while ((c = getchar()) != '\n') {
        if (c == '.') {
            printf("|");
        } else if (!isdigit(c)) {
            printf("вводите числа, а не символы!\n");
            return 0;
        } else putchar(c);

    }
    printf("\n");
}
