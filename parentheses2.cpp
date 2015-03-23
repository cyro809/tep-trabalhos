
#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>


using namespace std;

int main()
{
    string input;

    vector<string> results;

    int i=0;
    cin>>input;

    while(input.length()) {
        if(input[i] == ' ') {
            results.push_back(input.substr(0, i));
            input = input.substr(i+1, input.length());
            i=0;
        }
        i++;
    }

    for(int i =0;i<results.size();i++) {
        cout<<results[i]<<endl;
    }


    return 0;
}



