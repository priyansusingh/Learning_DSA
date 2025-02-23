#include<iostream>
using namespace std;

int getQuotient(int divident, int divisor){
   int s = 0;
   int e = divident;
   int mid = s + ((e-s)>>1);
   int ans = -1;

    while( s<=e ){
    if( divisor*mid == divident){
      return mid;
    }
    if(divisor*mid < divident){
        ans = mid;
        s = mid + 1;
    }
    else{
        e = mid - 1;
    }
    mid = s + ((e-s)>>1);
   }
    return ans;
}

int main(){

   int divident = 10;
   int divisor = -1;
 
   int ans = getQuotient(abs(divident), abs(divisor));
   
   if( (divident < 0 && divisor > 0) || ( divident > 0 && divisor < 0)){
    ans = 0-ans;
   }
    
    cout << "Final ans: "<< ans << endl;


    return 0;
}