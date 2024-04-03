//классы
//написать функцию которая считает одновременно максимум и минимум массива
#include <iostream>
#include <math.h>
using namespace std;

class C {
    float *arr;
    int lenght;
public: 
    C(int n) {
        arr=new float[lenght=n];   
    }
    ~C() {
        delete[] arr;
    }
    void input() {
        for (int i=0;i<lenght;i++) {
            cin>>arr[i];
        }
    }
    void output() {
        cout<<"(\n";
        for (int i=0;i<lenght;i++) {
            cout<<arr[i]<<",";
        }
        cout<<")\n";
    }

    void set_arr(float array[],int n) {
              //если сравнить n и length, то на входе будет минимальная длина
        for(int i;i<min(n,lenght);i++) {
                arr[i]=array[i];
        }
    }

    C find_min_max() {        
        float min_max[2];
        min_max[0]=arr[0];
        min_max[1]=arr[1];
        //первый элемент-минимальный,второй-максимум
        for (int i=1;i<lenght;i++) {
            if (arr[i]>min_max[1]) min_max[1]=arr[i];
            else if(arr[i]<min_max[0]) min_max[0]=arr[i];
        }
        C arrClass(2);     //динамический массив из 2 элементов
        arrClass.set_arr(min_max,2);
        return arrClass; 
    }

};


int main() {
    C instance(5);       //создаем экземпляр класса,где вводим 5 чисел для массива
    instance.input();
    instance.output();

    C min_max(2);       //еще экземляр класса,гед
    min_max= instance.find_min_max();
    min_max.output();
    return 0;
}