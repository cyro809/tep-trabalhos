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

//int *indegree;
//bool *visited;
vector<bool> visited;
vector<int> indegree;
vector<vector<int> > mapping;

void dfs(int n){
    visited[n] = true;

    vector<int>::iterator it;
    for(it = mapping[n].begin(); it != mapping[n].end(); it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }
}

int main()
{

    int n, r;
    int c1, c2;
    bool euler = true;

    while(cin>>n>>r){
        if( r == 0)
            euler = false;

        if(euler){
            //indegree = new int[n];
            //visited = new bool[n];

            for(int i=0;i<n;i++){
//                indegree[i] = 0;
//                visited[i] = false;
                visited.push_back(false);
                indegree.push_back(0);
                vector<int> v;
                mapping.push_back(v);
            }
            for(int i=0;i<r;i++){
                cin>>c1>>c2;
                indegree[c1]++;
                indegree[c2]++;
                mapping[c1].push_back(c2);
                mapping[c2].push_back(c1);
            }
            dfs(c1);
            for(int i=0;i<n;i++){
                if(indegree[i] > 0){
                    if(indegree[i]%2 != 0 || !visited[i])
                        euler = false;
                }
            }
        }

        if(euler){
            cout<<"Possible"<<endl;
        }
        else{
            cout<<"Not Possible"<<endl;
        }
//        delete[] visited;
//        delete[] indegree;
        visited.clear();
        indegree.clear();
        mapping.clear();
        euler = true;
    }

    return 0;
}
