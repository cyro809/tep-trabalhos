#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>


using namespace std;

int main()
{
    int n;
    int *streak;
    int x;
    int maxStreak;
    while(true){
        cin>>n;

        if(n == 0)
            break;
        streak = new int[n];

        for(int i =0;i<n;i++){
            cin>>x;
            if(i == 0){
                if(x > 0){
                    streak[i] = x;
                    maxStreak = x;
                }
                else{
                    streak[i] = 0;
                    maxStreak = 0;
                }

            }
            else{
                if(x + streak[i-1] > 0){
                    streak[i] = x + streak[i-1];
                }
                else{
                    streak[i] = 0;
                }

            }
            if(maxStreak < streak[i])
                maxStreak = streak[i];
        }
        if(maxStreak > 0){
            cout<<"The maximum winning streak is "<<maxStreak<<"."<<endl;
        }
        else{
            cout<<"Losing streak."<<endl;
        }
        delete[] streak;
    }

    return 0;
}
