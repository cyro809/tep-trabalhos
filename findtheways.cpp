
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <math.h>

using namespace std;

double factorial_log(long long int n, long long p) {
    double aux = 0;
    if( p > n-p){
        for( long long i=p+1; i<= n; i++){
            aux += (log10(i) - log10(n-i+1));
        }
    }
    else{
        for(long long i = n-p+1;i<=n;i++){
            aux += (log10(i) - log10(n-i+1));
        }
    }
    return aux;
}

int main()
{
    long long int n;
    long long int p;
    long long int c;

    while(scanf("%lld %lld",&n, &p) != EOF){
        c = floor(factorial_log(n,p)) +1;
        cout<<c<<endl;
    }
    return 0;
}
