#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <utility>


using namespace std;

vector<long long> states;

bool calculateStates(long long s, long long d, long long month){

    if(month == 12){
        long long max_year =0;
        max_year = states[0];
        for(long long i=0;i<states.size();i++){

            if(states[i] > max_year){
                max_year = states[i];
            }
        }

        if(max_year >= 0){
            cout<<max_year<<endl;
        }
        else{
            cout<<"Deficit"<<endl;
        }

        return true;
    }


    vector<long long> months;
    long long total =0;
    long long year =0;
    bool deficit = true;
    for(int i=0;i<12;i++){
        months.push_back(s);
        if(i<month){
            months[i] = -d;
        }
        year += months[i];
    }


    while(next_permutation(months.begin(),months.end())){
        deficit = true;
        for(int i=0;i<8;i++){
            total = 0;
            for(int j=0;j<5;j++){
                total += months[i+j];
            }
            if(total > 0){
                deficit = false;
                break;
            }
        }
        if(deficit){
            states.push_back(year);
            break;
        }
        else{
        }
    }
    calculateStates(s,d,month+1);
    return true;
}

int main()
{
    long long d, s;

    while(cin>>s>>d){
        calculateStates(s,d,1);


        states.clear();
    }

    return 0;
}
