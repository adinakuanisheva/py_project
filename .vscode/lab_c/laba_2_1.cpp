#include <stdio.h>
#define lmax 200
int main()   {
    int z[lmax][lmax], f[lmax], q[lmax], n, m, k, l, i, j, flag,n1, m1, s;
    printf("Лабораторная работа №2\n");
    printf("Куанишева Адина БИТ233\n");
    printf("Задание №1\n");
    printf("Введите число строк и столбцов матрицы z\n");
    do {
        l=scanf ("%d%d", &n, &m);
        while (getchar()!='\n');
    } 
    while (n<=0||m<=0||n>=lmax||m>=lmax||l!=2);
    
    printf ("Введите матрицу %d на %d\n", n, m);
    for (i=1;i<=n;i++) {
    for (j=1;j<=m;j++) {
    scanf ("%d", &z[i][j]);
    }
    }

    printf ("Введите длину массива f\n");
    do {
        l=scanf ("%d",&k);
        while (getchar()!='\n');
    } 
    while (l>=lmax||l<0||l!=1);
    
    printf ("Введите массив f из %d элементов\n", k);
    for (i=1;i<=k;i++) {
    scanf ("%d", &f[i]);
    }
    flag = 0;
    for(i=0; i<=n; i++) 
    {
        for (j=0;j<=m;j++)
        {
        if (z[i][j]<0)
        flag =1;   
        }
    }
    if (flag==0) {
    printf ("Нет отрицательных элементов в матрице");
    } else {
        for (j=1; j<=m; j++)
        {
            for (i=1; i<=n; i++)
            {
                if (z[i][j]<0){
                n1=i;
                m1=j;
                printf ("%d ", z[n1][m1]);
                break;
                } 
            } 
        }
    printf("\n");
    printf ("Массив q: ");
    for (j=0;j<=m;j++) 
    {
        for (i=0; i<=n; i++)
        {
        if (z[i][j]<0)
        {
        for (i=i+1;i<=n;i++)
            {
                s=0;
                for(int x=1;x<=k;x++)
                {
                    if(z[i][j]==f[x])
                    s++;
                    if(s!=0)
                    break;
                }
                if (s==0)
                {
                    q[lmax]=z[i][j];
                    printf ("%d ", q[lmax]);
                }
            }
        }
        }
    }
    if (s!=0) 
    printf ("Массив не сформирован\n");
    }
    return 0;
}

