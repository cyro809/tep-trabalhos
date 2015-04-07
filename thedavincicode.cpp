
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

void fiboSequence(int n, map<int,int> &fb){
    int first = 0, second = 1, next, c;

   for ( c = 0 ; c < n ; c++ )
   {
      next = first + second;
      first = second;
      second = next;
      fb.insert(pair<int,int>(next, c));
   }
}

int main()
{
    int test_cases;
    int n;


    cin>>test_cases;

    for(int t=0;t<test_cases;t++){
        cin>>n;
        int cont = 0;
        int max_index = 0;

        vector<int> fib_code;
        vector<char> code;

        map<int, int> fibo_seque;

        vector<char> result;

        for(int i=0;i<100;i++) {
            result.push_back(' ');
            code.push_back(' ');
        }

        for(int i=0;i<n;i++) {
            int f;

            scanf("%d", &f);

            fib_code.push_back(f);

        }

        char c;
        scanf("%c", &c);

        while(true) {
            scanf("%c", &c);

            if ( c == '\n') break;

            if(((c >= 'A') && (c <= 'Z'))){
                code[cont] = c;
                cont++;
            }
        }

        fiboSequence(46, fibo_seque);

        for(int i=0;i<n;i++) {
            if(fibo_seque.count(fib_code[i]) > 0){
                result[fibo_seque[fib_code[i]]] = code[i];

                if(max_index < fibo_seque[fib_code[i]]){
                    max_index = fibo_seque[fib_code[i]];
                }
            }
        }

        for(int i=0;i<=max_index;i++) {
            cout<<result[i];
        }

        cout<<endl;

        fib_code.clear();
        code.clear();
        fibo_seque.clear();

    }

    return 0;
}
