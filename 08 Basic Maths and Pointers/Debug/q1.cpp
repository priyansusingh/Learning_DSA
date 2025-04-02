#include<iostream>
#include<vector>
using namespace std;


void SieveOfEratosthenes(int n) 
{
    vector<bool> prime(n+1, false);
  
    for (int p = 2; p * p <= n; p++) {
            for (int i = p * p; i <= n; i += p) 
                prime[i] = true; 
        } 
    
  
    for (int p = 0; p <= n; p++) 
        if (prime[p]) 
            cout << p << " "; 
}

int main(){
    SieveOfEratosthenes(50);
    return 0;
}
