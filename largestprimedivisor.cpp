#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define MAX 10000000

int raiz_max = sqrt(MAX);
long long primes[MAX];
bool is_prime[MAX];
long long nPrimes=0;

using namespace std;

int main()
{

    memset(is_prime,true,sizeof(is_prime));
    is_prime[1]=false;
    is_prime[0] = false;
    for(long long i=2;i<MAX;i++)
    {
        if(is_prime[i])
        {
            primes[nPrimes++]=i;
            for(long long j=i*i, k=1;j<MAX;j= i*i + k++ *i)
            {
                is_prime[j]=false;
            }
        }
    }
    std::vector<int> factors;

    long long n;
    long long n2;
    int cont;
    while (std::cin>>n) {

        cont = 0;

        if(n == 0)
            break;

        if(n < 0)
            n2 = -n;
        else
            n2 = n;

        for(long int i=0; i<nPrimes; i++){
            if(n2 % primes[i] == 0){
                if(std::find(factors.begin(), factors.end(), primes[i]) != factors.end()) {
                    /* v contains x */
                } else {
                    factors.push_back(primes[i]);
                }
                if(n2/primes[i] == 1){
                    break;
                }
                else{
                    n2 = n2/primes[i];
                }
                i=-1;
                cont++;
            }
        }
        if((cont == 0) || (factors.size() == 1 && n2/factors[0] == 1)){
            std::cout<<"-1"<<std::endl;
        }
        else{
            std::cout<<n2<<std::endl;
        }
        factors.clear();
    }
    return 0;
}
