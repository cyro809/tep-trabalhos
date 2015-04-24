
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    int test_cases;
    long long int n;
    int counter = 0;
    long long int n_reverse;
    bool palindrome = false;


    cin>>test_cases;
    for(int t=0;t<test_cases;t++){
        cin>>n;

        while(!palindrome){
            string Result;          // string which will contain the result

            ostringstream convert;   // stream used for the conversion

            convert << n;      // insert the textual representation of 'Number' in the characters in the stream

            Result = convert.str();


            reverse(Result.begin(), Result.end());

            n_reverse = atoll(Result.c_str());

            n = n + n_reverse;

            convert.str("");

            convert << n;      // insert the textual representation of 'Number' in the characters in the stream

            Result = convert.str();


            bool flag = true;
            for(int i=0;i<Result.length()/2; i++) {
                if(Result[i] != Result[Result.length()-1-i]) {
                    flag = false;
                    break;
                }
            }
            palindrome = flag;
            counter++;
        }
        cout<<counter<<" "<<n<<endl;

        counter = 0;
        palindrome = false;
    }
    return 0;
}
