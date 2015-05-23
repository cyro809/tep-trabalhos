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

int main()
{

    int x0, y0, x1, y1;
    int hx, hy;
    double totalDistance = 0.0;
    int speed = 20;
    int test_cases;
    bool first = true;

    cin>>test_cases;
    for(int t=0;t<test_cases;t++){

        cin>>hx>>hy;

        string word;
		getline(cin,word);
		getline(cin,word);
        while(word.length() >0){

            istringstream instream(word);
            instream>>x0>>y0>>x1>>y1;


            int dx = abs(x0-x1);
            int dy = abs(y0-y1);

            double distance = sqrt(dx*dx + dy*dy) * 2;

            totalDistance += distance;

            getline(cin,word);
        }
        totalDistance /= 1000.0;

        double time = totalDistance/speed;
        double hour;
        double minute = modf(time, &hour);
        minute *= 60;
        minute = round(minute);
        if(minute == 60.0){
            hour++;
            minute = 0;
        }
        if(!first)
			cout << endl;
		else
			first = false;
        printf("%d:%02d\n", (int) hour, (int) minute);

        totalDistance = 0.0;
    }


    return 0;
}
