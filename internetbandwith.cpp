
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
vector<vector<pair<int,int> > > mapping;
int main()
{
    int n;

    while(cin>>n){
        for(int i=0;i<=n;i++){
            vector<pair<int,int> > v;
            mapping.push_back(v);
        }
        int s,t,c;
        cin>>s>>t>>c;
        for(int i=0;i<c;i++){
            int a, b, dist;
            cin>>a>>b>>dist;
            mapping[a].push_back(pair<int,int>(b,dist));
        }

    }

    return 0;
}



