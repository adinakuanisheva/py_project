#include <stdio.h>
#include <string.h>
#define lmax 200

int main() {
    char first[lmax],second[lmax];
    int first10 = 0, second10 = 0;
    
    printf("Введите первое число: ");
    scanf("%s", first);
    printf("Введите второе число: ");
    scanf("%s", second);
    
    for (int i = 0; i < strlen(first); i++) {
        first10 = first10 * 2 + (first[i] - '0');
    }
    
    for (int i = 0; i < strlen(second); i++) {
        second10 = second10 * 2 + (second[i] - '0');
    }
    
    int s = first10 + second10;
    
    printf("Сумма: ");
    
    int summ[lmax], index = 0;
    while (s > 0) {
        summ[index]=s%2;
        s/=2;
        index++;
    }
    for (int i=index-1;i>=0;i--) {
        printf("%d", summ[i]);
    }
    printf("\n");
    return 0;
}
