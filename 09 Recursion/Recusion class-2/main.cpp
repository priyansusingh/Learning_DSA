#include<iostream>
using namespace std;

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

//Minimum number in array
void findMin(int* arr, int size, int index, int &mini){
    //base case
    if(index >= size){
      //entire array traverse ho chuka hai
      return;
    }
    //recursive relation
    //1 case mera
    mini = min(mini,arr[index]);
    //baaki recursion
    findMin(arr,size,index+1, mini);
    
  }

//Maximum number in array
void findMax(int* arr, int size, int index, int &maxi){
  //base case
  if(index >= size){
    //entire array traverse ho chuka hai
    return;
  }
  //recursive relation
  //1 case mera
  maxi = max(maxi,arr[index]);
  //baaki recursion
  findMax(arr,size,index+1, maxi);
  
}

//Search in a Array
bool searchInArray(int* arr, int index, int target, int size){
    //base case
    if(index == size){
        return false;
    }
    //ek case mai solve karunga
    //ise base case bhi bol sakte hai
    if( arr[index] >= target){
        //invalid index out of bound of array
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
   int arr[] = {10, 20, 30, 40, 50, 60};
   int size = 6;
   int target = 600;
   int maxi = INT8_MIN;
   int mini = INT8_MAX;


   findMin(arr,size,0,mini);
   cout << mini << endl;

//    findMax(arr,size,0,maxi);
//    cout << maxi << endl;

   //string ans = searchInArray(arr,0,target, size) ? "found":"not found";
   //cout << ans << endl;
   //printArray(arr,size, 0);


  

   return 0;
}