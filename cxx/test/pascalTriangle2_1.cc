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
vector<int> getRow(int r) {
    vector<int> res(r+1, 0);
    res[0]=res[1]=1;
    for (int i=2; i<=r; ++i) {
        res[i>>1] = i&1 ? res[(i>>1)-1]+res[i>>1] : res[(i>>1)-1]<<1;
        for (int j=(i>>1)-1; j>=1; --j) {
            res[j] += res[j-1];
        }
    }
    for (int i=0; i<=(r>>1); ++i)
        res[r-i] = res[i];

    return res;
}
void test(int k)
{
    for (int i = 0; i <= k; ++i) {
        vector<int> r = getRow(i);
        copy(r.begin(), r.end(), ostream_iterator<int>(cout, " "));
        cout << endl << "********************************" << endl;
    }
    cout << endl;
}
int main()
{
    test(6);
    return 0;
}
