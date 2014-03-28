#include	<iostream>
#include	<climits>
#include    <string>
#include    <cstring>

using namespace std;

int *p;

string longestPalindrome(string s)
{
    int max_len = s.size()*2+2;
    string ns("#", max_len);
    ns[0] = '$';
    for (int i = 1; i<=s.size(); ++i) {
        ns[i*2] = s[i-1];
    }
    p = new int [max_len];
    memset(p, 0, sizeof(int)*max_len);
    p[0]=0;
    int maxid=0;
    int id=0;
    for (int i=1;i<max_len;i++) {
        if (maxid > i)
            p[i] = maxid-i<p[2*id-i] ? maxid-i : p[2*id-i];
        else
            p[i] = 1;
        while (ns[i+p[i]] == ns[i-p[i]])
            p[i]++;
        if (i+p[i]-1 > maxid) {
            maxid = i+p[i]-1;
            id = i;
        }
    } 
    int maxp=-1;
    int i = 0, idx;
    for (; i<max_len; i++) {
        if (p[i] >= maxp) {
            idx = i;
            maxp = p[i];
        }
    }
    string res = s.substr((idx-p[idx])/2, p[idx]-1);
    delete[] p;
    return res;
}

int main()
{
    cout << longestPalindrome(string("bananas"))<<endl;
    return 0;
}
