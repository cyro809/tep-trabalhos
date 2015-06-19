
#include <iostream>
#include<math.h>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string.h>
#include <queue>

using namespace std;

vector<vector<pair<int,int> > > graph;
vector<vector<pair<int,int> > > residual_graph;
int n;

bool bfs(int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[n+1];
    memset(visited, false, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;


    while(!q.empty()){
        int u = q.front();
        q.pop();

        visited[s] = true;
        for(unsigned int i=0;i<residual_graph[u].size();i++){

            if(visited[residual_graph[u][i].first] == false){
                q.push(residual_graph[u][i].first);
                parent[residual_graph[u][i].first] = u;
                visited[residual_graph[u][i].first] = true;
            }

        }

    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// Returns tne maximum flow from s to t in the given graph
int fordFulkerson(int s, int t)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph

    // residual capacity of edge from i to j (if there
    // is an edge. If rGraph[i][j] is 0, then there is not)
    residual_graph = graph;

    int parent[n+1];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(s, t, parent))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow

        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, residual_graph[u][v].second);
        }


        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            residual_graph[u][v].second -= path_flow;
            residual_graph[v][u].second += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}


int main()
{


    while(cin>>n){
        for(int i=0;i<=n;i++){
            vector<pair<int,int> > v;
            graph.push_back(v);
        }
        int s,t,c;
        cin>>s>>t>>c;
        for(int i=0;i<c;i++){
            int a, b, capacity;
            cin>>a>>b>>capacity;
            graph[a].push_back(pair<int,int>(b,capacity));
            graph[b].push_back(pair<int,int>(a,capacity));
        }
        cout<<fordFulkerson(s, t)<<endl;
    }

    return 0;
}



