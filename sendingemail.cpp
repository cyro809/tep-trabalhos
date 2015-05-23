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
#include <functional>


using namespace std;

vector< vector<pair<int, int> > > mapping;
int *dist;
int *previous;


void bfs(int curr){

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;

    pq.push(pair<int,int>(curr, 0));
    while(!pq.empty()){
        pair<int,int> top = pq.top();
        pq.pop();

        curr = top.first;
        for(unsigned int i=0;i<mapping[curr].size();i++){
            int alt = dist[curr] + mapping[curr][i].second;

            if (alt < dist[mapping[curr][i].first]){
                dist[mapping[curr][i].first] = alt;
                previous[mapping[curr][i].first] = curr;
                pq.push(pair<int,int>(mapping[curr][i].first, dist[mapping[curr][i].first]));
            }
        }

    }

}

int main()
{

    int test_cases;
    int n, m, t0, t1;
    int c1,c2, d;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++){
        cin>>n>>m>>t0>>t1;

        dist = new int[n];
        previous = new int[n];
        for(int i=0;i<n;i++){
            dist[i] = 1000001;
            previous[i] = -1;
            vector<pair<int,int> > v;
            mapping.push_back(v);
        }
        dist[t0] = 0;

        for(int i=0;i<m;i++){
            cin>>c1>>c2>>d;
            mapping[c1].push_back(pair<int,int>(c2,d));
            mapping[c2].push_back(pair<int,int>(c1,d));
        }
        bfs(t0);
        if(dist[t1] != 1000001){
            cout<<"Case #"<<t+1<<": "<<dist[t1]<<endl;
        }
        else{
            cout<<"Case #"<<t+1<<": unreachable"<<endl;
        }
        delete[] dist;
        delete[] previous;
        mapping.clear();
    }


    return 0;
}
