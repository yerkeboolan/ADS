#include <iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
};
 
struct node *top = NULL;
 
void push (int x){
    if (top == NULL){
        top = new node;
        top->value = x;
    }
    else{
        struct node *a;
        a = new node;
        a->value = x;
        a->next = top;
        top = a;
    }
}
void pop(){
    struct node *temp;
    if (top == NULL){
        cout << "stack is already empty" << endl;
    }
    else{
        temp = top;
        top = top->next;
	//  delete temp;
    }
}
int get_top(){
    if (top == NULL){
        cout << "stack is empty" << endl;
        return 0;
    }
    else{
        return top->value;
    }
}
int main(){
    push(1);
    push(2);
    cout << get_top() << endl;
    pop();
    cout << get_top() << endl;
    return 0;
}