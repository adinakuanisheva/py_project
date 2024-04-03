#include <iostream>
using namespace std;

class VolumeFigure {
protected:
    int x, y, z;
public:
    VolumeFigure(int x, int y, int z) : x(x), y(y), z(z) {}

    void displayCoordinates() {
        cout << "Координаты точки привязки фигуры: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void shiftFigure(int newX, int newY, int newZ) { 
        x = newX;
        y = newY;
        z = newZ;
    }

    virtual double calculateS() = 0; 

    virtual void stretchAlongZ(double k) = 0;
};

class Parallelepiped : public VolumeFigure {
    int lenght, width, height;
public:
    Parallelepiped(int x, int y, int z, int lenght, int width, int height) : VolumeFigure(x, y, z), lenght(lenght), width(width), height(height) {}

    void displayParameters() {
        cout << "Параметры параллепипеда:" << endl;
        cout << "Точка привязки: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Длина: " << lenght << ", Ширина: " << width << ", Высота: " << height << endl;
    }

    void stretchAlongZ(double k) override {
        height *= k;
    }

    double calculateS() override { 
        return 2 * (lenght * width + lenght * height + width * height);
    }
};

double compareS(VolumeFigure& figure1, VolumeFigure& figure2) { 
    double area1 = figure1.calculateS();
    double area2 = figure2.calculateS();
    return area1 - area2;
}

int main() {
    int x, y, z, lenght, width, height;

    cout << "Введите координаты точки привязки фигуры (x, y, z): ";
    cin >> x >> y >> z;

    cout << "Введите длину, ширину и высоту параллелепипеда: ";
    cin >> lenght >> width >> height;

    Parallelepiped p(x, y, z, lenght, width, height);
    p.displayParameters();

    double stretchK;
    cout << "Введите коэффициент растяжения по z: ";
    cin >> stretchK;
    p.stretchAlongZ(stretchK);
    cout << "Новая площадь после растяжения: "<< p.calculateS() << endl;
    p.displayParameters();

    cout << "Введите координаты точки привязки второго параллелепипеда (x, y, z): ";
    cin >> x >> y >> z;
    cout << "Введите длину, ширину и высоту второго параллелепипеда: ";
    cin >> lenght >> width >> height;

    Parallelepiped p2(x, y, z, lenght, width, height);

    cout << "Площадь поверхности p: " << p.calculateS() << endl;
    cout << "Площадь поверхности p2: " << p2.calculateS() << endl;

    double res = compareS(p, p2);
    cout << "Разница между p и p2: " << res << endl;

    return 0;
}