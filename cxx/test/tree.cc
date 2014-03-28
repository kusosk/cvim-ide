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
const int IM = INT_MIN;
template<typename T>
struct TNode {
    T val;
    TNode* l;
    TNode* r;
    TNode(T& v) : val(v), l(nullptr), r(nullptr) {};
};
typedef TNode<int> TNI;

TNI* genTree_(vector<int>& d, int &p)
{
    TNI* r = nullptr;
    if (p>=d.size() || d[p] == numeric_limits<int>::min()) {
        return nullptr;
    }
    TNI* c = new TNI(d[p]);
    c->l = genTree_(d, ++p);
    c->r = genTree_(d, ++p);
    return c;
}

TNI* genTree(vector<int>& d)
{
    TNI* r = nullptr;
    if (!d.size()) return r;
    int i = 0;
    r = genTree_(d, i);
    return r;
}
void cleanupTree(TNI* r)
{
    if (!r) return ;
    cleanupTree(r->l);
    cleanupTree(r->r);
    delete r;
}
string itoa(int v)
{
    string r;
    bool neg = false;
    if (v<0) {
        neg = true;
        v = -v;
    }
    while (v) {
        int t = v%10;
        r += string(1, (char)('0'+t));
        v /= 10;
    }
    if (neg) r+="-";
    reverse(r.begin(), r.end());
    return r;
}
void treeToString_helper(TNI* r, string& s)
{
    if (!r) {
        s+="@|";
        return;
    }
    s+= itoa(r->val)+"|";
    treeToString_helper(r->l, s);
    treeToString_helper(r->r, s);
}
string treeToString(TNI* r)
{
    string res = "";
    treeToString_helper(r, res);
    return res;
}

bool isTreeBalanced_helper(TNI* r, int &h)
{
    bool res = false;
    if (!r) {  return true; }
    if (!r->l && !r->r) { h++; return true;}
    int hl = -1, hr = -1;
    return isTreeBalanced_helper(r->l, hl) && isTreeBalanced_helper(r->r, hr) && abs(hl-hr) < 2;
}

bool isTreeBalanced(TNI* r)
{
    bool res = false;
    int h = 0;
    return isTreeBalanced_helper(r, h);
}

typedef TNI TreeNode;
void h(TreeNode* r, int& m1, int& m2, int& m, TreeNode* rr){
    bool topl = r == rr;

    if (!r) {
        m1 = m2 = INT_MIN;//not m1 = m2 = m = INT_MIN; will overwrite the existsing m value
        return ;
    }
    if (!r->l && !r->r) {
        m1 = r->val;
        m2 = INT_MIN;
        m = max(m, m1);
        return ;
    }

    int lm1, lm2, rm1, rm2;
    h(r->l, lm1, lm2, m, rr);
    h(r->r, rm1, rm2, m, rr);
    m1 = max(r->val, max(lm1==INT_MIN?INT_MIN:lm1+r->val, rm1==INT_MIN?INT_MIN:rm1+r->val));
    m2 = max(lm1, max(lm2, max(rm1, rm2)));
    m = max(m, max(m1, m2));
    if (lm1!=INT_MIN && rm1!=INT_MIN) { // update m2 value to not populate up to r's parent
        if (r->val+lm1+rm1 > m) {
            m2 = r->val+lm1+rm1;
            m = m2;
        }
    }
    //cout << "@["<<r->val<<"]\tm1=" << m1 << "\tm2="<<m2<<"\tm="<<m<<endl;
}
int maxPathSum(TreeNode *root) {
    int m=INT_MIN, m1, m2;
    h(root, m1, m2, m, root);
    return m;
}
TNI* MT(vector<int> &ps, vector<int> &is, int l, int r, int &p) {
    int sz=ps.size();
    if (p >= sz || l < 0 || r >= ps.size() || l > r) return nullptr;
    TNI* root= new TreeNode(ps[++p]);
    cout << ps[p] << endl;
    auto pos = find(is.begin(), is.end(), ps[p]);
    assert(pos != is.end());
    int k = pos-is.begin();
    root->l=MT(ps, is, l, k-1, p);
    root->r=MT(ps, is, k+1, r, p);
    return root;
}
void t(int i)
{
    vector<vector<int> > res(i, vector<int>(i));
    res[0][0] = 12;
    cout << res[0][0] << endl;
}
vector<vector<int> > generateMatrix(int n) {
    assert(n);
    if (n==1) {
        vector<vector<int> > res(1);
        res[0].push_back(1);
        return res;
    }
    vector<vector<int> > res(n, vector<int>(n)); 
    int stp=0;
    int i=0, j=0, k=1;
    int sc=(n-1)>>1;// wrong sc=n>>1
    // not work if n == 1
    while(stp <= sc) {//wrong: while(stp < sc)
        for (i=stp, j = stp; j < n-stp-1; ++j)
            res[i][j] = k++;
        for (; i < n-stp-1; ++i)
            res[i][j] = k++;
        for (; j>stp; --j)
            res[i][j] = k++;
        for (; i>stp; --i)
            res[i][j] = k++;//not res[i][j] = k++;
        stp++;
    }
    return res;
}

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    int stp=0, i, j;
    if (!matrix.size()) return res;

    return res;
}

int main()
{
    vector<int> d {1, 3, INT_MIN, -2, INT_MIN, INT_MIN, 5, 4, INT_MIN, 6, 8, INT_MIN, INT_MIN, 10, INT_MIN, INT_MIN, INT_MIN};
    TNI* nr = genTree(d);
    cout << treeToString(nr) << endl;
    cleanupTree(nr);
    vector<int> d1 {-3, -4, IM,IM, 0, 0,IM, 7,IM,IM,1,IM,-3,IM, IM};
    TNI* t2 = genTree(d1);
    cout << treeToString(t2) << endl;
    cout << maxPathSum(t2) << endl;
    cleanupTree(t2);

    vector<int> ps{1,2};
    vector<int> is{2,1};
    int p = -1;
    TNI* r3 = MT(ps, is, 0, 1, p);
    cout << treeToString(r3) << endl;
    cleanupTree(r3);

    vector<vector<int> > res = generateMatrix(2);
    return 0;
}
