#include<iostream>
using namespace std;

//Search in a Array
int getTheNumber(int* arr, int index, int target, int size){
    int ans = -1;
    //base case
    if(index == size){
        return -1;
    }
    //ek case mai solve karunga
    if( arr[index] == target){
         ans = index;
         return ans;
    }
    //Recursive relation
    getTheNumber(arr, index+1, target, size);
    //Processing
    return ans;
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

//    printArray(arr,size, 0);

   cout << getTheNumber(arr,0,53, size) << endl;

    return 0;
}