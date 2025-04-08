#include<iostream>
using namespace std;

//Search in a Array
bool searchInArray(int* arr, int index, int target, int size){
    //base case
    if(index == size){
        return false;
    }
    //ek case mai solve karunga
    if( arr[index] == target){
         return true;
    }
    //Recursive relation
    bool ans = searchInArray(arr, index+1, target, size);
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

   cout << searchInArray(arr,0,53, size) << endl;

    return 0;
}