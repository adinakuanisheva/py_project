#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("123.rtf", "r"); // открываем файл для чтения

    if (file == NULL) {
        printf("Ошибка при открытии файла");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) { // считываем файл построчно
        for (int i = 0; line[i] != '\0'; i++) { // заменяем цифры на буквы
            if (line[i] >= '0' && line[i] <= '9') {
                line[i] = line[i] - '0' + 'A';
            }
        }
        printf("%s", line); // выводим измененную строку
    }

    fclose(file); // закрываем файл

    return 0;
}
