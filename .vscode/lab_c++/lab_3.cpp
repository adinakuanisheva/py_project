/*Разработать класс «массив целых чисел произвольной размерности». (динамический массив) Члены-данные сделать закрытой частью класса.
Разработать:
·        конструктор для инициализации количеством элементов и заполнения заданным числом,
·        деструктор,
·        методы ввода/вывода,
·        метод вычисления количества элементов, равных заданному числу, и количества элементов, меньших заданного числа, и расположенных на последних n-четных позициях в массиве.*/

#include <iostream>
using namespace std;

class Array { 
private: 
    int *arr; int size;

public: 
    Array(int s, int num) { 
        size = s; 
        arr = new int[size]; 
        for (int i = 0; i < size; i++) { 
            arr[i] = num; 
            } 
    }

    ~Array() {
        delete[] arr;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void output() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void calculate(int num, int n) {
        int countEqual = 0;
        int countLess = 0;
        int countEven = 0;
        
        for (int i = size-1; i >= 0 ; i -= 1) {
            if (arr[i] == num) {
                countEqual++;
            }
        }
        for (int i = size-1; i >= 0 && countEven < n; i -= 2) {
            if (arr[i] < num) {
                countLess++;
            }
            countEven++;
        }

        cout << "Количество элементов, равных " << num << ": " << countEqual << endl;
        cout << "Количество элементов меньше, чем  " << num << " и на последних " << n << " четных позициях: " << countLess << endl;
    }
};

int main() { 
    int size, num, n; 
    cout << "Введите размер массива: "; 
    cin >> size; 
 
    Array myArray(size, num);

    cout << "Введите " << size << " чисел для заполнения массива: ";
    myArray.input();

    cout << "Элементы массива: ";
    myArray.output();

    cout << "Введите число для расчета элементов: ";
    cin >> num;
    cout << "Введите значение n для четных позиций: ";
    cin >> n;

    myArray.calculate(num, n);

    return 0;
}