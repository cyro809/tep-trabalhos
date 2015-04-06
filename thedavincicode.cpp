
#include <iostream>
#include<math.h>
#include <cstdio>
#include <stack>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string.h>

using namespace std;

double logPhi(double n) {
    const int PHI = 1.6180339887;
    return log(n) / log(PHI);
}

int indiceFibonacci(double f) {
    return (int) floor(logPhi(f * sqrt(5) + 0.5));
}

void fiboSequence(int n, map<int,int> &fb){
    int first = 0, second = 1, next, c;

   for ( c = 1 ; c < n ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      fb.push_back(pair<int,int>(next, c));
   }
}

int main()
{
    int test_cases;
    int n;

    cin>>n;

    vector<int> fib_code;
    vector<char> code;

    map<int, int> fibo_seque;

    vector<char> result;


    cin>>code;
    for(int i=0;i<n;i++) {
        cin>>fib_code[i];
    }
    for(int i=0;i<n;i++) {
        char c;
        cin>>c
        if(c >= 'A' && c <= 'Z')
            code.push_back(c);
    }

    return 0;
}



