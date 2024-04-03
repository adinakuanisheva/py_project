//похожее на 1 лабу по структурам: создать стурктуру вектора(массив и число размера)
//найти в массиве первое число(которое мы введем) и на каком месте оно стоит(например введем 4 и массив 1 2 4 5,должно вывести 2(это индекс 4 в массиве))
#include <iostream>

using namespace std;

struct vector 
{
    int ln;            //длина вектора
    float *v;          //указатель на массив,начало вектора
};

struct vector new_vector(int n)  //n-длина вектора
{
    struct vector X;
    X.ln = n;
    X.v = new float[X.ln];
    for (int i = 0; i < X.ln; i++) 
        X.v[i] = 0;
    return X;
}

void input_vector(struct vector *vec)
{
    for (int i = 0; i < vec->ln; i++)         //стрелочка-тк передает указатель
        cin >> vec->v[i];
}

void print_vector(struct vector vec)
{
    cout << "{";
    for (int i = 0; i < vec.ln; i++)
        cout << vec.v[i] << " ";
    cout << "}\n";
}
int search(struct vector vec, float x)
{
    for(int i = 0; i < vec.ln; i++)
    {
        if(vec.v[i] == x) return i;
    }
    return -1;
}

int main()
{
    int n;
    cout << "input n \n";
    cin >> n;
    cout << "input vector \n";
    struct vector p;
    p = new_vector(n);
    input_vector(&p);
    cout << "print vector \n";
    print_vector(p);
    float x; 
    cout<<"Input x \n";
    cin>>x; 
    int index;                        //номер числа, который нам нужен  
    index = search(p,x);
    if(index == -1) cout<<"No x"; 
    else cout<<index;
    
    return 0;
}




