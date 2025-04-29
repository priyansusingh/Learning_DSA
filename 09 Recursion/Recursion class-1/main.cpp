#include<iostream>
using namespace std;

//sum of 1 to n
int getSum(int n){
   //base case
   if(n == 1){
     return 1;
   }
   //recursive relations
   int ans = n + getSum(n-1);
   //processing
   return ans;
}

//fibonacci series
int fibo(int n){
    if(n==0 || n==1){
        return n;
    }

    int ans = fibo(n-1) + fibo(n-2);

    return ans;
}

//prints 2^n 
int pow(int n){
    //base case
    if( n==0 ){
        return 1;
    }
   
   //recurrence relation
   int recKaAns = pow(n-1);
   int finalAns = 2 * recKaAns;

   //processing
   return finalAns;
}

//print counting from n to 1
void printCounting(int n){
//base case
if( n==0 ){
    return;
}
cout << n <<" ";
//recursive call
printCounting(n-1);
//processing

}


int getFactorial(int n){
    //base case
    if(n == 0 || n ==1){
        return 1;
    }
 
    //recursive call
    int recursionKaAns = getFactorial(n-1);
    int finalAns = n * recursionKaAns;

    return finalAns;
}

int main(){
    
    int n;

    // cout << "Enter the value of n: ";
    // cin >> n;

    // int ans = getFactorial(n);
    // cout << "Factorial of "<< n << " is: " << ans << endl;

    // printCounting(5);

    // int ans = pow(10);
    // cout << ans <<" ";

    // cout << fibo(9) << endl;
    cout << getSum(5) << endl;
    return 0;
}