
#include <iostream>
#include<math.h>
#include <cstdio>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int test_cases;
    int n;
    int n_reverse;

    cin>>n;

    string Result;          // string which will contain the result

    ostringstream convert;   // stream used for the conversion

    convert << n;      // insert the textual representation of 'Number' in the characters in the stream

    Result = convert.str();
    reverse(Result.begin(), Result.end());

    n_reverse = atoi(Result.c_str());

    cout<<n_reverse<<endl;
    return 0;
}
