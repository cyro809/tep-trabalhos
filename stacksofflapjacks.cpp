
#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>


using namespace std;

void flipStack(int arr[], int i)
{
    int temp;
    int start = 0;
    while(start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int maxIndex(int arr[], int n) {
    int max_index = 0;
    for(int i =1; i<n; i++) {
        int newnumber = arr[i];
        if(newnumber > arr[max_index]) {
            max_index = i;
        }
    }

    return max_index;
}

int main()
{
    int input;
    int flips = 0;
    int max_index;
    string line;
    while(true) {

        vector<int> flapjack;
        getline(cin, line);
        if(line.length() == 0)
            break;
        istringstream stream(line);
        while (stream >> input)
            flapjack.push_back(input);


        int numbers[flapjack.size()];
        int n = sizeof(numbers)/sizeof(numbers[0]);
        copy(flapjack.begin(), flapjack.end(), numbers);
        for(int i=0;i<flapjack.size();i++) {
            cout<<numbers[i]<<" ";
        }
        cout<<endl;
        for(int i=n;i>1;i--) {
            max_index = maxIndex(numbers, i);
            if(max_index != i-1) {

                flipStack(numbers, max_index);


                flipStack(numbers, i-1);

                flips++;
                if(max_index != 0)
                    cout<<n-max_index<< " ";
                cout<<n-i+1<<" ";
            }
        }
        cout<<"0"<<endl;
        flips = 0;
    }

    return 0;
}



