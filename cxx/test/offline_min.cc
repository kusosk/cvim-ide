#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>

using namespace std;

int find_set(vector<int>& set, int& x)
{
    if (set[x] != x)
        set[x] = find_set(set, set[x]);
    return set[x];
}

void union_set(vector<int>& set, int x, int y)
{
    int xr = find_set(set, x), yr=find_set(set, y);
    set[min(xr, yr)] = max(xr, yr);
}

vector<int> offline_min(vector<int>& A, vector<int>& E)
{
    vector<int> R(A.size(), E.size());
    int pre=0;

    copy(R.begin(), R.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (int i = 0; i< E.size(); ++i) {
        for (int j = pre; j <= E[i]; ++j) 
            R[ A[j] ] = i;
        pre = E[i]+1;
    }
    copy(R.begin(), R.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //vector<int> ret(E.size(), -1);
    vector<int> ret(E.size(), -1);
    vector<int> set(E.size()+1);
    iota(set.begin(), set.end(), 0);
    for (int i = 0; i<A.size(); ++i ) {
        if (find_set(set, R[i]) != E.size() &&
                ret[find_set(set, R[i])] == -1) {
            ret[set[R[i]]] = i;
            union_set(set, set[ R[i] ], set[ R[i] ]+1);
        }
    }


    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return ret;
}

int main()
{
    vector<int> A {10, 4, 8, 2, 5, 6, 1, 7, 12 };
    vector<int> E {2, 4, 5, 7};
    offline_min(A, E);
    return 0;
}
