#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <string.h>


using namespace std;
vector<int> G[20];
int dp[201][21];

int buy(int m, int c){
    if(m<0) return -2;
    if(c == 0) return 0;
    int &ret = dp[m][c];
    if(ret!= -1) return ret;
    ret = -2;
    for(unsigned int i=0; i<G[c-1].size();i++){
        int ci = G[c-1][i];
        if (buy(m-ci, c-1) != -2)
            ret = max(ret, buy(m-ci, c-1) + ci);
    }

    return ret;
}

int main()
{

    int test_cases;
    int M, C;

    cin>>test_cases;

    for(int t=0;t<test_cases;t++){
        cin>>M>>C;

        for(int i=0;i<C;i++){
            int K;
            cin>>K;
            G[i].resize(K);
            for(int j=0;j<K;j++){
                cin>>G[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));

        if(buy(M,C) < 0) cout<<"no solution"<<endl;
        else cout<<buy(M,C)<<endl;

        for(int i=0; i<20;i++){
            G[i].clear();
        }
    }


    return 0;
}
