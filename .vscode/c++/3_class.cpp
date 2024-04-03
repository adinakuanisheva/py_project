//то же самое, что и 3_struct.cpp,только из классов 
#include <iostream>

using namespace std;

class vector{
    int ln;
    float *v;
public:
    vector(int n){
        ln = n;
        v = new float[ln];
        for(int i = 0; i != ln; ++i){
            v[i] = 0;
        }
    }
    ~vector(){
        delete[] v;
    }
    void input(){
        for (int i = 0; i < ln; i++){
        cin >> v[i];
        }
    }
    void print(){
        for (int i = 0; i < ln; i++){
        cout << v[i] << " ";}
        cout << endl;
    }
    int search(float x){
        for(int i = 0; i < ln; i++) {
            if(v[i] == x) return i;
            
        }
    return -1;
    }
};


int main()
{
    int n;
    cout << "input n \n";
    cin >> n;
    cout << "input vector \n";
    vector p(n);
    p.input();
    cout << "print vector \n";
    p.print();
    float x; 
    cout<<"Input x \n";
    cin>>x; 
    int index;
    index = p.search(x);
    if(index == -1) cout<<"No x"; 
    else cout<<index;
    
    return 0;
}

