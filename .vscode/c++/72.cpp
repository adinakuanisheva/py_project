//списки на классах (создание,заполнение элементами и удаление элементов)

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *ukaz;     
};

class Stack {
    Node *begin;  //первый узел списка
    int len;       //длина списка
public:
    Stack() {
        begin=NULL;
        len=0;
    }

    void add(int n) {
        Node *noviy=new Node();     //имя нового узла
        noviy->ukaz=begin;
        noviy->info=n;
        begin=noviy;
        len++;
    }

    int dlt() {        //для удаления элемента(первого, то есть как стек: будет удаляться первые по очереди как стопка тарелок)
        int k=begin->info;
        begin=begin->ukaz;
        len--;
        return k;
    }

    Node* next(Node *n) {          //прыгнуть на след Node
        if (n->ukaz==NULL) {
            return NULL;
        }
        return n->ukaz;
    }

    void output() {
        Node *curr=begin;
        cout<<"print Stack\n[";
        for (int i=0;i<len;i++,curr=next(curr)) {
            cout<<curr->info<<" ";
            
        }
        cout<<"]\n";
    }
};

int main() {
    Stack s;   //список
    s.add(14);
    s.add(100);
    s.output();
    int k=s.dlt();
    cout<<k<<"\n";
    s.output();
    return 0;
}