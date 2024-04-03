//написать метод, который меняет ~ и получить компекс сопряженного числа

#include <iostream>
#include <math.h>
//написать метод - оператор тильда - и получить комплекс сопряженного числа - часть IM меняет знак и все
using namespace std;
class Complex
{
    float re,im;
public:
    Complex(float Re = 0., float Im = 0.){re = Re; im = Im;}
    Complex operator+(Complex a)
    {
        Complex temp;
        temp.re = re + a.re;
        temp.im = im + a.im;
        return temp;
    }
    Complex operator~()
    {
        Complex nov;
        nov.re = re;
        nov.im = -im;
        return nov;
    }
    friend float operator!(Complex p);
    friend istream& operator>>(istream&, Complex&); // потоковый ввод
    friend ostream& operator<<(ostream&, Complex&); // потоковый вывод

};
float operator!(Complex p)
{
    return sqrt(p.re*p.re + p.im*p.im);
}
istream& operator>>(istream& Cin, Complex& x)
{
    Cin>>x.re>>x.im;
    return Cin;
}
ostream& operator<<(ostream& Cout, Complex& x)
{
    Cout<<"("<<x.re<<","<<x.im<<") ";
    return Cout;
}
int main()
{
    Complex X(-3.5, 1.7), Y(38.7), Z;
    Z = ~X;
    cout<<Z;

    return 0;
}