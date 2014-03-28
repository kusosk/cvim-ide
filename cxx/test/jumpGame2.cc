#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <queue>
#include    <set>
#include    <deque>
#include    <list>
#include    <stack>
#include    <iterator>
#include    <cassert>
#include    <memory>
#include    <unordered_map>
#include    <unordered_set>

using namespace std;
int jh(int A[], int n, int k) {
    int res=INT_MAX;
    if (k>=n-1) return 0;
    if (A[k]<=0) return INT_MAX;
    int sn=A[k];
    while(sn>0) {
        if (sn+k>=n-1) return 1;
        int cr = jh(A,n,k+sn);
        if (cr!=INT_MAX)
            res = min(res, cr+1);
        //res = res==INT_MAX?INT_MAX:res+1;//careful about the overflow
        sn--;
    }
    return res;
}
int jump(int A[], int n) {
    if (n<=0) return INT_MAX;
    return jh(A, n, 0);
}

void print(vector<int>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
}

void dedup(vector<int>& v, int max)
{
    if (!v.size()) return;
    unordered_map<int, int> cnt;
    for (int pos=0; pos<v.size(); ++pos) {
        if (cnt.find(v[pos])==cnt.end()) {
            cnt.emplace(v[pos], 1);
        } else {
            if (cnt[v[pos]] == max)
                continue;
            cnt[v[pos]]++;
        }
    }
    int pos=0, npos=0;
    for (; pos<n; ++pos) {
        auto pRec=cnt.find(v[pos]);
        int refcnt=(*pRec).second;
        while(refcnt--) 
            v[npos++] = elem.first;
    }
    v.resize(npos);
}

int main()
{
    int A[] {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    //cout << jump(A, 31)<<endl;

    vector<int> v {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    vector<int> v1 {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    sort(v1.begin(), v1.end());
    print(v1);

    dedup(v, 3);
    sort(v.begin(), v.end());
    print(v);
    return 0;
}
