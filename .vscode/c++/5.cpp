//написать функцию, на входе массив С и возвращает 2 числа(указатели) мин и макисимум в одной функции
#include <iostream>
#include <math.h>
using namespace std;
//написать классы ввод вывод
// функции считает макс и мин в массиве одновременно
class C // тип данных
{
    float *arr; //объявление вещ массива
    int len;

public:
    //конструктор
    C(int n)
    {
        arr = new float [len = n];
    }
    //деструктор
    ~C()
    {
        delete[] arr;
    }
    void input()
    {
        for(int i = 0; i < len; i++)
        {
            cout<<"["<<i<<"]";
            cin >> arr[i];
        }
        cout<<"\n";
    }
    void output()
    {
        for(int i = 0; i < len; i ++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    //инициатор - функция которая заполняет массив значениями из массива который передается в скобочках
    void set_arr(float array[], int n)
    {
        for(int i = 0; i < min(n, len); i++)
        {
            arr[i] = array[i];
        }
    }

    float get_elem(int n) {
        return arr[n];
    }
    int get_len() {
        return len;
    }

    //функция поиска мин и макс
    C find_min_max()
    {

        float min_max[2];
        min_max[0] = arr[0];   //минимум
        min_max[1] = arr[0];   // максимум
        for(int i = 1; i<len; i++)
        {
            if(arr[i] > min_max[1]) min_max[1] = arr[i];
            if(arr[i] < min_max[0]) min_max[0] = arr[i];
        }
        C arrClass(2);
        arrClass.set_arr(min_max, 2);
        return arrClass;
    }
};

void find_a(C ar,float *Min,float *Max) {
    *Min=ar.get_elem(0);
    *Max=ar.get_elem(0);
    for(int i = 1; i<ar.get_len(); i++)
        {
            if(ar.get_elem(i) > *Max) *Max = ar.get_elem(i);
            if(ar.get_elem(i) < *Min) *Min = ar.get_elem(i);
        }
}

int main()
{
    float Min,Max;
    C instance(5);
    instance.input();
    instance.output();
    C min_max(2); // массив из 2 элементов
    min_max = instance.find_min_max();
    min_max.output();
    find_a(instance,&Min,&Max);
    cout<<Min<<","<<Max<<endl;
    return 0;
}



