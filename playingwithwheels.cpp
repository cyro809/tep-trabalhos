#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>


using namespace std;

map<vector<int>,bool> visited;
map<vector<int>,vector< vector<int> > > mapping;
vector<vector<int> > forbNums;
queue<vector<int> > q;
int moves = 0;

void bfs(vector<int> curr, vector<int> objective){
    int currentDepth = 0;
    int elementsToDepthIncrease = 1;
    int nextElementsToDepthIncrease = 0;
    bool result = false;

    visited[curr] = true;
    q.push(curr);

    while(!q.empty()){
        curr = q.front();

        visited[curr] = true;
        if(curr == objective){
            result = true;
            break;
        }
        q.pop();

        for(int i=0;i<4;i++){
            vector<int> next = curr;

            next[i] = curr[i]+1;
            next[i] %=10;
            if(find(forbNums.begin(),forbNums.end(),next) == forbNums.end()){
                mapping[curr].push_back(next);
                if(mapping.find(next) == mapping.end()){
                    visited.insert(pair<vector<int>,bool>(next,false));
                    vector<vector<int> > v;
                    mapping.insert(pair<vector<int> ,vector<vector<int> > >(next, v));
                }
            }

            next[i] = curr[i]+9;
            next[i] %= 10;

            if(find(forbNums.begin(),forbNums.end(),next) == forbNums.end()){
                mapping[curr].push_back(next);
                if(mapping.find(next) == mapping.end()){
                    visited.insert(pair<vector<int>,bool>(next,false));
                    vector<vector<int> > v;
                    mapping.insert(pair<vector<int> ,vector<vector<int> > >(next, v));
                }
            }
        }

        nextElementsToDepthIncrease += mapping[curr].size();

        if (--elementsToDepthIncrease == 0) {
            currentDepth++;
            elementsToDepthIncrease = nextElementsToDepthIncrease;
            nextElementsToDepthIncrease = 0;
        }

        vector<vector<int> >::iterator it;
        for(it = mapping[curr].begin(); it != mapping[curr].end(); it++){
            if(!visited[*it]){
                q.push(*it);
                visited[*it] = true;
            }
        }

    }

    if(result){
        cout<<currentDepth<<endl;
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

    for(int i=0;i<4;i++){
        int n;
        cin>>n;
        initConfig.push_back(n);
    }

    for(int i=0;i<4;i++){
        int n;
        cin>>n;
        target.push_back(n);
    }

    cin>>numForbConfig;

    for(int n=0;n<numForbConfig;n++){
        for(int i=0;i<4;i++){
            int n;
            cin>>n;
            forbN.push_back(n);
        }
        forbNums.push_back(forbN);
    }

    bfs(initConfig, target);

    visited.clear();
    mapping.clear();
    forbNums.clear();
    queue<vector<int> > empty_q;
    swap(q, empty_q);
    initConfig.clear();
    target.clear();
    forbN.clear();
    return 0;
}
