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

map<vector<int>,bool> visited;
map<vector<int>,int > mapping;
vector<vector<int> > forbNums;
queue<vector<int> > q;
int moves = 0;

void bfs(vector<int> curr, vector<int> objective){

    bool result = false;

    q.push(curr);

    while(!q.empty()){
        curr.clear();
        curr = q.front();
        q.pop();
        if(visited[curr] == true) continue;

        visited[curr] = true;

        if(curr == objective){
            result = true;
            break;
        }

        for(int i=0;i<4;i++){
            vector<int> next = curr;

            next[i] += 1;
            next[i] %= 10;
            if(visited[next] == false){
                q.push(next);
            }
            mapping[next] = mapping[curr] + 1;

            next = curr;
            next[i] -= 1;
            if(next[i] == -1) next[i] = 9;

            if(visited[next] == false){
                q.push(next);
            }
            mapping[next] = mapping[curr] + 1;
        }

    }

    if(result){
        cout<<mapping[objective]<<endl;
    }
    else{
        cout<<"-1"<<endl;
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
    vector<int> initConfig;
    vector<int> target;
    int numForbConfig;
    vector<int> forbN;
    int test_cases;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++){
        initConfig.clear();

        for(int i=0;i<4;i++){
            int n;
            cin>>n;

            initConfig.push_back(n);
        }

        mapping[initConfig] = 0;

        for(int i=0;i<4;i++){
            int n;
            cin>>n;

            target.push_back(n);
        }

        cin>>numForbConfig;

        for(int n=0;n<numForbConfig;n++){
            forbN.clear();
            for(int i=0;i<4;i++){
                int n;
                cin>>n;
                forbN.push_back(n);
            }
            visited[forbN] = true;
        }

        bfs(initConfig, target);

        visited.clear();
        mapping.clear();
        queue<vector<int> > empty_q;
        swap(q, empty_q);
        initConfig.clear();
        target.clear();
        forbN.clear();
    }

    return 0;
}
