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
#include <queue>


using namespace std;

bool* visited;
int* color;
vector<vector<int> > mapping;
queue<int> q;

int isBipartite(int curr){

    int total = 0;
    int color1 = 0;
    q.push(curr);
    color[curr] = 1;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        total++;
        if(color[curr] == 1) color1++;

        for (int i = 0; i < mapping[curr].size() ; i++)
        {
            int v = mapping[curr][i];
            if (color[v] == -1)
            {
                color[v] = 1 - color[curr];
                q.push(v);
            }

            else if (color[v] == color[curr])
                return -1;
        }


    }
    if(total == 1) return 1;

    if(color1 > 0 && total-color1 > 0){
        return min(color1, total-color1);
    }
    else{
        return max(color1, total-color1);
    }

}


vector<int> make_vector(int a)
{
    vector<int> v;
    v.push_back(a);
    return v;
}

int main()
{
    int n, m;
    int x,y;
    int test_cases;
    int ans =0;
    bool impossible = false;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++){
        cin>>n>>m;
        color = new int[n];
        for (int i = 0; i < n; i++) {
            color[i] = -1;
            vector<int> v;
            mapping.push_back(v);
        }

        for(int i=0;i<m;i++){
            cin>>x>>y;
            mapping[x].push_back(y);
            mapping[y].push_back(x);

        }

        for(int i=0;i<n;i++){
            if( color[i] == -1){
                int result = isBipartite(i);
                if(result == -1){
                    impossible = true;
                    break;
                }
                else{
                    ans += result;
                }

            }

        }

        if(impossible)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;

        mapping.clear();
        queue<int> empty_q;
        swap(q, empty_q);
        delete[] color;
        ans = 0;
        impossible = false;
    }
    return 0;
}
