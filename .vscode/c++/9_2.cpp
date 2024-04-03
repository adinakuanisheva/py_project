//2 класса для 2 массивов(статический и динамический),они одинаковые будут, просто для практики

#include <iostream>
using namespace std;

template <typename A> 
class ArraySt{        //статический массив из 5 элементов
    A m[5];
public: 
    ArraySt(A a1,A a2,A a3,A a4,A a5) {
        m[0]=a1; m[1]=a2; m[2]=a3; m[3]=a4; m[4]=a5;
    }
    ArraySt(A n[5]) {
        for (int i=0;i<5;i++) {
            m[i]=n[i];
        }
    }
    void output() {
        for(int i=0;i<5;i++) {
            cout<<m[i]<<endl;
        }
    }

};

template <typename A> 
class Array {

};

int main() {
    int m1[5]={8,5,4,6,9}, m2[5];
    ArraySt<int> m3(m1);
    m3.output();

    float m11[5]={8,5,4,6,9};
    ArraySt<float> m4(5.1,6.7,4.3,3.3,2.3);
    m4.output();

    return 0;
}

