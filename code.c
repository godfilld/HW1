#include <stdio.h>
#include <ctype.h>

int main(void) {
    printf("Введите число с плавающей точкой(float) \n");
    char c;
    while ((c = getchar()) != '\n') {
        if (c == '.') {
            printf("|");
        } else if (!isdigit(c)) {
            printf("вводите числа, а не символы!\n");
            return -5;
        } else {
            putchar(c);
        }
    }
    printf("\n");
}