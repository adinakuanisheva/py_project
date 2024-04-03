#include <stdio.h>
#include <limits.h>

#define lmax 200

void f(int C[][lmax], int A[lmax], int *n, int *min);
void output(int *min);
void output_matrix(int C[][lmax], int n);
void input_matrix(int C[][lmax],int *n);

int main(void)
{
	int C[lmax][lmax],A[lmax],n,min;
	printf ("Лабораторная работа №3\n");
	printf ("Задача №2\n");
	input_matrix(C,&n);
	f(C,A,&n,&min);
	output_matrix(C,n);
	output(&min);
	return 0;
}

void input_matrix(int C[][lmax], int *n)
{	
	printf("n=");
	scanf("%d",n);
	printf("Введите матрицу %d на %d\n", *n, *n);
		for(int i=0;i<*n;i++)
		{
			for(int j=0;j<*n;j++)
			{
				scanf("%d", &C[i][j]);
			}
		}
}

void f(int C[][lmax], int A[lmax], int *n, int *min)
{	
	int max,n1,min1;
	n1=*n;
	min1=INT_MAX;
	for(int i=0;i<n1;i++)
	{	
		max=INT_MIN;
		for(int j=0;j<n1;j++)
		{
			if(C[i][j]>=max)
			{
				max=C[i][j];
			}
		}
		A[i]=max;
	}
	for(int i=0;i<n1;i++)
	{
		if(A[i]<=min1)
		{
			min1=A[i];
		}
	}
	*min=min1;
}

void output_matrix(int C[][lmax], int n)
{
	printf("Введённая матрица\n");
	for(int i=0; i<n; i++) {
		for (int j=0; j<n; j++) 
			printf("%4d", C[i][j]);
		printf("\n");
	}
}

void output(int *min)
{
	printf("Минимальное значение среди максимальных элементов по строкам\n");
	printf("min=%d\n",*min);
}
