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

bool *visited;
int *distS;
int *distD;
vector<vector<int> > mapping;
queue<int> q;
int moves = 0;

void bfs(int curr, int* &dist){
    q.push(curr);

    while(!q.empty()){
        curr = q.front();
        q.pop();

        visited[curr] = true;
        for(unsigned int i=0;i<mapping[curr].size();i++){

            if(visited[mapping[curr][i]] == false){
                q.push(mapping[curr][i]);
                dist[mapping[curr][i]] = dist[curr] + 1;
                visited[mapping[curr][i]] = true;
            }

        }

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

    int n;
    int m;
    int c1, c2;
    int d, s;
    int maxPath = 0;
    int test_cases;

    cin>>test_cases;

    for(int t=0;t<test_cases;t++){
        cin>>n;
        visited = new bool[n];
        distD = new int[n];
        distS = new int[n];
        for(int i=0;i<n;i++){
            visited[i] = false;
            distD[i] = 0;
            distS[i] = 0;
            vector<int> v;
            mapping.push_back(v);
        }

        cin>>m;

        for(int i=0;i<m;i++){
            cin>>c1>>c2;
            mapping[c1].push_back(c2);
            mapping[c2].push_back(c1);
        }
        cin>>s>>d;
        bfs(s, distS);
        for(int i=0;i<n;i++){
            visited[i] = false;
        }
        bfs(d, distD);

        for(int i=0;i<n;i++){
            if( maxPath < distD[i] + distS[i]){
                maxPath = distD[i] + distS[i];
            }
        }
        cout<<"Case "<<t+1<<": "<<maxPath<<endl;
        delete[] distD;
        delete[] distS;
        mapping.clear();
        maxPath = 0;
        delete[] visited;
    }


    return 0;
}
