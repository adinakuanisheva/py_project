#include <stdio.h>
#define lmax 200
int main() {
    int n,last,arr[lmax];
    printf("Лабораторная работа №2\n");
    printf("Куанишева Адина БИТ233\n");
    printf("Задание №2\n");
    printf("Введите длину массива: \n");
    do {
        scanf("%d",&n);
    }
    while (n<=0 || n>lmax);
    printf("Введите элементы массива:\n");
    for (int i=0;i<n;i++) 
    {
        printf("arr[%d]",i);
        do {
            scanf("%d",&arr[i]);
        }
        while (arr[i]<0);
    }
    last=arr[n-1];
    for (int i=n-2;i>=0;i--) 
    {
        arr[i+1]=arr[i];
    }
    arr[0]=last;
    printf("Новый массив:\n");
    for (int i=0;i<n;i++) 
    {
        printf("%4d",arr[i]);
    }
    return 0;
}