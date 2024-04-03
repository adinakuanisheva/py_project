//перегрузка операций
//класс(комплексное число):конструктор для инициализации.сделать перегрузку операторов ввода и вывода

#include <iostream>
//класс комплексное число
//конструктор для инициализации
//функция ввода вывода
//перегрузка операции
using namespace std;
class Complex
{
    float re,im;
public:
    Complex(float Re = 0., float Im = 0.){re = Re; im = Im;}
    friend istream& operator>>(istream&, Complex&); // потоковый ввод, прототип функции на cin>>
    friend ostream& operator<<(ostream&, Complex&); // потоковый вывод, прототип функции на cout<<
};
istream& operator>>(istream& Cin, Complex& x)
{
    Cin>>x.re>>x.im;         //Cin типо то же самое,что и cin
    return Cin;
}
ostream& operator<<(ostream& Cout, Complex& x)
{
    Cout<<"("<<x.re<<","<<x.im<<") ";     //Cout типо то же самое,что и cout
    return Cout;
}
int main()
{
    Complex X(-3.5, 1.7), Y(38.7), Z;
    cin>>Z;
    cout<<Z;
    return 0;
}