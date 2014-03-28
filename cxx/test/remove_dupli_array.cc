#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <unordered_map>

using namespace std;

void rd(vector<int> &a)
{
    if (a.size() <= 1) return;
    int sz=a.size();
    sort(a.begin(), a.end());

    int p=0, e=sz-1, t;
    int cnt=0;
    for (t=p+1; p<=e; ) {
        t=p+1;
        while(t <= e) {
            if (a[t] == a[p]) {
                swap(a[t], a[e]);
                if (a[t] == a[p]) {
                    cnt+=e-t+1;
                    break;
                }
                e--;
                cnt++;
            } else{}
        }

    }
    a.resize(sz-cnt);
}

int main()
{
    
    return 0;
}
