#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <set>
#include    <algorithm>
#include    <vector>

using namespace std;
vector<int> maketuple(int a, int b, int c)
{
    if (a<=b) {
        if (b>c&&c<a) {
            swap(b,a);
            swap(c,a);
        }
    } else {
        if (c>a) {
            swap(a,b);swap(b,c);
        } else {
            if (c<b) {
                swap(a,c);
            } else {
                swap(a,b);
                swap(b,c);
            }
        }
    }
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
    return res;
}

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > res;

    size_t sz=num.size();
    if (sz < 3) return res;
    sort(num.begin(), num.end());
    for(size_t i =0; i<sz;++i) {
        int m=i+1, n=sz-1;
        while(m<n){
            if (0 == num[m]+num[n]+num[i]) {
                vector<int> curr = maketuple(num[m],num[n],num[i]); 
                if (find(res.begin(), res.end(), curr)==res.end()) {
                    res.push_back(curr);
                    break;
                }
            } else if (0 < num[m]+num[n]+num[i]) {
                n--;
            } else {
                m++;
            }
        }
    }
    return res;
}

vector<vector<int> > threeSum_(vector<int> &num) {
    vector<vector<int> > res;
    set< vector<int> > tmp;
    size_t sz=num.size();
    if (sz < 3) return res;
    sort(num.begin(), num.end());
    for(size_t i =0; i<sz;++i) {
        int m=i+1, n=sz-1;
        while(m<n){
            if (0 == num[m]+num[n]+num[i]) {
                vector<int> curr;
                curr.push_back(num[i]);
                curr.push_back(num[m]);
                curr.push_back(num[n]);
                tmp.insert(curr);
                break;
            } else if (0 < num[m]+num[n]+num[i]) {
                n--;
            } else {
                m++;
            }
        }
    }
    for (auto it=tmp.begin(); it!=tmp.end(); ++it)
        res.push_back(*it);
    return res;
}
int main()
{
    vector<int> a(3, 0);
    //cout << threeSum_(a).size() <<endl;
    return 0;
}
