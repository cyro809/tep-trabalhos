#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <utility>


using namespace std;

int main()
{
    vector<pair<int,int> > fractions;
    int total;
    int k;

    while(cin>>k){
        total = 0;

        for(int i=k+1;i<=k*2;i++){
            if((i*k)%(i-k) == 0){
                total++;
                fractions.push_back(make_pair((i*k)/(i-k),i));
            }
        }
        cout<<total<<endl;
        for(int i=0;i<total;i++){
            cout<<"1/"<<k<<" = 1/"<<fractions[i].first<<" + 1/"<<fractions[i].second<<endl;
        }
        fractions.clear();
    }

    return 0;
}
