
#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string input;
    int num;
    int max_frequency = 0;
    map<string, int>word_frequency;

    cin>>num;

    cin>>input;

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
    return 0;
}



