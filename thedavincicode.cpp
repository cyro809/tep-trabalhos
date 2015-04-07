
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
        vector<int> fib_code;
        vector<char> code;

        map<int, int> fibo_seque;

        vector<char> result(100,' ');


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
                cont++;
                code.push_back(c);
                //result.push_back(' ');
            }
            else if(c == ' ') {
                cont++;
                //result.push_back(' ');
            }


        }

        fiboSequence(cont, fibo_seque);
        for(int i=0;i<n;i++) {
            result[fibo_seque[fib_code[i]]] = code[i];
        }

        for(int i=0;i<result.size();i++) {
            cout<<result[i];
        }
        cout<<endl;

        fib_code.clear();
        code.clear();
        fibo_seque.clear();

    }

    return 0;
}



