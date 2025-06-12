#include <iostream>
#include<vector>
using namespace std;

void printSubsequences(string str, int i, string output, vector<string> &ans){
  //base case
    if(i == str.length()){
        ans.push_back(output);
        return;
    }
  //1 case
  //include
  char ch = str[i];
  printSubsequences(str, i+1, output+ch,ans);
  //exclude
  printSubsequences(str, i+1, output,ans);
}


bool checkSortedDescending(int *arr, int size, int index){
    //base case
    if(index+1 == size-1){
        return true;
    }
    //1 case
    bool meraAns = false;
    bool recKaAns = false;
    if( arr[index+1] < arr[index]){
        meraAns = true;
    }
    //baaki recursion
    recKaAns = checkSortedDescending(arr,size,index+1);
    
    return (meraAns&&recKaAns);
}

bool checkSorted(int *arr, int size, int index){
    // base case
    if (index+1 == size-1)
    {
        return true;
    }
    bool meraAns = false;
    bool recKaAns = false;

    // ek case mai
    if (arr[index+1] > arr[index])
    {
     meraAns = true;
    }
    // baki recursion
    recKaAns = checkSorted(arr, size, index+1);
     
  return (meraAns&&recKaAns);
}

int main()
{
   string str = "abc";
   string output = "";
   vector<string> ans;
   int index = 0;
   printSubsequences(str, index, output,ans);
   cout << "size-->" << ans.size() << endl;   string str = "abc";
   string output = "";
   vector<string> ans;
   int index = 0;
   printSubsequences(str, index, output,ans);
   cout << "size-->" << ans.size() << endl;
   cout << "printing subsequesces: " << endl;
   for(auto i: ans){
   cout << i << endl;
   }
   cout << "printing subsequesces: "<< endl;
   for(auto i: ans){
   cout << i << endl;
   }
    // int arr[] = {70, 60, 50, 40, 30, 20, 10};
    // int size = 7;
    // int index = 0;
    // bool ans = checkSortedDescending(arr, size, index);
    // cout << ans;
    return 0;
}