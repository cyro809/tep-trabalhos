
#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    string input;
    int test_cases;
    int score;
    int streak;

    cin>>test_cases;

    for(int t=0; t<test_cases;t++) {
        cin>>input;

        score = 0;
        streak = 0;

        for(int i=0;i<input.length();i++){
            if(input[i] == 'O') {
                streak++;
                score = score + streak;
            }
            else {
                streak = 0;
            }
        }
        cout<<score<<"\n";
    }

    return 0;
}

