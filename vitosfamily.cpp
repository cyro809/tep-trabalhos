
#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <cstdio>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int test_cases;
    int family_members;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++) {
        cin>>family_members;

        int median;
        int distance = 0;
        vector<int> houses;

        for(int f=0;f<family_members;f++) {
            int house;
            cin>>house;
            houses.push_back(house);

        }

        sort(houses.begin(), houses.end());

        if(houses.size()%2 != 0) {
            median = houses[houses.size()/2];
        }
        else {
            int m1 = houses[houses.size()/2 - 1];
            int m2 = houses[houses.size()/2];
            median = (m1+m2)/2;

        }

        for(int i=0;i<houses.size();i++) {
            distance += abs(median - houses[i]);
        }

        cout<<distance<<endl;
    }

    return 0;
}



