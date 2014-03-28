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
void helper(string s, int k, int p, vector<string>& res, const int n)
{
    if (k < 0||p<0) return;
    if (!k) {
        if (p > 1) return;
        if (p)
            s+=")";
        if (find(res.begin(), res.end(), s) == res.end())
            res.push_back(s);
        return;
    }
    if (p>0)
        helper(s+")", k-1, p-1, res,n);
    if (p<k)
        helper(s+"(", k, p+1, res,n);
}
vector<string> generateParenthesis(int n) {
    vector<string> res;

    if (!n) return res;
    helper("(", n, 1, res, n);

    return res;
}
int main()
{
    vector<string> r = generateParenthesis(4);
    copy(r.begin(), r.end(), ostream_iterator<string>(cout, "\t"));
    cout << endl << r.size() << endl;
    return 0;
}
