#include<iostream>
using namespace std;

class Heap{
    public:
    int* arr;
    int capacity;
    int index;
    
    Heap(int n){
     this->capacity = n;
     arr = new int[n];
     index = 0;
    }

    void printHeap(){
        for(int i=0; i<capacity; i++){
            cout<< arr[i] <<" ";
        }cout<<endl;
    }

    void insert(int val){
        if(index == capacity-1){
            cout<<"Overflow"<<endl;
            return;
        }
            index++;
            arr[index] = val;
         
        // insert ans compare with parent
        int i=index;
        while(i > 1){
          int parentIndex = i/2;
          if(arr[parentIndex] < arr[i]){
            swap(arr[parentIndex],arr[i]);
            i = parentIndex;
          }
          else{
            break;
          }
        }
    }
    
    void deleteFromHeap(){
      //replacing
      swap(arr[1],arr[index]);
      //decrease size;
      arr[index] = 0;
      index--;
      //heapify
      heapify(arr,index,1);
    }

    void heapify(int *arr, int n, int currIndex){
       int i = currIndex;
       int leftIndex = 2*i;
       int rightIndex = 2*i + 1; 
       // ab check karo ki left ya right me koi largest element hai ya nahi
       //agr hai to replace karo curr ko largest se
       int largestIndex = i;
       if( leftIndex < n && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
       }
       if( rightIndex < n && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
       }
       if(largestIndex != i){
        swap(arr[i],arr[largestIndex]);
        i = largestIndex;
        heapify(arr,n,i);
       }
    }
    
};

int main(){
    Heap pq(10);

    pq.insert(10);
    pq.printHeap();
    pq.insert(20);
    pq.printHeap();
    pq.insert(30);
    pq.printHeap();
    pq.insert(40);
    pq.printHeap();
    pq.insert(50);
    pq.printHeap();
    
    pq.deleteFromHeap();
    pq.printHeap();

    pq.deleteFromHeap();
    pq.printHeap();

    pq.deleteFromHeap();
    pq.printHeap();
    

    return 0;
}