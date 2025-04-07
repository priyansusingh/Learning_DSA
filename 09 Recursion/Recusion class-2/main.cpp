#include<iostream>
using namespace std;

void printArray(int* arr, int size, int index){
  
if(index == size){
   return;
} 

cout << arr[index] <<" ";

printArray(arr,size,index+1);

}

int main(){ 
   int arr[] = {12, 32, 24, 21, 43, 53};
   int size = 6;

   printArray(arr,size, 0);

    return 0;
}