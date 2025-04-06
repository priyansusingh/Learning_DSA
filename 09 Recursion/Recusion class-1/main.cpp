#include<iostream>
using namespace std;

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

    cout << "Enter the value of n: ";
    cin >> n;

    // int ans = getFactorial(n);
    // cout << "Factorial of "<< n << " is: " << ans << endl;

    // printCounting(5);

    int ans = pow(10);
    cout << ans <<" ";
    
    return 0;
}