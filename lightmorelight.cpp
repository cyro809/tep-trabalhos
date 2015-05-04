#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

bool is_perfect_square(unsigned long int n) {
    if (n < 0)
        return false;
    unsigned long int root(round(sqrt(n)));
    return n == root * root;
}

int main()
{
    unsigned long int n;

    while(true){
        cin>>n;
        if(n == 0)
            break;

        if(is_perfect_square(n)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
