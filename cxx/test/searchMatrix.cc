#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <utility>
#include    <unordered_map>

using namespace std;
void helper(vector<string>& m, int r, int c, string&s, int p, vector<pair<int, int> > &cr, vector< vector<pair<int, int> > > &res)
{
    if (p == s.size()) {
        res.push_back(cr);
        return ;
    }
    if (m[r][c] == s[p]) {
        cr.push_back(make_pair(r, c));
        if (c+1 < m[0].size())
            helper(m, r, c+1, s, p+1, cr, res);
        if (r+1 < m.size())
            helper(m, r+1, c, s, p+1, cr, res);
        if (r>= 1)
            helper(m, r-1, c, s, p+1, cr, res);
        if (c>=1)
            helper(m, r, c-1, s, p+1, cr, res);
    }
}
vector< vector<pair<int, int> > > getLoc(vector<string>& m, string &s)
{
    vector< vector<pair<int, int> > > res;
    vector<pair<int, int> > cr;

    if (!s.size()) return res;
    helper(m, 0, 0, s, 0, cr, res);
    return res;
}

int main()
{
    vector<string> m {
        { "SNBSE"},
        {"BAKEK"},
        {"BKBBA"},
        {"SEBSN"}
    };
    string s("SNAKES");
 vector< vector<pair<int, int> > > r = getLoc(m, s);
 for (auto v : r) {
    for (auto p : v) {
        cout << p.first << ", " << p.second << endl;
    }
    cout << "**************************" << endl;
 }
    return 0;
}
