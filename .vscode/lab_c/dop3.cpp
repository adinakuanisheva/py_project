#include <stdio.h>

void f(int x, int y);

int main() {
    int x, y;
    printf("Введите координаты x и y: ");
    scanf("%d %d", &x, &y);
    f(x, y);
    return 0;
}

void f(int x, int y) {
    if (x ==0 && y ==0) {
        printf("точка находится в начале координат(1&3 область)\n");
    } else if (x <=0 && y <=0 && y>=-1 && x>=-2) {
        printf("точка находится в 3 области\n");
    } else if (x >=0 && y >=0 && y<=1 && x<=3) {
        printf("точка находится в 1 области\n");
    } else {
        printf("точка находится в другой области\n");
    }
}