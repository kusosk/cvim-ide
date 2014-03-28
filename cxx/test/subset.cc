#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
    int sz=S.size();
    vector<vector<int> > r;
    if (!sz) return r;
    vector<int> curr;
    if (sz==1) {
        curr.push_back(S[0]);
        r.push_back(curr);
        return r;
    }
    sort(S.begin(), S.end());
    int i =0;
    curr.push_back(S[0]);
    r.push_back(curr);
    for (i=1; i<S.size(); ++i) {
        int l=r.size();
        for (int j=0; j<l; ++j) {
            vector<int> o = r[j];
            o.push_back(S[i]);
            r.push_back(o);
        }
        curr[0]=S[i];
        r.push_back(curr);
    }
    return r;
}
int main()
{
    vector<int> s{1,2};
    vector<vector<int> > res=subsets(s);
    cout << res.size() << endl;
    return 0;
}
