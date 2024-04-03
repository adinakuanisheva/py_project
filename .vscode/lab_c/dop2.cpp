#include <stdio.h>
#include <locale.h>
#define lmax 200
int main()
{
	int z[lmax][lmax], n, m, k, l, i, j, flag,n1, m1, s,imax=0,cc;
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
        for (j=1; j<=m; j++){
            for (i=1; i<=n; i++)
            {
                if (z[i][j]<0)
                {
                    n1=i;
                    m1=j;
                    printf ("%d ", z[n1][m1]);
                    break;
                } 
            } 
        }
    }
    for(i=0; i<=n; i++) 
    {
        for (j=0;j<=m;j++)
        {
        if (z[i][j]>=imax)
        {
            imax=z[i][j];
        }    
        }
    }
    printf ("Новая матрица");
    for (i=0;i<=n;i++)
    {
        for (j=0; j<=m; j++)
        {
            cc=imax;
            imax=z[i][j];
            z[i][j]=cc;
        }
    }
	for (i = 0; i < n; i++) 
    {
		for (j = 0; j < m; j++) 
        {
			printf("%d\t", z[i][j]);
		}
		printf("\n");
        return 0;
	}
}
