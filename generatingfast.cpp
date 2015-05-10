#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{
    int test_cases;

    string input;

    cin>>test_cases;

    for(int t=0;t<test_cases;t++){
        cin>>input;
        sort(input.begin(),input.end());
        string::iterator it;

        cout<<input<<endl;
        while(next_permutation(input.begin(),input.end())){
            cout<<input<<endl;
        }

        cout<<endl;
    }



    return 0;
}
