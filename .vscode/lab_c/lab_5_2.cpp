#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lmax 100

int main() {
    char inputFile[lmax], outputFile[lmax], str[lmax];
    FILE *in, *out;

    printf("Введите имя входного файла: ");
    scanf("%s", inputFile);

    printf("Введите имя выходного файла: ");
    scanf("%s", outputFile);

    in = fopen(inputFile, "r");
    if (in == NULL) {
        printf("Ошибка открытия входного файла.");
        return 1;
    }

    out = fopen(outputFile, "w");
    if (out == NULL) {
        printf("Ошибка открытия выходного файла.");
        fclose(in);
        return 1;
    }

    while (fgets(str, lmax, in) != NULL) {
        int len = strlen(str);
        for (int i = len - 1; i >= 0; i--) {
            fputc(str[i], out);
        }
        fputs("\n", out);
    }

    fclose(in);
    fclose(out);

    out = fopen(outputFile, "r");
    if (out == NULL) {
        printf("Ошибка открытия выходного файла для чтения.");
        return 1;
    }

    printf("Содержимое нового файла:\n");
    while (fgets(str, lmax, out) != NULL) {
        printf("%s", str);
    }

    fclose(out);

    return 0;
}

