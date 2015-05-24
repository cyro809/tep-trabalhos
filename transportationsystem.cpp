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

vector<pair<pair<int,int>, double> > mapping;
vector<pair<int,int> > coord;
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

void Union(int &x, int &y){
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
        if(ranking[i] == ranking[j]) ranking[j]++;
    }
    counter--;
}

void kruskal(){

}

struct sort_pred {
    bool operator()(const std::pair<pair<int,int>,double> &left, const std::pair<pair<int,int>, double> &right) {
        return left.second < right.second;
    }
};



int main()
{

    int test_cases;
    int n, m;
    int x, y;
    double ans;
    double roads, railroads;
    int states;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++){
        ans = 0.0;
        states = 1;
        cin>>m>>n;
        id = new int[m];
        ranking = new int[m];
        counter = m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            coord.push_back(pair<int,int>(x,y));

            id[i] = i;
            ranking[i] = 0;
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
//                cout<<"c[i].first = "<<coord[i].first<<"   c[j].first = "<<coord[j].first<<endl;
//            cout<<"c[i].second = "<<coord[i].second<<"   c[j].second = "<<coord[j].second<<endl;
                int dx = abs(coord[i].first-coord[j].first);
                int dy = abs(coord[i].second-coord[j].second);
//                cout<<"dx = "<<dx<<"  dy = "<<dy<<endl;
                double distance = sqrt(dx*dx + dy*dy);
                //distance = round(distance);
//                cout<<"distance = "<<distance<<endl;
                mapping.push_back(pair<pair<int,int>, double>(pair<int,int>(i,j), distance));

            }
        }
        std::sort(mapping.begin(), mapping.end(), sort_pred());

        roads = 0.0;
        railroads = 0.0;
        for(int i=0;i<mapping.size();i++){
            int u = mapping[i].first.first;
            int v = mapping[i].first.second;
//            cout<<"u = "<<u<<"   v = "<<v<<endl;
//            cout<<"counter = "<<counter<<endl;

            if(Find(u) != Find(v)){
                Union(u,v);
                ans = mapping[i].second;
                if(ans > n){
                    railroads += ans;
                    states++;
                }
                else{
                    roads += ans;
                }
                //cout<<"map[i] = "<<ans<<endl;
            }
        }

        railroads = round(railroads);
        roads = round(roads);
        cout<<"Case #"<<t+1<<": "<<states<<" "<<roads<<" "<<railroads<<endl;

        delete[] id;
        delete[] ranking;
        mapping.clear();
        coord.clear();

    }


    return 0;
}
