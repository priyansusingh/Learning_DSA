#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int arr[5] = {10,20,30,40,50};
    int size = 5;

        int secondLargest = INT_MIN;
        int max = INT_MIN;
        int zeroCount = 0;
        
        for(int i=0; i<size; i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }
        
        for(int i=0; i<size; i++){
            if(arr[i] == max){
                arr[i] = 0;
            }
        }
        
        for(int i=0; i<size; i++){
            if(arr[i] == 0){
               zeroCount++;
            }
        }
        
        if(zeroCount == size){
            return -1;
        }
        
        for(int i=0; i<size; i++){
            if(secondLargest < arr[i]){
                secondLargest = arr[i];
            }
        }
        return secondLargest;

    return 0;
}