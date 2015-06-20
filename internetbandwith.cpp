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
#include <climits>

using namespace std;

int n;
int **graph;
int **rGraph;

bool bfs(int s, int t, int parent[])
{

    bool visited[n];
    memset(visited, false, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;


    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<n; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

int fordFulkerson(int s, int t)
{
    int u, v;

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
             rGraph[u][v] = graph[u][v];

    int parent[n+1];

    int max_flow = 0;


    while (bfs(s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int network_number = 1;
    while(cin>>n){
        if(n == 0)
            break;
        n++;

        graph = new int*[n];
        rGraph = new int*[n];

        for(int i=0;i<n;i++){
            graph[i] = new int[n];
            rGraph[i] = new int[n];

            for(int j=0;j<n;j++){
                graph[i][j] = 0;
            }
        }

        int s,t,c;

        cin>>s>>t>>c;

        for(int i=0;i<c;i++){
            int a, b, capacity;

            cin>>a>>b>>capacity;

            graph[a][b] += capacity;
            graph[b][a] += capacity;

        }

        cout<<"Network "<<network_number<<endl;
        cout<<"The bandwidth is "<<fordFulkerson(s, t)<<"."<<endl;
        cout<<endl;

        for(int i=0;i<n;i++){
            delete[] graph[i];
            delete[] rGraph[i];
        }

        delete[]graph;
        delete[] rGraph;

        network_number++;
    }

    return 0;
}
