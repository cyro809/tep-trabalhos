
#include <iostream>
#include<math.h>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string.h>

using namespace std;

int main()
{
    string word1, word2;
    vector<char> common_letters;
    while(true) {
        getline(cin,word1);

        if(word1.length() == 0)
            break;

        getline(cin,word2);

        if(word2.length() == 0)
            break;


        for(int i=0;i<word1.length();i++) {
            for(int j=0;j<word2.length();j++) {
                if(word1[i] == word2[j]){
                    common_letters.push_back(word1[i]);
                    word2[j] = ' ';
                    break;
                }
            }
        }

        sort(common_letters.begin(), common_letters.end());
        for(int i=0;i<common_letters.size();i++){
            cout<<common_letters[i];
        }
        cout<<endl;
        common_letters.clear();
    }
    return 0;
}
