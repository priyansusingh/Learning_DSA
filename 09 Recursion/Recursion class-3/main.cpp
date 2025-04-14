#include <iostream>
using namespace std;

bool checkSorted(int *arr, int size, int index)
{
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
    int arr[] = {12, 23, 34, 54, 58, 67, 75};
    int size = 7;
    int index = 0;
    bool ans = checkSorted(arr, size, index);
    cout << ans;
    return 0;
}