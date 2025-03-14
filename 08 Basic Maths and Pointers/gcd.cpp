
class Solution {
    public:
      int gcd(int a, int b) { 
          // code here
          if( a == 0 ) return b; // if a is 0, return b
          if( b == 0 ) return a; // if b is 0, return a
          while ( a > 0 && b > 0){ // while a and b are not 0
              if( a>b ){ // if a is greater than b, subtract b from a
                  a = a-b; 
              }
              else{ // if b is greater than a, subtract a from b
                  b = b-a;
              }
          }
       return a==0? b : a; // return b if a is 0, else return a
      }
  };
  