#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<bool> Sieve(int n){
    // create a sieve array of N size telling isPrime
    vector<bool> sieve(n+1,true);
    sieve[0]=sieve[1]=false;        
    for(int i=2; i*i<=n;i++){     //optimization 2-> outer loop
        if(sieve[i]==true){
            int j=i*i;            //optimization 1-> inner loop
            while(j<=n){
                sieve[j]=false;
                j += i;
            }
        }
    }
    return sieve;
}
vector<bool>segmentedSieve(int l, int r){
    // make a prime array to mark seg sieve
    vector<bool>sieve=Sieve(sqrt(r));
    vector<int>basePrimes;
    for(int i=0;i<sieve.size();i++){ // store all primes in basePrimes, to use them for seg sieve, as we need primes till sqrt(r), to mark all numbers in range
        if(sieve[i]){ // if prime
            basePrimes.push_back(i); // store prime, to use it for marking in seg sieve, as we need primes till sqrt(r), to mark all numbers in range
        }
    }
    vector<bool>segSieve(r-l+1,true); // create a seg sieve array of size r-l+1, +1 as 0 based indexing, to store primes in range l to r
    if(l==1 || l==0){
        segSieve[l]=false; // 0 and 1 are not prime
    }
    for(auto prime:basePrimes){ // for all primes till sqrt(r)
        int first_mul = (l/prime)*prime; // find the first multiple of prime in range l to r
        if(first_mul<l){ // if first_mul is less than l, then add prime to it, to get the first multiple of prime in range l to r
            first_mul+=prime; // add prime to it, to get the first multiple of prime in range l to r
        }
        int j=max(first_mul,prime*prime); // start marking from max of first_mul and prime*prime, as prime*prime se start karna hai, as prime*prime se chote multiples toh pehle hi mark ho chuke honge
        while(j<=r){
            segSieve[j-l] = false; // mark j as not prime, as it is a multiple of prime, in range l to r
            j+=prime; // increment j by prime
        }
    }
    return segSieve;
}

int main(){
    int l=110;
    int r=130;
    vector<bool>ss=segmentedSieve(l,r);
    for(int i=0;i<ss.size();i++){
        if(ss[i]) cout<< i + l << " ";
    }
    return 0;
}