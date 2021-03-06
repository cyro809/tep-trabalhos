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

int numRoots = 0;
int root = -1;
int test_case = 1;
bool isTree = true;
map<int,bool> visited;
map<int, int> indegree;
map<int,vector<int> > mapping;

vector<int> make_vector(int a)
{
    vector<int> v;
    v.push_back(a);
    return v;
}

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
    int x,y;

    while(true){
        cin>>x>>y;
        if(x == -1 && y == -1)
            break;
        else if( x == 0 && y == 0){
            map<int, int>::iterator it;

            for(it = indegree.begin(); it != indegree.end(); it++) {
                if(it->second == 0){
                    root = it->first;
                    numRoots++;
                }
                if (numRoots > 1) {
                    isTree = false;

                    break;
                }
            }
            if(isTree){
                dfs(root);
                map<int, bool>::iterator it2;
                for( it2= visited.begin(); it2!= visited.end(); it2++){
                    if(!it2->second){
                        isTree = false;

                        break;
                    }
                }
            }

            if(isTree){
                cout<<"Case "<<test_case<<" is a tree."<<endl;
            }
            else{
                cout<<"Case "<<test_case<<" is not a tree."<<endl;
            }
            mapping.clear();
            visited.clear();
            indegree.clear();
            test_case++;
            isTree = true;
            numRoots = 0;
            root= -1;

        }
        else {
            if(mapping.find(x) == mapping.end()){
                mapping.insert(pair<int,vector<int> >(x, make_vector(y)));
                visited.insert(pair<int,bool>(x,false));
                indegree.insert(pair<int,int>(x,0));
                if(mapping.find(y) == mapping.end()){
                    vector<int> v;
                    mapping.insert(pair<int,vector<int> >(y, v));
                    visited.insert(pair<int,bool>(y,false));
                    indegree.insert(pair<int,int>(y,1));
                }
                else{
                    indegree[y] = indegree[y] + 1;
                    if (indegree[y] > 1) {
                        isTree = false;
                    }
                }
            }
            else{
                mapping[x].push_back(y);

                if(mapping.find(y) == mapping.end()){
                    vector<int> v;
                    mapping.insert(pair<int,vector<int> >(y, v));
                    visited.insert(pair<int,bool>(y,false));
                    indegree.insert(pair<int,int>(y,1));
                }
                else{
                    indegree[y] = indegree[y] + 1;
                    if (indegree[y] > 1) {
                        isTree = false;
                    }
                }
            }
        }


    }
    return 0;
}
