#include <iostream>
using namespace std;

class queue{
    class node{
    public:
        int data;
        node* next;

        node(int x){
            data = x;
            next = NULL;
        }
    };

    node* head, *tail;
    int sze;
public:
    queue(){
        head = NULL;
        tail = NULL;
        sze = 0;
    }
    void push(int x){
        if(isempty()){
            node* tmp = new node(x);
            head = tmp;
            tail = tmp;
            sze++;
        }
        else{
            node* tmp = new node(x);
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void pop(){
        if(isempty()){
            return;
        }
        else{
            node* tmp = head;
            head = head->next;
            delete tmp;
            sze--;
        }
    }
    int front(){
        if(isempty()){
            return -1;
        }
        else{
            int x = head->data;
            return x;
        }

    }
    bool isempty(){
        return head==NULL;
    }
    int size(){
        return sze;
    }
    ~queue(){
        while(head){
            node* tmp = head->next;
            delete head;
            head = tmp;
        }
    }
};


int main(){
    queue q;
    q.push(10);
    q.push(2);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;


    return 0;
}