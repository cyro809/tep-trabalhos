
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
    char word1[1000];
    char word2[1000];
    vector<char> common_letters;
    while(gets(word1) != NULL && gets(word2) != NULL) {
        for(int i=0;i<strlen(word1);i++) {
            for(int j=0;j<strlen(word2);j++) {
                if(word1[i] >= 'a' && word1[i] <= 'z'){
                    if(word1[i] == word2[j]){
                        common_letters.push_back(word1[i]);
                        word2[j] = '#';
                        break;
                    }
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
