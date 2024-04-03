/*Разработать классы «точка» и «равнобедренный треугольник». Члены-данные сделать закрытой частью в каждом классе.
Для каждого класса разработать два конструктора: по умолчанию и с параметрами для инициализации, деструкторы, методы ввода/вывода.
Разработать: метод класса «треугольник» и функцию с двумя параметрами (точка и треугольник) определения принадлежности точки треугольнику.*/

#include <iostream>
using namespace std;

class Point {
private:
    float x, y; 

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(float xCoord, float yCoord) {
        x = xCoord;
        y = yCoord;
    }

    ~Point() {
    cout << "Деструктор точки вызван" << endl;
    }

    void input() {
        cout << "Введите координаты точки (x, y): ";
        cin >> x >> y;
    }

    void output() {
        cout << "Координаты точки: (" << x << ", " << y << ")" << endl;
    }

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }
};


class IsoscelesTriangle {
private:
    Point point1, point2, point3; 

public:
    IsoscelesTriangle() {
        point1=Point();
        point2=Point();
        point3=Point();
    }

    IsoscelesTriangle(Point p1, Point p2, Point p3) {
        point1 = p1;
        point2 = p2;
        point3 = p3;
    }

    /*~IsoscelesTriangle() {
    cout << "Деструктор треугольника вызван" << endl;
    }*/

    void input() {
        cout << "Введите координаты вершин треугольника." << endl;
        cout << "Вершина 1:" << endl;
        point1.input();
        cout << "Вершина 2:" << endl;
        point2.input();
        cout << "Вершина 3:" << endl;
        point3.input();
        
        while (!isIsoscelesTriangle()) {
            cout << "Введенные точки не образуют равнобедренный треугольник. Попробуйте снова." << endl;
            cout << "Вершина 1:" << endl;
            point1.input();
            cout << "Вершина 2:" << endl;
            point2.input();
            cout << "Вершина 3:" << endl;
            point3.input();
        }
    }

    void output() {
        cout << "Вершины треугольника:" << endl;
        point1.output();
        point2.output();
        point3.output();
    }

    bool isIsoscelesTriangle() {
        float x1 = point1.getX();
        float y1 = point1.getY();
        float x2 = point2.getX();
        float y2 = point2.getY();
        float x3 = point3.getX();
        float y3 = point3.getY();

        float side1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        float side2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        float side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

        return (side1 == side2) || (side2 == side3) || (side3 == side1);
    }

    Point getP1() {
        return point1;
    }
    Point getP2() {
        return point2;
    }
    Point getP3() {
        return point3;
    }

    bool isPointInside(Point p) {
        float x1 = point1.getX();
        float y1 = point1.getY();
        float x2 = point2.getX();
        float y2 = point2.getY();
        float x3 = point3.getX();
        float y3 = point3.getY();

        float x = p.getX();
        float y = p.getY();

        float s = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
        float s1 = abs((x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2)) / 2);
        float s2 = abs((x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y)) / 2);
        float s3 = abs((x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2);

        return s == s1 + s2 + s3;
    }
};

bool isPointInsideTriangle(Point& p,IsoscelesTriangle& T) {  //для сокращения объектов 
        float x1 = T.getP1().getX();
        float y1 = T.getP1().getY();
        float x2 = T.getP2().getX();
        float y2 = T.getP2().getY();
        float x3 = T.getP3().getX();
        float y3 = T.getP3().getY();

        float x = p.getX();
        float y = p.getY();

        float s = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
        float s1 = abs((x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2)) / 2);
        float s2 = abs((x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y)) / 2);
        float s3 = abs((x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2);

        return s == s1 + s2 + s3;
    }

int main() {
    
    /*Point p;
    p.input();

    IsoscelesTriangle triangle;
    triangle.input();

    if (triangle.isPointInside(p)) {
        cout << "Точка принадлежит треугольнику." << endl;
    }
    else {
        cout << "Точка не принадлежит треугольнику." << endl;
    } */

    Point pp;
    pp.input();
    IsoscelesTriangle T;
    T.input();

    if (isPointInsideTriangle(pp,T)) {
        cout << "Точка принадлежит треугольнику." << endl;
    }
    else {
        cout << "Точка не принадлежит треугольнику." << endl;
    }


    return 0;
}