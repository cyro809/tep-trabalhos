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
int *cont;

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

void Union(int &x, int &y){
    int i = Find(x);
    int j = Find(y);
    if(i == j){
        return;
    }

    if(ranking[i] < ranking[j]){
        id[i] = j;
        ranking[j] += ranking[i];
        cont[j] += cont[i];
    }
    else {
        id[j] = i;
        ranking[i] += ranking[j];
        cont[i] += cont[j];
        if(ranking[i] == ranking[j]) ranking[j]++;
    }
    counter--;
}

int main()
{
    int n, m;
    int x,y;
    int test_cases;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++){
        cin>>n>>m;
        id = new int[n];
        ranking = new int[n];
        cont = new int[n];
        counter = n;
        for (int i = 0; i < n; i++) {
            id[i] = i;
            ranking[i] = 0;
            cont[i] = 1;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            x--;
            y--;
            Union(x,y);

        }
        int largest_group = 0;
        for(int i=0;i<n;i++){
            if(largest_group < cont[i]){
                largest_group = cont[i];
            }
        }
        cout<<largest_group<<endl;
        delete[] id;
        delete[] ranking;

    }

    return 0;
}
