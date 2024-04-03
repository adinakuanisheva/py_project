//та же задача,только функция суммирования написана через указатели
//на структуру: разработай 2 строктуры: точку(с координатами) и двумерный вектор(координаты начала и конца) и написать функцию суммирования

#include <stdio.h>

struct dot {
    float x;
    float y;
};

struct vector {
        struct dot start_dot;
        struct dot end_dot;
};

struct dot scan_dot() {
    struct dot d;
    float x, y;
    printf("Введите X и Y: ");
    scanf("%f%f", &x, &y);
    
    d.x = x;
    d.y = y;
    return d;
}

struct vector scan_vector() {
    struct vector v;
    printf("Введите x1 y1: ");
    v.start_dot = scan_dot();
    printf("Введите x2 y2: ");
    v.end_dot = scan_dot();
    
    return v;
}

void print_dot(struct dot d) {
    printf("Точка (%f; %f)", d.x, d.y);
}

void print_vector(struct vector v) {
    printf("vector ");
    print_dot(v.start_dot);
    print_dot(v.end_dot);
}

// struct vector summa(struct vector v1, struct vector v2){
//     struct vector s; 
//     s.start_dot.x = v1.start_dot.x + v2.start_dot.x;
//     s.start_dot.y = v1.start_dot.y + v2.start_dot.y;
//     s.end_dot.x = v1.end_dot.x + v2.end_dot.x;
//     s.end_dot.y = v1.end_dot.y + v2.end_dot.y;
//     return(s); 
// }

void summa_pointers(struct vector *v1, struct vector *v2, struct vector *s) {
    s->start_dot.x = v1->start_dot.x + v2->start_dot.x;
    s->start_dot.y = v1->start_dot.y + v2->start_dot.y;
    s->end_dot.x = v1->end_dot.x + v2->end_dot.x;
    s->end_dot.y = v1->end_dot.y + v2->end_dot.y;
}

int main()
{
    //struct dot d = scan_dot();
    //print_dot(d);
    struct vector v = scan_vector();
    struct vector w = scan_vector();
    struct vector s;
    //s = summa(v,w);
    summa_pointers(&v,&w,&s);
    print_vector(v);
    print_vector(w);
    print_vector(s);
    return 0;
}
