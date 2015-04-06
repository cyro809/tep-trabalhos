
#include <iostream>
#include<math.h>
#include <cstdio>
#include <map>
#include <vector>
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

   for ( c = 0 ; c < n ; c++ )
   {
      next = first + second;
      first = second;
      second = next;
      cout<<"NUM= "<<next<<" ---- Index: "<<c<<endl;
      fb.insert(pair<int,int>(next, c));
   }
}

int main()
{
    int test_cases;
    int n;
    string line = "";
    cin>>n;
    int cont = 0;
    vector<int> fib_code;
    vector<char> code;

    map<int, int> fibo_seque;

    vector<char> result;


    for(int i=0;i<n;i++) {
        int f;
        scanf("%d", &f);
        fib_code.push_back(f);
        result.push_back(' ');
    }
    char c;
    scanf("%c", &c);
    while(true) {
        scanf("%c", &c);

        if ( c == '\n') break;
        if(((c >= 'A') && (c <= 'Z')) || (c == ' ')){
            cout<<c<<endl;
            cont++;
            code.push_back(c);
        }

    }

    fiboSequence(cont, fibo_seque);
    for(int i=0;i<cont;i++) {
        result[fibo_seque[fib_code[i]]+1] = code[i];
        cout<<"FIBO_CODE "<<fib_code[i]<<" ---- FIBO_SEQUE "<<fibo_seque[fib_code[i]]<<endl;

    }

    for(int i=0;i<n;i++) {
        cout<<result[i];
    }
    cout<<endl;

    return 0;
}



