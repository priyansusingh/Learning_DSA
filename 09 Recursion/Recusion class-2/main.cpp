#include<iostream>
using namespace std;

//Search in a Array
int getTheNumber(int* arr, int size, int index, int target){
    //base case
    if( arr[index] == target){
        return index;
    }
    //Recursive relation
    
    //Processing

}


//Print the Array
void printArray(int* arr, int size, int index){
//base case
if(index == size){
   return;
} 
//Recursive relation
//ek case mai solve karunga
cout << arr[index] <<" ";
//baaki recursion sambhal lega
printArray(arr,size,index+1);

}

int main(){ 
   int arr[] = {12, 32, 24, 21, 43, 53};
   int size = 6;

   printArray(arr,size, 0);

    return 0;
}