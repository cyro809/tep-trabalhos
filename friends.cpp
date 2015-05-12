#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>


using namespace std;

int *id;
int* ranking;
int counter;

int Find(int x){
    int root = x;
    while(root != id[root]){
        root = id[root];
    }
    while(x != root){
        int newx = id[x];
        id[x] = root;
        x = newx;
    }
    return x;
}

void Union(int x, int y){
    int i = Find(x);
    int j = Find(y);
    if(i == j){
        return;
    }

    if(ranking[i] < ranking[j]){
        id[i] = j;
        ranking[j] += ranking[i];
    }
    else {
        id[j] = i;
        ranking[i] += ranking[j];
    }
    counter--;
}

int main()
{
    int n, m;
    int x,y;
    int *groups;
    int test_cases;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++){
        cin>>n>>m;
        id = new int[n];
        ranking = new int[n];
        groups = new int[n];
        counter = n;
        for (int i = 0; i < n; i++) {
            id[i] = i;
            ranking[i] = 0;
            groups[i] = 0;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            Union(x-1,y-1);

        }
        for(int i=0;i<n;i++){
            groups[id[i]]++;
        }
        int largest_group = 0;
        for(int i=0;i<n;i++){
            if(largest_group < groups[i]){
                largest_group = groups[i];
            }
        }
        cout<<largest_group<<endl;
        delete[] id;
        delete[] ranking;

    }

    return 0;
}
