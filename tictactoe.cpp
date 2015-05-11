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

int main()
{
    string lines[4];
    int test_cases;

    cin>>test_cases;
    cin.ignore();
    std::ifstream infile("input.txt");

    for(int t=0;t<test_cases;t++){
        int x_count = 0;
        int o_count = 0;
        bool x_wins = false;
        bool o_wins = false;
        for(int i=0;i<4;i++){
            getline(infile, lines[i]);
            //getline(cin, lines[i]);
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(lines[i][j] == 'X'){
                    x_count++;
                }
                else if(lines[i][j] == 'O'){
                    o_count++;
                }
            }
        }
        if(o_count > x_count){
            cout<<"no"<<endl;
        }
        else{
            for(int i=0;i<3;i++){
                char type = lines[i][0];
                if(lines[i].find_first_not_of(type) == string::npos){
                    if(type == 'X'){
                        x_wins = true;
//                        cout<<"x wins 1"<<endl;
                    }
                    else if(type == 'O'){
                        o_wins = true;
//                        cout<<"o wins 1"<<endl;
                    }
                }
                else if( (type == lines[1][1] && type == lines[2][2]) ||
                        (type == lines[1][1] && type == lines[2][0]) ){
                    if(type == 'X'){
                        x_wins = true;
//                        cout<<"x wins 2"<<endl;
                    }
                    else if(type == 'O'){
                        o_wins = true;
//                        cout<<"o wins 2"<<endl;
                    }
                }
                else if(lines[0][i] == lines[1][i] && lines[0][i] == lines[2][i] && lines[0][i] != '.'){
//                    cout<<lines[0][i] <<" "<<lines[1][i]<<" "<<lines[2][i]<<endl;
                    if(lines[0][i] == 'X'){
                        x_wins = true;
//                        cout<<"x wins 3"<<endl;
                    }
                    else if(lines[i][0] == 'O'){
                        o_wins = true;
//                        cout<<"o wins 3"<<endl;
                    }
                }
            }
//            cout<<"x_count "<<x_count<<" -=- o_count "<<o_count<<endl;
            if((o_wins && o_count == x_count && (!x_wins)) ||
               (!o_wins && !x_wins && x_count == o_count+1) ||
               (x_wins && x_count == o_count+1)){
                cout<<"yes"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
    }


    return 0;
}
