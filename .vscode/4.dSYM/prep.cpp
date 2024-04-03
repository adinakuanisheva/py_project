#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define lmax 200
int main() {
    setlocale(LC_ALL,"RUS");

    // Ввод имени файлов
    char input_name[lmax], output_name[lmax];
    FILE *input_file, *output_file;

    puts("Введите имя входного файла\n");
    fgets(input_name, lmax, stdin);
    // Изменение имён файлов
    input_name[strlen(input_name)-1] = '\0';
    strcat(input_name, ".rtf");
    input_file = fopen(input_name, "r");
    if(input_file==NULL)
    {
        printf("Нет файла с указанным именем!\n");
        return 0;
    }

    printf("Введите имя выходного файла\n");
    fgets(output_name, lmax, stdin);
    output_name[strlen(output_name)-1] = '\0';
    strcat(output_name, ".rtf");
    output_file = fopen(output_name, "w");

    printf("\n");

    int flag = -1;
    char string[lmax];
    char *s;
    while(!feof(input_file))
    {
        flag += 1;
        fgets(string, lmax, input_file);

        while (fgets(string, lmax, input_file)) {
        int length = strlen(string);
        for (int i = length -1; i >= 0; i--) {
            fputc(string[i], output_file);
            printf("%c", string[i]);
        }
        //fputc('\n', output_file);
        printf("\n");
    }
        fprintf(output_file, "%s", string);
    }
    if(!flag) printf("Входной файл оказался пустым!\n");
    else printf("Проверяйте файл с именем %s\n", output_name);
    fclose(input_file);
    fclose(output_file);

    return 0;

}



