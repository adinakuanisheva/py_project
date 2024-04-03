#include <stdio.h>

float X(float a,float b, float c, float d, float e, float f);
float Y(float a, float b, float c, float d, float e, float f);

int main() {
	printf("Лабораторная работа №3\n");
    printf("Куанишева Адина БИТ233\n");
    printf("Задание №1\n");
    float a, b, c, d, e, f,x,y,k;
    do {
        printf("Введите a,b,c,d,e,f: ");
        k=scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
    } while (k!=1 && getchar()!='\n');
    if ((a*e-b*d)==0) {
		printf("ae-bd=0, поэтому происходит деление на 0\n");
	} else {
		x=X(a,b,c,d,e,f);
		y=Y(a,b,c,d,e,f);
		printf("x=%.1f y=%.1f\n",x,y);
        printf("\n");
	}
    return 0;
}

float X(float a,float b,float c,float d,float e,float f) {
    float x=(c*e-b*f)/(a*e-b*d);
    return x;
}

float Y(float a,float b,float c,float d,float e,float f) {
    float y=(a*f-c*d)/(a*e-b*d);
    return y;
}

