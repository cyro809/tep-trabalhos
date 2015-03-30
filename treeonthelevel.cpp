
#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>


using namespace std;

struct cmpByLengthAndAlphabet {
    int operator()(const string &a, const string &b) const {
        if(a.length() < b.length()) {
            return -1;
        }
        if(a.length() > b.length()) {
            return 1;
        }
        if(a.compare(b) < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }
};

string ReplaceAll(string str, const string& from, const string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int main()
{
    string input = "";
    string line;
    map<string, int>nodes;
    while(true) {
        getline(cin, line);
        input += line + " ";
        if(line.find("()") != string::npos)
            break;
    }
    input = ReplaceAll(input, "(", "");
    input = ReplaceAll(input, ")", "");


    cout<<input<<endl;
    return 0;
}



