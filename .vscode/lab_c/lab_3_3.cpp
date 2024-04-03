#include <stdio.h>
#define lmax 200

void input(int A[lmax], int *n);
void func1(int A[lmax], int C[lmax], int *n);
void func2(int A[lmax], int B[lmax], int C[lmax], int *k, int *n);

int main (){
	printf ("Лабораторная работа 3\n");
	printf ("Задание 3\n");
	int A[lmax],B[lmax],C[lmax],n,m,i,k;
	input(A, &n);
	func1(A, C, &n);
	func2(A, B, C, &k, &n);
}

void input (int A[lmax], int *n) {
	int n1,i,k;
	printf("Введите длину массива от 1 до %d: ",lmax);
	do
	{
		k=scanf("%d", &n1);
		while(getchar()!='\n');
	} while(n1<0 || n1>lmax || k!=1);
	*n=n1;
	printf("Введите значения элементов массива: ");
	for(i=0;i<n1;i++){
		scanf("%d",&A[i]);
	}
}

void func1(int A[lmax], int C[lmax], int *n) {
	int n1;
	n1=*n;
	for (int i=0;i<n1;i++) {
		C[i]=1;           
	}
	for(int i=0;i<n1;i++) {
		for(int j=i+1;j<n1;j++) {
			if(A[i]==A[j]) {
				C[i]++;
				for(int k=j; k<n1; k++){
					A[k]=A[k+1];
				}
				n1--;
				j--;
			}
		}
	}
	*n=n1;
}

void func2 (int A[lmax], int B[lmax], int C[lmax], int *k, int *n)
{
	int n1=*n, k1 =*k;
	k1=0;
	for (int i=0;i<n1;i++) {
		if (C[i]==1){
			k1++;
			B[k1]=A[i];
		}
	}
	if (k1==0){
		printf ("В массиве нет неповторяющихся элементов\n");
	}
	if (k1!=0){
		printf ("Новый массив: ");
		for (int j=1;j<k1+1;j++){
			printf ("%d ", B[j]);
		}
		printf("\n");
	}
}