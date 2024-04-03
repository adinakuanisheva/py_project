#include <stdio.h>
#include <math.h>
# define lmax 200
int main() 
    int n,c,b,pmax,np,i,k,n1,q;
    float x,h,a,sr,r[lmax];
    printf("Лабораторная работа №1\n");
    printf("Куанишева Адина БИТ223\n");
    printf("Задание №1\n");
    //Задание 1
    do
    {printf("Введите длину массива R от 1 до %d:",lmax);
        scanf("%d",&n);
    }
    while (n<=0||n>lmax);
    printf("Введите x,h,a:");
    scanf("%f",&x);
    scanf("%f",&h);
    scanf("%f",&a);
    for (i=1;i<=n;i++)
        r[i]=0.8*cos(8*a*x-i*h);
    printf("Массив R из %d элементов:\n",n);
    for (i=1;i<=n;i++)
        printf("%8.3f",r[i]);
    printf("\n");
    //Задание 2
    k=n;
    printf("Задание №2\n");
    for (pmax=0,np=0,i=1;i<=n;i++)
    {
        if (r[i]>0)
            np=i;
        if (fabs(r[i])>fabs(r[pmax]))
            pmax=i;
    }
    if (np==0)
    printf("Нет положительного элемента\n");
    else
    if (fabs(np-pmax)<2)
    printf("Последний положительный и первый максимальный по модулю элементы расположены рядом или совпадают\n");
    else {
        if (pmax<np) {
            c=pmax;
            b=np;
        } else {
            c=np;
            b=pmax;
        };
        k=c;
        for (i=b;i<=n;i++) {
            k+=1;
            r[k]=r[i];
        }
        printf("Массив r из %d элементов: \n",k);
        for (i=1;i<=k;i++)
        printf("%8.3f",r[i]);
        printf("\n\n");
    };
    //Задание 3
    printf("Задание №3\n");
    n1=0;
    q=0;
    sr=0;
    for (i=1;i<=k;i++) {
        if (r[i]>0) {
            n1=i;
        }
    }
    if (n1==k || n1==0) {
        printf("Нет среднего значения\n");
    } else {
    for (i=0;i<(n1-1);i++) {
        if (r[i]>0 && r[i]>r[n1]) {
            n1=i;
        }
    }
      for (i=n1+1;i<=k;i++) {
          sr+=r[i];
          q++;     
      }
      if (q!=0) {
        sr=sr/q;
        printf("sr=%f\n",sr);
      }
    }
    return 0;
}
