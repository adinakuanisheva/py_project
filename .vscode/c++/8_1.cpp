//класс фигуры на плоскости,координаты точки привязки(в конструкторе),метод вывода точки привязки на экран(ее координату)
//функция перемещения точки(просто смена координат), породить класс прямоугольник и новую точку привязки создать и переместить прямоугольник

#include <iostream>
using namespace std;

class Figure {
protected:
    float x;
    float y;
public:
    Figure(float a,float b) {
        x=a;
        y=b;
    }
    ~Figure() {};

    void output() {
        cout<<"point"<<"("<<x<<","<<y<<")"<<endl;
    }

    void MoveTo(float s,float f) {
        x=s;
        y=f;
    }

};

class Rectangle: public Figure {
    float len;
    float hight;
public:
    Rectangle(float l,float h,float r,float u) : Figure(r,u){
        len=l;
        hight=h;
    }
    void output() {
        cout<<"point"<<"("<<x<<","<<y<<")"<<endl;
        cout<<"len="<<len<<" hight="<<hight<<endl;
    }
};

int main() {
    Figure a(2.3,3.0);
    a.output();
    a.MoveTo(1.9,2.5);
    a.output();
    Rectangle b(3.8,5.7,8.9,2.3);
    b.output();
    b.MoveTo(100.0,100.0);
    b.output();
    return 0;
}