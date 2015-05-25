#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>



using namespace std;

int main()
{
    int n;
    int *p;
    int *m;
    vector<int> sequence;
    while(cin>>n){

        sequence.push_back(n);
    }
    p = new int[sequence.size()];
    m = new int[sequence.size() + 1];

    int l =0;


    for(int i =0; i < sequence.size(); i++){
        int l0 = 1;
        int hi = l;

        while (l0 <= hi){
            int mid = ceil((l0+hi)/2);
            if(sequence[m[mid]] < sequence[i]){
                l0 = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        int newL = l0;

        p[i] = m[newL-1];
        m[newL] = i;

        if(newL > l){
            l = newL;
        }
    }

    int s[l];
    int k = m[l];

    for(int i=l-1;i>=0;i--){
        s[i] = sequence[k];
        k = p[k];
    }

    cout<<l<<endl;
    cout<<"-"<<endl;
    for(int i=0;i<l;i++){
        cout<<s[i]<<endl;
    }

    return 0;
}
