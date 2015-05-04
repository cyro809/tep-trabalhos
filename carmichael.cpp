#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int carmichael_numbers[15] = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
bool is_carmichael(int n){
   for(int i=0;i<15;i++){
        if(n == carmichael_numbers[i])
            return true;
   }
   return false;
}

int main()
{
   int n;

   while(true){
        cin>>n;

        if(n==0)
            break;

        if(is_carmichael(n)){
            cout<<"The number "<<n<<" is a Carmichael number."<<endl;
        }
        else{
            cout<<n<<" is normal."<<endl;
        }
   }

    return 0;
}
