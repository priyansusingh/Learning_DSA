#include<iostream>
using namespace std;

bool binarySearch(int arr[], int size, int target){
    int s = 0, e= size-1;
    int mid = (s+e)/2;
     
    while(s <= e){

        if(arr[mid] == target){
            return true;
        }
        
        if(target > arr[mid] ){
            s = mid + 1;
        } 

        if( target < arr[mid]){
            e = mid - 1;
        }

        mid = (s+e)/2;
    }
  return false;
}

void findFirstOccurence(int arr[], int n, int target, int &ansIndex){
  int s=0, e=n-1;
  int mid = s + (e-s)/2;
  while( s <= e){
     if( arr[mid] == target){
        ansIndex = mid;
        e = mid - 1;
     }
     else if (target > arr[mid]){
        s = mid + 1;
     }
     else if(target < arr[mid]){
        e = mid - 1;
     }
     mid = s + (e-s)/2;
  }
  }

void findLastOccurence(int arr[], int n, int target, int &ansIndex){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    
    while( s <= e){
        if( arr[mid] == target){
            ansIndex = mid;
            s = mid + 1;
        }
        if( target > arr[mid]){
            s = mid + 1;
        }
        if( target < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
}

int totalNumberOfOccurrences(int firstOccurrence, int lastOccurrence){
    int totalOccurrence = (lastOccurrence - firstOccurrence) + 1;
    
    return totalOccurrence;
}

int main(){
// Binary Search
//     int arr[10] = {10, 23, 24, 34, 40, 57, 69, 80, 90, 100};
//     int size = 10;
//     int target = 100;

//   //cout << binary_search(arr, arr+size, target) << endl;
//     cout << binarySearch(arr, size, target) << endl;

// First Occurance
int arr[] = {20,20,20,20,20,30,40,50,60};
int n = 11;
int target = 20;
int ansIndex = -1;
// findFirstOccurence(arr,n,target, ansIndex);
findLastOccurence(arr,n,target,ansIndex);
cout << ansIndex << endl;

    return 0;
}