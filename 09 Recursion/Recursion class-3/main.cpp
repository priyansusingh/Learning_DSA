#include <iostream>
using namespace std;

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
    int arr[] = {70, 60, 50, 40, 30, 20, 10};
    int size = 7;
    int index = 0;
    bool ans = checkSortedDescending(arr, size, index);
    cout << ans;
    return 0;
}