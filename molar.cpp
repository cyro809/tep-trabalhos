//
//  main.cpp
#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <cstdio>


using namespace std;

int main()
{
    string input;
    int quantity[4];
    float molar_mass;
    int test_cases;

    cin>>test_cases;

    for(int t=0;t<test_cases;t++)
    {
       cin>>input;
        molar_mass = 0;
        for(int i =0; i<4;i++) {
            quantity[i] = 0;
        }

        for (int i = 0; i < input.length(); i++) {
            string sub_string = input.substr(i, 3);
            if (!isdigit(sub_string[0])) {

                if (sub_string[0] == 'C') {

                    if (isdigit(sub_string[1])) {
                        quantity[0] += atoi (sub_string.substr(1,2).c_str());
                    }
                    else {
                        quantity[0] += 1;
                    }
                }
                else if (sub_string[0] == 'H') {

                    if (isdigit(sub_string[1])) {
                        quantity[1] += atoi (sub_string.substr(1,2).c_str());
                    }
                    else {
                        quantity[1] += 1;
                    }
                }
                else if (sub_string[0] == 'O') {

                    if (isdigit(sub_string[1])) {
                        quantity[2] += atoi (sub_string.substr(1,2).c_str());
                    }
                    else {
                        quantity[2] += 1;
                    }
                }
                else if (sub_string[0] == 'N') {

                    if (isdigit(sub_string[1])) {
                        quantity[3] += atoi (sub_string.substr(1,2).c_str());
                    }
                    else {
                        quantity[3] += 1;
                    }
                }

            }
        }

        molar_mass = quantity[0] * 12.01 + quantity[1] * 1.008 + quantity[2] * 16.00 + quantity[3] * 14.01;

        printf("%.3f\n", molar_mass);
    }

    return 0;
}



