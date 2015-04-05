
#include <iostream>
#include<math.h>
#include <cstdio>
#include <stack>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string.h>

using namespace std;

void topologicalSort(list<int> *adj, bool visited[], int curr, stack<int> &st) {
    visited[curr] = true;

    list<int>::iterator i;
    for(i = adj[curr].begin();i!= adj[curr].end(); ++i) {
        if (!visited[*i])
            topologicalSort(adj,visited, *i, st);
    }
    st.push(curr);
}

int main()
{
    int m, n;
    int i, j;

    while(true) {
        cin>>n>>m;

        list<int> *adj = new list<int>[n+1];
        stack<int> sorted_stack;

        bool *visited = new bool[n+1];

        if(m == 0 && n == 0)
            break;
        else {
            for(int x=1; x<=m;x++) {
                cin>>i>>j;

                adj[i].push_back(j);

                visited[x] = false;
            }

            visited[0] = true;

            for(int x=1;x<=n;x++) {
                if(visited[x] == false)
                    topologicalSort(adj,visited,x, sorted_stack);
            }

            while(sorted_stack.empty() == false) {
                cout<< sorted_stack.top() << " ";

                sorted_stack.pop();
            }
            cout<<endl;
            for(int x=0;x<=m;x++) {
                adj[x].clear();
            }
        }
    }


    return 0;
}



