#include <iostream>
#include<math.h>

using namespace std;

int balconing()
{
    float l;
    float d;
    float v;
    float h;

    int test_cases;

    cin>>test_cases;
    for(int i=0 ; i<test_cases; i++){
        cin>>l;
        cin>>d;
        cin>>h;
        cin>>v;

        float gravity = 9810;
        float time = sqrt(-h/ -(gravity/2));

        float distance_travelled = v*time;

        if( distance_travelled < d - 500 || distance_travelled > d + l + 500) {
            cout<<"FLOOR\n";
        }
        else if(distance_travelled < (d + l - 500) && distance_travelled > (d + 500)){
            cout<<"POOL\n";
        }
        else{
            cout<<"EDGE\n";
        }
    }

    return 0;
}

