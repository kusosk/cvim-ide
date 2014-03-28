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
void par(vector<int> &ins, int i)
{
    int l=0, r=ins.size()-1, m=0;
    int p=ins[i];
    while(l < r) {
        if (ins[l] > p) {
            swap(ins[l], ins[r]);
            --r;
            continue;
        }
        if (ins[r] < p){}
        ++l;
    }
}
void p(vector<int>& num)
{
    copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
int findKth(vector<int> &ins, int k)
{
    if (k<0 || k>ins.size()) throw invalid_argument("Index Error");
    return 0;
}
void h(vector<int> &num, int l, int t, vector<int> &curr, vector<vector<int> > &res) 
    {
        /*
        cout << "l=" << num[l] << " t="<<t<<"\t\t";
        p(curr);
        cout <<"#################\n";
        */
        if (!t) {
            if (curr.size() && find(res.begin(), res.end(), curr) == res.end()) {
                p(curr);
                res.push_back(curr);
                return;
            }
        }
        if (l==num.size() || t <num[l]) return;
        int nt = t-num[l];
        curr.push_back(num[l]);
        h(num, l+1, nt, curr, res);
        curr.pop_back();
        h(num, l+1, t, curr, res);
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int t) {
        sort(num.begin(), num.end());//, greater<int>());

    copy(num.begin(), num.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
        vector<vector<int> > res;
        vector<int> curr;
        h(num, 0, t, curr, res);
        return res;
    }

void test1()
{
    vector<int> r0{14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    vector<int> r{-2, -2, -1, -1, -1, -1, -1, 0, 0, 1};
	vector<vector<int> > res = combinationSum2(r, -5);
	for (vector<int> ri : res) {
		copy(ri.begin(), ri.end(), ostream_iterator<int>(cout, " "));
		cout <<endl << "*******************************"<<endl;
	}
}
void test0()
{

    vector<int> t{19, 2, 3, 4, 1};
    sort(t.begin(), t.end(), std::greater<int>());
    copy(t.begin(), t.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
int main()
{
    test1();
    return 0;
}
