#include<iostream>
#include<vector>
using namespace std;

// Search Space Pattern + Store and compute 
// Answer ke range me search karte hai binary search lagake
/*
Ex : Square root of 100
sol: Square root of 100 ka range 0 se 100 tak me hi hoga
    -> yaani ki answer 0 se 100 me hi koi hoga to 0 ---> 100 tak binary search apply karo
       start = 0 , End = 100;
     -> agar Mid*Mid bada hai 100 se , to answer left me hoga
     -> agar mid*mid chota hai 100 se to wo answer ho sakta hai par aur bhi nearest answer ho sakta
        isiliye isko store karke ek variable me right me jao
*/
class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s + (e-s)/2;
        int ans = -1;
        while( s <= e ){
           long long int prod = mid*mid;
          if( prod == x){
            return mid;
          }  
          if( prod < x ){
            ans = mid;
            s = mid + 1;
           
          }
          else{
            e = mid - 1;
          }
          mid = s + (e-s)/2;
        }
        return ans;
    }
};