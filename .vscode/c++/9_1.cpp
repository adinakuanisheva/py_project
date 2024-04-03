//на шаблоны: функция макисмум в виде шаблона,на нее сделать класс интервал(от и до)
//функцию(метод в классе) пересеняи двух интервалов(которая возвращает интервал,кусочек пересения)

#include <iostream>
using namespace std;

template <typename T> 
T Maximum(T a,T b) {
    if (a>b) {
        return a;
    }
    return b;
}

template <typename T> 
T Minimum(T a,T b) {
    if (a<b) {
        return a;
    }
    return b;
}

template <typename T>
class Interval {
    T left;
    T right;
public: 
    Interval(T a,T b) {
        left=a;
        right=b;
    }
    void print() {
        cout<<"("<<left<<";"<<right<<")"<<endl;
    }

    Interval <T> peresech(Interval<T> i2) {              //пересечение интервалов 
        return Interval<T> (Maximum<T>(left,i2.left),Minimum<T>(right,i2.right));
    }
};



int main() {
    int a,b;
    a=9;
    b=3;
    cout<<Maximum<int>(5,7)<<endl;     //попорбуем испробовать функцию максимума 
    cout<<Maximum<float>(-3.5,7.34)<<endl;
    cout<<Maximum<int>(a,b)<<endl;

    Interval<int> i(a,b);         //пробуем функцию класса,которая выводит интервал
    i.print();
    
    char d='A', e='F';
    Interval<char> i1(d,e);
    i1.print();

    Interval<int> in1(5,10);      //ищем пересечение интервалов
    Interval<int> in2(2,7);
    Interval<int> ans=in1.peresech(in2); 
    ans.print();
    return 0;
}

