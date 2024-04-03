
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#define kmax 100
#define lmax 100

int f1(char a[kmax][lmax],char s[kmax][lmax], int k, int schet) {
    int i, o=0, j, h, p;
    schet=0; 
    printf("Задание 1\n");
    for(i=0; i<k; i++) {
        for (j=0; j<lmax; j++) {
            if(a[i][j]=='<') {
                s[o][schet]=a[i][j];
                schet+=1;
                for(h=j+1; h<lmax; h++) {
                    if(a[i][h]=='>') {
                        for(p=0;p<h-j-1; p++) {
                            s[o][p]=a[i][j+1+p];
                        }
                        if(h-j!=1) {
                            s[o][p]='\0';
                            o++;
                        }
                    }
                }
            }
        }
    }
    return o;
}

int f2(char s[kmax][lmax],int o) {
    int max_digits = -1,max_index = 0;
    printf("Задание 2\n");
    for (int i = 0; i < o; i++) {
        int digit_count = 0;
        for (int j = 0; j < lmax; j++) {
            if (isdigit(s[i][j])) {
                digit_count++;
            } else {
                break;
            }
        }
        if (digit_count > max_digits && digit_count != 0) {
            max_digits = digit_count;
            max_index = i;
        }
    }
    return max_index;
}

void f3(char s[kmax][lmax]) {
    int i,j=0;
    printf("Задание 3\n");

    /* Тут я должна проверять только ту строку, в которой содержится найденая в задании 2 подстрока
     * А я проверяю все
     */

    for (int i = 0; i < kmax; i++) {
        while (s[i][j] != '\0') {
            if (isdigit(s[i][j])) {
                char temp[lmax];
                strcpy(temp, &s[i][j+1]);  // копируем часть строки после первой цифры
                s[i][j+1] = '.';  
                s[i][j+2] = '.';  
                s[i][j+3] = '.';  
                s[i][j+4] = '\0'; 
                strcat(s[i], temp);  // добавляем оставшуюся часть строки
                break;
            } else {
                j++;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    char a[kmax][lmax], s[kmax][lmax];
    int k, n, i, j, p, h, o, l, m, q, schet;
    printf("Лабораторная работа №4\n");
    printf("Введите количество строк не больше чем %d: ", kmax);
    do{
        n=scanf("%d", &k);
        if(k<=0||k>kmax) {
            printf("Неверный ввод данных, повторите попытку\n");
        } while(getchar()!='\n');
    } while (k<=0||k>kmax||n!=1);
    printf("Введите строки: \n");
    for(i=0; i<k; i++) {
        fgets(a[i], lmax, stdin);
    }
    l = f1(a, s, k,schet);
    if(l==0) {
        printf("Нет таких подстрок,все дальнейшие действия невозможны\n");
    } else {
    for(i=0; i<l; i++) {
        puts(s[i]);
    }
    }
    q=f2(s,l);  // <- Вот тут у тебя вторым аргументом стояла 'o'. Вопрос - почему?     
    if(q==-1) {
        printf("Подстроки с цифрой(ами) в начале нет.");
    } else {
    printf("Подстрока с максимальным количеством цифр в начале:\n");
    puts(s[q]);
    }
    


    f3(s);  

    return 0;
}

