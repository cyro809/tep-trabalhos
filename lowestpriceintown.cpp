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
    double price;
    int M;
    int test_case = 1;

    while(cin>>price>>M){
        vector<string> numbers_strings;
        vector<int> numbers;
        vector<pair<int,double> > pack_price;

        for(int i=0;i<M;i++){
            int n;
            double p;

            cin>>n>>p;
            pack_price.push_back(pair<int,double>(n,p));
        }

        vector<double> dp(101, 0);

        for (int k = 1; k <= 100; ++k)
                dp[k] = price * k;
        for (int i = 0; i < M; ++i)
        {
            int n = pack_price[i].first;
            double p = pack_price[i].second;
            for (int k = 0; k <= 100 - n; ++k)
                for (int m = 1; m <= n; ++m)
                    dp[k + m] = min(dp[k + m], dp[k] + p);
        }

        cin.ignore();

        string line;
        getline(cin, line);

        numbers_strings = split(line, ' ');

        for(unsigned int i=0; i<numbers_strings.size();i++){
            int x = atoi(numbers_strings[i].c_str());
            numbers.push_back(x);
        }

        cout<<"Case "<<test_case<<":"<<endl;

        test_case++;

        for(unsigned int i = 0; i<numbers.size();i++){
            printf("Buy %d for $%.2f\n", numbers[i], dp[numbers[i]]);
        }
    }

    return 0;
}
