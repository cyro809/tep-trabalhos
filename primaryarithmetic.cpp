
#include <iostream>
#include<math.h>
#include <cstdio>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

vector<string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main()
{

    string input;
    int carry = 0;
    bool has_carry = false;

    while(getline(cin, input)){
        vector<string> nums = split(input, ' ');
        if(nums[0][0] == '0' && nums[1][0] == '0')
            break;



        if(nums[0].length() >= nums[1].length()){
            int dif = nums[0].length() - nums[1].length();
            int result;
            for(int i=nums[1].length()-1 ; i>=0;i--){

                if(has_carry){
                    result = nums[1][i] - '0' + nums[0][i+dif] - '0' + 1;
                }
                else{
                    result = nums[1][i] - '0' + nums[0][i+dif] - '0';
                }

                if(result >= 10){
                    carry++;
                    has_carry = true;
                }
                else{
                    has_carry = false;
                }

                if(i==0 && has_carry && dif > 0) {
                    for(int j=dif-1; j>=0;j--){

                        if(has_carry)
                            result = nums[0][j] - '0' + 1;

                        if(result >= 10){
                            carry++;
                        }
                        else{
                            has_carry = false;
                        }
                    }
                }
            }
        }
        else {
            int dif = nums[1].length() - nums[0].length();
            int result;
            for(int i=nums[0].length()-1 ; i>=0;i--){

                if(has_carry){
                    result = nums[0][i] - '0' + nums[1][i+dif] - '0' + 1;
                }
                else{
                    result = nums[0][i] - '0' + nums[1][i+dif] - '0';
                }

                if(result >= 10){
                    carry++;
                    has_carry = true;
                }
                else{
                    has_carry = false;
                }

                if(i==0 && has_carry && dif > 0) {
                    for(int j=dif-1; j>=0;j--){

                        if(has_carry)
                            result = nums[1][j] - '0' + 1;

                        if(result >= 10){
                            carry++;
                        }
                        else{
                            has_carry = false;
                        }
                    }
                }
            }
        }
        nums.clear();
        if(carry > 0){
            if(carry == 1){
                cout<<"1 carry operation."<<endl;
            }
            else{
                cout<<carry<<" carry operations."<<endl;
            }

        }
        else{
            cout<<"No carry operation."<<endl;
        }
        carry = 0;
        has_carry = false;
    }
    return 0;
}
