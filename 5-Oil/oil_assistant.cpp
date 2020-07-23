#include <iostream>
#include <algorithm>
#include "oil.h"

using namespace std;

pair <int,int> ans;

inline void renew(pair < int,int >& rhs) {
    ans.first = min(ans.first,rhs.first);
    ans.second = max(ans.second,rhs.second);
}

int main()
{
    initial();
    int N = oil_size();

    int lo=0, hi=N-1;

    while(lo +1 < hi) {
        int m=(lo+hi)/2;
        if(observe(0,m) == 0) lo=m;
        else hi=m;
    }
    ans.first = lo+1;
    lo=0, hi=N-1;

    while(lo +1 < hi) {
        int m=(lo+hi)/2;
        if(observe(m,N-1) != 0) lo=m;
        else hi=m;
    }
    ans.second=lo;

    oil_report(ans.first,ans.second);


    return 0;
}
