#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

long long int power(long long int x, unsigned long long int y,long long int p)
{
    long long int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main(){
    int tc;

    cin>>tc;

    while(tc--){

        int squareIteration;

        cin >> squareIteration;

        long long int square = power(2,squareIteration,1000000007);

       // cout << square <<endl;

        long long int dot= (square%1000000007 + 1)%1000000007;

        long long int results =((dot%1000000007)*(dot%1000000007))%1000000007;

        cout << results <<endl;

    }

    return 0;
}
