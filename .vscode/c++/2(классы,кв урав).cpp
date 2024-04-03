//решение квадратного уравнение, используя классы
#include <iostream>
using namespace std;
#include <math.h>

class urav2 {
    float a,b,c;   //коэффициенты
public: 
    void ur_input(){
        cout>>"Введите a b c: ";
        cin>>a>>b>>c;
    }
    float discriminant() {
        return pow(b,2)-4*a*c;
    }
    void roots(float *r1,*r2) {
        *r1=(-b-sqrt(discriminant))/(2*a);
        *r2=(-b+sqrt(discriminant))/(2*a);
    }

};
int main() {

    return 0;
}