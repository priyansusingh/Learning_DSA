#include<iostream>
#include<vector>
using namespace std;

// Sieve of Eratosthenes
vector<bool> Sieve(int n){
    // create a sieve array of N size telling isPrime
    vector<bool> sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2; i<=n;i++){
        if(sieve[i]==true){
            int j=i*2;
            while(j<=n){
                sieve[j]=false;
                j += i; //increment by i
            }
        }
    }
    return sieve;
}


// optimising Sieve of Eratosthenes
vector<bool> optSieve(int n){
    // create a sieve array of N size telling isPrime
    vector<bool> sieve(n+1,true);
    sieve[0]=sieve[1]=false;        
    for(int i=2; i*i<=n;i++){     //optimization 2-> outer loop , root(n) tak hi jana hai kyuki uske baad ke elements toh pehle hi mark ho chuke honge
        if(sieve[i]==true){
            int j=i*i;            //optimization 1-> inner loop, i*i se start karna hai kyuki i-1 se pehle ke elements toh pehle hi mark ho chuke honge
            while(j<=n){
                sieve[j]=false;
                j += i; //increment by i
            }
        }
    }
    return sieve;
}

int main(){
    // vector<bool>sieve=Sieve(25);
    vector<bool>sieve=optSieve(25);
    for(int i=0;i<=25;i++){
        if(sieve[i]) cout<<i<<" ";
    }
    return 0;
}

