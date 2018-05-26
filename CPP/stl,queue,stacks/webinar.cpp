#include <iostream>
using namespace std;

class stack{
    class node{
    public:
        int data;
        node* next;

        node(int x){
            data = x;
            next = NULL;
        }
    };
    node* head;
    int sze;
public:
    stack(){
        head = NULL;
        sze = 0;
    }
    void push(int x){
        node* n = new node(x);
        n->next = head;
        head = n;
        sze++;
    }
    void pop(){
        if(empty()) return;
        node* n = head;
        head = head->next;
        delete n;
        sze--;
    }
    int top(){
        if(empty()) return -1;
        int x = head->data;
        return x;
    }
    bool empty(){
        return head == NULL;
    }
    int size(){
        return sze;
    }
    ~stack(){
        while(head){
            node* ahead = head->next;
            delete head;
            head = ahead;
        }
    }
};

int main(){
    stack s;
    s.push(3);
    cout<<s.top();
    s.pop();


    return 0;
}
