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

vector<int> make_vector(int a)
{
    vector<int> v;
    v.push_back(a);
    return v;
}

int main()
{
    int x,y;
    map<int,bool> visited;
    map<int, int> indegree;
    map<int,vector<int> > mapping;
    while(true){
        cin>>x>>y;
        if(x == -1 && y == -1)
            break;

        if(mapping.find(x) == mapping.end()){
            mapping.insert(pair<int,vector<int> >(x, make_vector(y)));
            visited.insert(pair<int,bool>(x,false));
            indegree.insert(pair<int,int>(x,0));
            if(mapping.find(y) == mapping.end()){
                vector<int> v;
                mapping.insert(pair<int,vector<int> >(x, v));
                visited.insert(pair<int,bool>(y,false));
                indegree.insert(pair<int,int>(y,1));
            }
            else{
                indegree[y]++;
            }
        }
        else{
            mapping[x].push_back(y);
            if(mapping.find(y) == mapping.end()){
                vector<int> v;
                mapping.insert(pair<int,vector<int> >(x, v));
                visited.insert(pair<int,bool>(y,false));
                indegree.insert(pair<int,int>(y,1));
            }
            else{
                indegree[y]++;
            }
        }


    }

    map<int, vector<int> >::iterator it_type;
    for(it_type = mapping.begin(); it_type != mapping.end(); it_type++) {
        cout<<it_type->first<<"  adj size = "<<it_type->second.size()<<endl;
    }

    map<int, int>::iterator it;
    for(it = indegree.begin(); it != indegree.end(); it++) {
        cout<<it->first<<"  indegree = "<<it->second<<endl;
    }
    return 0;
}
