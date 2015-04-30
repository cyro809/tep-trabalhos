#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    long long int n;
    long long int n2;
    int cont;
    long long int largest_prime;
    std::vector<int> primes;
    primes.push_back(2);
    for(long long int i=3; i < sqrt(100000000); i++)
    {
        bool prime=true;
        for(int j=0;j<primes.size() && primes[j]*primes[j] <= i;j++)
        {
            if(i % primes[j] == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime)
        {
            primes.push_back(i);
        }
    }

    while (true) {
            cont = 0;
            largest_prime = 0;
            cin>>n;
            if(n == 0)
                break;

            n2 = n;
            for(long long int i=0; i<sqrt(n); i++){
                if(n2 % primes[i] == 0){
                    if(largest_prime <= primes[i]){
                        largest_prime = primes[i];
                    }
                    n2 = n2/primes[i];

                    if(n2 == 1) break;
                    i=0;
                    cont++;
                }
            }
            if(cont == 0){
                cout<<"-1"<<endl;
            }
            else{
                cout<<largest_prime<<endl;
            }

    }
    return 0;
}
