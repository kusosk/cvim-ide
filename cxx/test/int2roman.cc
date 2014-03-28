#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <unordered_map>

using namespace std;

int romanToInt(string s) {
        if (!s.size()) return 0;
        string R[] = {"I","IV","V","IX","X","XL", "L","XC","C", "CD", "D", "CM","M"};
        int v[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        unordered_map<string, int> vlp;
        for (int i = 0; i <13; i++) {
            vlp[R[i]] = v[i];
        }

        int res=0;
        int sz=s.size(), i=0;
        if (sz==2)
            if (vlp.find(s)!=vlp.end())
                return vlp[s];
        while(i<sz) {
            res+=vlp[string(1,s[i])];
            i++;
            cout << res<<endl;
        }
        return res;
    }

string intToRoman(int num) {
    string R[7] = {"I", "V", "X", "L", "C", "D", "M"};
    int v[7]={1,5,10,50,100,500,1000};
    string res;
    if (num <= 0) return res;
    int l=0, r=6, m;
    int n = num;
    while(n) {
        l=0, r=6;
        while(l<=r) {
            m = (l+r)/2;
            if (n==v[m]) {
                res += R[m];
                return res;
            } else if (n<v[m]) {
                r=m-1;
            } else {
                l=m+1;
            }
        }
        if (n<v[l])
            r=l-1; // l won't be 0
        //if (n>v[r]) {
        if (r==6) {
            res+=R[6];
            n-=v[6];
            continue;
        } else {
            if (!(r%2)) {
                if (n >= v[r+1]-v[r]) {
                    res+=R[r]+R[r+1];
                    n-=v[r+1]-v[r];
                    continue;
                }
            } else {
                if (n>=v[r+1]-v[r-1]) {
                    res+=R[r-1]+R[r+1];
                    n-=v[r+1]-v[r-1];
                    continue;
                }
            }
        }
        res+=R[r];
        n-=v[r];
        //}
    }

    return res;
}
void test_intToRoman()
{

    int v;
    while(1) {
        cin>>v;
        if (!v) break;
        cout << intToRoman(v) << endl;
    }
}
void test_romanToInt()
{
    string s;
    while(1) {
        cin>>s;
        if (s.compare(" ")==0) break;
        cout << romanToInt(s) << endl;
    }
}
int main()
{
    test_romanToInt();
    return 0;
}
