#include <stdio.h>

int main() {

    FILE *f;
    int k,b,summ=0;

    f=fopen("123.rtf","w");
    printf("Введите количество символов: ");
    scanf("%d",&k);

    for (int i=0;i<k;i++){
        printf("Введите %d число: ",i+1);
        scanf("%d",&b);
        fprintf(f,"%d ",b);
    }

    fclose(f);

    f=fopen("123.rtf","r");
    for (int i=0;i<k;i++) {
        fscanf(f,"%d",&b);
        if (b>0) 
            summ+=b;
    }

    fclose(f);

    printf("%d\n",summ);

    return 0;
}