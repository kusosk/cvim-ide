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
string next_perm(const string& s)
{
    string r(s);

    int pos=-1, j;
    for (int i = s.size()-1; i>0; --i) {
        if (r[i] > r[i-1]) {
            pos =i;
            break;
        }
    }
    if (pos == -1) return r;

    //for (j=pos+1; j<s.size(); ++j) {
    for (j=pos+1; j<s.size(); ++j) {
        if (r[j] < r[pos-1]) {
            swap(r[j-1], r[pos-1]);
            break;
        }
    }
    if (j == s.size())
        swap(r[s.size()-1], r[pos-1]);

    reverse(r.begin()+pos, r.end());
    return r;
}
void test_next_perm()
{
    string s {"0123456789"};

    int cnt = 0;
    while(cnt < 20) {
        random_shuffle(s.begin(), s.end());
        cout << s << endl;
        cout << next_perm(s) << endl << "***********************" << endl;
        cnt++;
    }

    s = "4321";
    cout << next_perm(s) <<endl;

    s = "1420";
    cout << next_perm(s) <<endl;

    s = "16543";
    cout << next_perm(s) <<endl;
}

string prev_perm(const string& s)
{
    string r(s);
    if (s.empty()) return {""};
    int pos = -1, j;
    for (int i = r.size()-1; i>0; --i) {
        if (r[i] < r[i-1]) {
            pos = i;
            break;
        }
    }   
    if (pos == -1) return {""};
    for (j = pos+1; j < s.size(); ++j) {
        if (r[j] > r[pos-1]) {
            swap(r[j-1], r[pos-1]);
            break;
        }
    }
    if (j == r.size()) swap(r[r.size()-1], r[pos-1]);
    reverse(r.begin()+pos,r.end());
    return r;
}

void test_prev_perm()
{
    string s {"0123456789"};

    int cnt = 0;
    while(cnt < 2) {
        random_shuffle(s.begin(), s.end());
        cout << s << endl;
        cout << prev_perm(s) << endl << "***********************" << endl;
        cnt++;
    }

    s = "2134";
    cout << prev_perm(s) <<endl;

    s = "1024";
    cout << prev_perm(s) <<endl;

    s = "14235";
    cout << prev_perm(s) <<endl;
}

void kth_perm(int n, int k)
{
    int j, i=0;
    vector<int> fact(n);
    vector<int> perm(n);
    fact[0]=1;
    while(++i < n)
        fact[i] = fact[i-1]*i;

    for (i=0; i<n; ++i) {
        perm[i]= k/fact[n-1-i];
        k = k % fact[n-1-i];
    }
    copy(perm.begin(), perm.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (i=n-1; i>0; --i)
        for (j=i-1; j>=0; --j)
            if (perm[j] <= perm[i])
                perm[i]++;
    for (i=0; i<n; ++i)
        cout << perm[i] ;
    cout << endl;
}
string gp(int n, int k)
{
    if (n <= 0) return "E";

    vector<int> f(n);
    string p(n, '0');
    int i=0;
    if (n==1) return {"1"};
    f[0]=1;
    for (i=1; i<n; i++)
        f[i]=f[i-1]*i;
    cout << k << " " << n*f[n-1] << endl;
    if (k>=n*f[n-1]) return "E1";
    for (i=0; i<n; ++i) {
        p[i] += k / f[n-1-i];
        k %= f[n-1-i];
    }

    for (i=n-1; i>0; --i) {
        for (int j = i-1; j>=0; --j)
            if (p[i]>=p[j]) p[i]++;
    }
    return p;
}
int main()
{
    //test_next_perm();
    //test_prev_perm();
    kth_perm(2, 1);
    kth_perm(4, 4);
    kth_perm(4, 21);

    cout << "* " << gp(2, 1) << endl;
    return 0;
}
