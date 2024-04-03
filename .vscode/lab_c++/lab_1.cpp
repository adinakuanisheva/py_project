/* Разработать структуру «Двумерный массив», в котором будет храниться сам массив и его размерности. В программе объявить прототипы функций. 
Разработать функции: ввода двумерного массива, вывода двумерного массива, формирования одномерного массива по столбцам, расчета разницы средних 
значений элементов строк двумерного массива (получить индексы и вернуть значение в главную функцию), поиска минимальной и максимальной величины 
среди элементов вне полученного диапазона индексов в одномерном массиве (в одной функции). */

#include<iostream>
using namespace std;

const int MAX_SIZE = 100;
struct TwoDimensionalArray {
    int arr[MAX_SIZE][MAX_SIZE]; 
    int rows; 
    int columns; 
};

void inputArray(TwoDimensionalArray& arr);
void outputArray(const TwoDimensionalArray& arr);
void formOneDimensionalArray(const TwoDimensionalArray& arr, int resultArray[MAX_SIZE]);
double calculateRowAverage(const TwoDimensionalArray &array, int row);
double calculateAverageDifference(const TwoDimensionalArray &array, int row1, int row2);
void findMinMaxOutsideRange(const int arr[], int size, int start, int end, int &minValue, int &maxValue);

int main() {
    TwoDimensionalArray arr;
    inputArray(arr);
    outputArray(arr);
    
    int resultArray[MAX_SIZE];
    formOneDimensionalArray(arr, resultArray);
    
    cout << "Одномерный массив: ";
    for (int i = 0; i < arr.rows * arr.columns; i++) {
        cout << resultArray[i] << " ";
    }
    cout << endl;

    int row1, row2;
    cout << "Введите индексы двух строк: ";
    cin >> row1 >> row2;
    double averageDifference = calculateAverageDifference(arr, row1, row2 );
    cout << "Разница средних значений двух строк составляет: " << averageDifference << endl;

    int start, end;
    cout << "Введите диапазон индексов в одномерном массиве: ";
    cin >> start >> end;
    int minValue, maxValue;
    findMinMaxOutsideRange(resultArray, arr.rows * arr.columns, start, end,minValue, maxValue);   
    cout << "Минимальное значение вне диапазона составляет: " << minValue << endl;
    cout << "Максимальное значение вне диапазона составляет: " << maxValue << endl;
    
    return 0;
}

void inputArray(TwoDimensionalArray& arr) {
    cout << "Введите количество строк: ";
    cin >> arr.rows;
    cout << "Введите количество столбцов: ";
    cin >> arr.columns;
    
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < arr.rows; i++) {
        for (int j = 0; j < arr.columns; j++) {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr.arr[i][j];
        }
    }
}

void outputArray(const TwoDimensionalArray& arr) {
    cout << "Двумерный массив:" << endl;
    for (int i = 0; i < arr.rows; i++) {
        for (int j = 0; j < arr.columns; j++) {
            cout << arr.arr[i][j] << " ";
        }
        cout << endl;
    }
}

void formOneDimensionalArray(const TwoDimensionalArray& arr, int resultArray[MAX_SIZE]) {
    int k = 0; 
    for (int j = 0; j < arr.columns; j++) {
        for (int i = 0; i < arr.rows; i++) {
            resultArray[k] = arr.arr[i][j];
            k++;
        }
    }
}

double calculateRowAverage(const TwoDimensionalArray &array, int row) {
    double sum = 0;
    for (int j = 0; j < array.columns; j++) {
        sum += array.arr[row][j];
    }
    return sum / array.columns;
}

double calculateAverageDifference(const TwoDimensionalArray &array, int row1, int row2) {
    double average1 = calculateRowAverage(array, row1);
    double average2 = calculateRowAverage(array, row2);
    return average1 - average2;
}

void findMinMaxOutsideRange(const int arr[], int size, int start, int end, int &minValue, int &maxValue) {
    minValue = INT_MAX;
    maxValue = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (i < start || i > end) {
            if (arr[i] < minValue) {
                minValue = arr[i];
            }
            if (arr[i] > maxValue) {
                maxValue = arr[i];
            }
        }
    }
}