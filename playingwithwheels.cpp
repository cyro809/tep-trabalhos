#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <map>


using namespace std;

map<char[4],bool> visited;
map<char[4],vector<char[4]> > mapping;
vector<char[4]> forbNums;

vector<int> make_vector(int a)
{
    vector<int> v;
    v.push_back(a);
    return v;
}

int main()
{
    char initConfig[4];
    char target[4];
    int numForbConfig;
    char forbN;

    for(int i=0;i<4;i++){
        cin>>initConfig[i];
    }

    for(int i=0;i<4;i++){
        cin>>target[i];
    }

    cin>>numForbConfig;

    for(int n=0;n<numForbConfig;n++){
        for(int i=0;i<4;i++){
            cin>>forbN[i];
        }
        forbNums.push_back(forbN);
    }

    return 0;
}
