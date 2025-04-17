#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

void printAllEvenNumbers(int* arr, int size, int index){

    //base case
    if(index >= size){
        return;
    }
    //1 case
    if(!((arr[index])&1)){
        cout << arr[index] <<" ";
    }
    //baaki recursion
    printAllEvenNumbers(arr,size,index+1);

}

void printAllOddNumbers(int* arr, int size, int index, vector<int> &ans){

    //base case
    if(index >= size){
        return;
    }
    //1 case
    if((arr[index])&1){
        ans.push_back(arr[index]);
    }
    //baaki recursion
    printAllOddNumbers(arr,size,index+1,ans);

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
    if( arr[index] == target){  
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
   int arr[] = {11, 20, 33, 41, 32, 69};
   int size = 6;
   int target = 600;
   int maxi = INT8_MIN;
   int mini = INT8_MAX;
   int index = 0;
   vector<int> ans;

//    printAllEvenNumbers(arr,size,index);

   printAllOddNumbers(arr,size,index,ans);
   
   for(auto num: ans){
    cout << num <<' ';
   }
//    findMin(arr,size,index,mini);
//    cout << mini << endl;

//    findMax(arr,size,index,maxi);
//    cout << maxi << endl;

   //string ans = searchInArray(arr,index,target, size) ? "found":"not found";
   //cout << ans << endl;
   //printArray(arr,size, index);


  

   return 0;
}