#include <iostream>
using namespace std;
struct node{
    int value;
	node *next;

	node() {}
	node(int x) {
		value = x;
		next = NULL;
	}
};
 
node *first = NULL;
node *last = NULL;
 
void enqueue(int x){
    if (first == NULL){
        last = first = new node(x);
    }
    else{
        node *a = new node(x);
        node *prelast = last;
        last = a;
        prelast -> next = last;
   }
}
void dequeue(){        
    if (first == NULL){
        cout << "queue is already empty" << endl;
    }
    else{
        node *temp = first;
        first = first->next;
        delete temp;
    	if (first == NULL)
    		last = NULL;
    }
}
int get_first(){
    if (first == NULL){
        cout << "queue is empty" << endl;
        return 0;
    }
    else{
        return first->value;
    }
}
int main(){
  	for (int i = 1; i <= 10; ++i)
  		enqueue(i * i);
  	for (int i = 1; i <= 10; ++i) {
  		dequeue();
  		cout << get_first() << endl;
  	}
    return 0;
}
