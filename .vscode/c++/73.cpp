//стек на массивах: массив из 10 элементов, 2 операции: push-заполняем стек числами с начала, pop-первое число вытаскиваем, а другие назад переносим

//списки на классах (создание,заполнение элементами и удаление элементов)

#include <iostream>
using namespace std;

class StackOnArr {
    float arr[100];
    int size;
public:
    StackOnArr(int s) {
        size=0;
    }

    void push(float value) {
        for(int i=size;i>0;i--) {
            arr[size]=arr[i];
        }
        arr[0]=value;
        size++;
    }

    float pop() {
        float result=arr[0];
        for(int i=0;i<size;i++) {
            arr[i]=arr[i+1];
        }
        size--;
        return result;
    }

    void print() {
        cout<<"[";
        for (int i=0;i<size;i++) {
            if (i!=size-1) cout<<arr[i]<<", ";
            else cout<<arr[i]<<"]";
        }
    }
};

int main() {
    StackOnArr B;
    B.print();
    B.push(4.3);
    B.push(5.);
    B.push(-2.9);
    B.pop();

}