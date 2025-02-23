#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0, e = n-1;
        int mid = s + (e-s)/2;
        int ansIndex = -1;

        while( s <= e ){
            if( arr[mid] < arr[mid+1]){
                s = mid + 1;
            }
            else{
                ansIndex = mid;
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ansIndex;
        // while(s < e){ // (s<e) karne se infinite loop me nhi jayenge
        //     if( arr[mid] < arr[mid + 1]){ // Iska matlab hum line A par hai
        //         s = mid + 1;   // To Answer Right Me Hoga
        //     }
        //     else {
        //         e = mid; // e = mid taaki answer index miss na ho jaaye
        //     }
        //     mid = s + (e-s)/2;
        // }
        // return s;
    }
};