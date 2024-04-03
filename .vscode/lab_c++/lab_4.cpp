#include <iostream>
#include <cmath>
using namespace std;

class Vector2 {
private:
    double x;
    double y;

public:
    Vector2() {
        x = 0.0;
        y = 0.0;
    }
    Vector2(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    friend istream& operator>>(istream& Cin, Vector2& v);
    friend ostream& operator<<(ostream& Cout, const Vector2& v);

    double operator~(){
        return sqrt(x*x + y*y);
    }

    friend Vector2& operator-=(Vector2& vector1, const Vector2& vector2);

};
istream& operator>>(istream& Cin, Vector2& v) {
    Cin >> v.x >> v.y;
    return Cin;
}

ostream& operator<<(ostream& Cout, const Vector2& v) {
    Cout << "(" << v.x << ", " << v.y << ")";
    return Cout;
}

Vector2& operator-=(Vector2& vector1, const Vector2& vector2) {
        vector1.x -= vector2.x;
        vector1.y -= vector2.y;
        return vector1;
    }

int main() {
    Vector2 vector1;
    cout << "Введите x и y для вектора vector1: ";
    cin >> vector1;

    Vector2 vector2;
    cout << "Введите x и y для вектора vector2: ";
    cin >> vector2;

    cout << "vector1: " << vector1 << endl;
    cout << "vector2: " << vector2 << endl;

    cout << "Длина вектора vector1: " << ~vector1 << endl;
    cout << "Длина вектора vector2: " << ~vector2 << endl;

    vector1-=vector2;
    cout << "Разность векторов vector1 и vector2: " << vector1 << endl;

    return 0;
}
