#include <iostream>
using namespace std;
  
  void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2; 
 
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
       
        heapify(arr, n, largest);
    }
}
 

	void heapSort(int arr[], int n)
{
    for (int i = n; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i=n-1; i>=0; i--)
    {
        
    swap(arr[0], arr[i]);
 
      
        heapify(arr, i, 0);
    }
}
 
	
	void printArray(int arr[], int n)
	{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
	}
 
int main()
{                
  	int arr[] = {5, 14, 10, 65, 89, 78, 3};  
   
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}