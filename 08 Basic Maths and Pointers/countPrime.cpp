class Solution {
    public:
        int countPrimes(int n) {
            if( n==0 ) return 0; 
            vector<bool> prime(n,true);  // prime[i] = true means i is prime
            prime[0] = prime[1] = false; // 0 and 1 are not prime
            int ans = 0; // number of primes
            for(int i=2; i<n; i++){ // check if i is prime 
              if(prime[i]){ // if i is prime, increment ans and mark all multiples of i as not prime
                ans++; 
                int j=2*i; // start from 2*i
                while( j<n ){ // mark all multiples of i as not prime
                  prime[j] = false; // j is not prime
                  j+=i; // increment j by i
                }
              }
            }
            return ans;
        }
    };