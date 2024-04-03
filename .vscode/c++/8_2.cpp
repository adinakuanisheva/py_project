//преобразуем фигуру в абстарктный класс и виртуальную метод плоащди фигуры, потом масштабирование фиру(то есть изменить ее размеры во сколько-то раз)
//+сделать фигуру круга
//функция сравнения фигур

#include <iostream>
using namespace std;

class figyra{
    protected:
    float x;
    float y;
    public:
    figyra(float a,float b){
        x=a;
        y=b;
    }
    ~figyra(){};
    void output (){
        cout<<"tochka:"<<"("<<x<<";"<<y<<")"<<endl;
    }
    void moveto(float s,float f){
        x=s;
        y=f;
    }
    virtual float squareF() = 0;
    
    virtual void changeF(float k) = 0;
};
class pr:public figyra {
    float len;
    float hight;
    public:
    pr(float w, float t,float r, float u):figyra(r,u){
        len=w;
        hight=t;
    }
    void output(){
        cout<<"tochka:"<<"("<<x<<";"<<y<<")"<<endl;
        cout<<"len="<<len<<" "<<"hight="<<hight<<endl;
    }
    float squareF() {
        return len * hight;
    }
    void changeF(float k) {
        len *= k;
        hight *= k;
    }
    
};

class cr:public figyra{
    float r;
    public:
    cr(float rad,float a, float b):figyra(a,b){
        r=rad;
    }
    void output(){
        cout<<"tochka:"<<"("<<x<<";"<<y<<")"<<endl;
        cout<<"r="<<r<<endl;
    }
    float squareF() {
        return 3.14 * r * r;
    }
    void changeF(float k) {
        r *= k;
    }
};

int compareFigure(figyra *fig1, figyra *fig2){
    float f1 = fig1->squareF();
    float f2 = fig2->squareF();
    if (f1 > f2){
        return 1;
    } else if (f1 == f2){
        return 0;
    }
    return -1;
};

int main()
{
    
    pr b (3.8,5.7,1.9,2.3);
    b.output();
    b.moveto(100.0,100.0);
    b.output();
    cout << "square = " << b.squareF();
    b.changeF(1.7);
    cout << "\nsquare = " << b.squareF() << endl;
    cr c (4, 1, 1);
    cout << "circle = " << c.squareF() << endl;
    c.changeF(2);
    cout << "circle = " << c.squareF() << endl;
    cout << compareFigure(&c, &b) << endl;
    return 0;
}
