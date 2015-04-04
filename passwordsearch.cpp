
#include <iostream>
#include<math.h>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string.h>

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
    char line[1000000];

    int num;
    int max_frequency = 0;

    map<string, int>word_frequency;

    vector<string> arguments;

    while(scanf("%d %s", &num, line) == 2) {

        arguments.clear();
        word_frequency.clear();
        input = string(line);

        if(num != 0 && input.length() > num) {
            for(int i=0;i<input.length()-(num-1);i++) {
            string word = input.substr(i, num);

            if(word_frequency.count(word)) {
                word_frequency[word] = word_frequency[word]+1;
            }
            else {
                word_frequency.insert(pair<string,int>(word, 1));
            }

            if(max_frequency < word_frequency[word])
                max_frequency = word_frequency[word];
            }

            map<string, int>::const_iterator it;
            string key = "";

            for (it = word_frequency.begin(); it != word_frequency.end(); ++it)
            {
                if (it->second == max_frequency)
                {
                    key = it->first;
                    break;
                }
            }

            cout<<key<<endl;

            word_frequency.clear();
            arguments.clear();
            max_frequency = 0;
        }
        input = "";
    }

    return 0;
}



