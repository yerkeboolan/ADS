#include <iostream>

	using namespace std;

		
		
	class Heap {
		static const int SIZE = 100;
		int *h;
		int HeapSize;
   	public :
   		Heap();
   		void addelement(int);
   		void outHeap();
   		void out();
   		int getmax();
   		void heapify(int);
   };



   Heap :: Heap() {
   		h = new int[SIZE];
   		HeapSize = 0;
   }



   void Heap :: addelement(int n) {
   	int i, parent;
   	i = HeapSize;
   	h[i] = n;
   	parent = (i - 1)/2;
   	while(parent >= 0 && i > 0) {
   		if(h[i] > h[parent]) {
   		int temp  = h[i];
   		h[i] = h[parent];
   		h[parent] = temp;
  		}
  		i = parent; 
  		parent = (i - 1)/2;
   	}

   	HeapSize++;


  }



  void Heap :: outHeap(void) {
  	int i = 0;
  	int k = 1;
  	while(i < HeapSize) {
  		while((i < k) && (i < HeapSize)) {
  			cout << h[i] << " ";
  			i++;
  		}
  		cout << endl;
  		k = k * 2 + 1;
 	}
 }



 int Heap :: getmax(void) {
 	int x;
 	x = h[0];
 	h[0] = h[HeapSize - 1];
 	HeapSize--;
 	heapify(0);
 	return(x);
 }

 void Heap :: heapify(int i) {
 	int left, right;
 	int temp;
 	left = 2*i + 1;
 	right = 2*i + 2;
 	if(left < HeapSize) {
 		if(h[i] < h[left]) {
 			temp = h[i];
 			h[i] = h[left];
 			h[left] = temp;
 			heapify(left);
 	    }
   }

   if(right < HeapSize) {
   	if(h[i] < h[right]) {
   		temp = h[i];
   		h[i] = h[right];
   		h[right] = temp;
   		heapify(right);
   		}
   	}
  }


  int main() {
  	Heap heap;
  	int k;
  	for(int i = 0; i < 10; i++) {
  		cout << "Enter the element "<<i + 1 <<": ";
  		cin >> k;
  		heap.addelement(k);
  	}


  	heap.outHeap();
  	cout << endl;
  	heap.out();
  	cout << endl<<"Maximum element: "<< heap.getmax();
  	cout << endl <<"New heap: "<<endl;
  	heap.outHeap();
  	cout <<endl;
  	heap.out();
  	cout  << endl << "Maximum element: " << heap.getmax();
  	cout  << endl << "New heap:" << endl;
  	heap.outHeap();
  	cout  << endl;
  	heap.out();
  	cin.get();cin.get();
  	return 0;
}




	

 