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
    int m;
    string line;
    vector<string> numbers_strings;
    vector<int> numbers;
    
    
    vector<pair<int,int> > pack_price;
    
    cin>>price>>m;
    
    for(int i=0;i<m;i++){
        int n, p;
        
        cin>>n>>p;
        pack_price.push_back(pair<int,int>(n,p));
    }
    
    getline(cin, line);
    numbers_strings = split(line, ' ');
    for(unsigned int i=0; i<numbers.size();i++){
        int x = atoi(numbers_strings[i].c_str());
        numbers.push_back(x);
    }
    
    return 0;
}
