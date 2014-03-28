#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;
string convert(string s, int nRows) {
    if (s.size()<2 || nRows < 2) return s;
    int len=s.size(), pos;
    int stp = (nRows<<1)-2;
    char c;
    string res;
    int cnt=0;
    for (int i = 1; i<=nRows; ++i) {
        pos = 0;
        if (i<=(nRows>>1)) {
            for (int j = 0; pos < len; ++j) {
                if (j%2)
                    pos = i==1 ? j*stp : (j ? ((j+1)>>1)*stp-(i-1) : i-1);
                else
                    pos = i==1 ? j*stp : (j ? ((j+1)>>1)*stp+(i-1) : i-1);
                cout <<"!"<< pos<< " "  << i << " " << j<<endl;
                if (cnt>len||pos>=len) break;
                c = s[pos];
                res.push_back(c);
                cnt++;
                cout << pos <<"["<<c<<"]";
            }
        } else {
            for (int j = 0; pos < len; ++j) {
                if (j%2== 0) {
                    pos = i==nRows ? (nRows-1)+j*stp : (j>>1)*stp+i-1;
                }else
                    pos = i==nRows ? (nRows-1)+j*stp : (j>>1)*stp+stp-i+1;
                cout <<"!"<< pos<< " "  << i << " " << j<<endl;
                if (cnt>len||pos>=len) break;
                c = s[pos];
                cout << pos<<"["<<c<<"]"<<endl;
                res.push_back(c);
                cnt++;
            }
        }
        cout << endl;
    }
    return res;
}

string n(string s, int nRows)
{
    if (s.size()<2 || nRows < 2) return s;
    int len=s.size(), pos;
    int stp = (len<<1)-2;
    char c;
    string res;
    int cnt=0;
    for (int i = 1; i<=nRows; ++i) {
        pos = 0;
        if (i<=(nRows>>1)) {
            for (int j = 0; pos < len; ++j) {
                if (j%2)
                    pos = i==1 ? j*stp : (j ? ((j+1)>>1)*stp-(i-1) : i-1);
                else
                    pos = i==1 ? j*stp : (j ? ((j+1)>>1)*stp+(i-1) : i-1);
                if (cnt>len||pos>=len) break;
                c = s[pos];
                res.push_back(c);
                cnt++;
            }
        } else {
            for (int j = 0; pos < len; ++j) {
                if (j%2 == 0)
                    pos = i==nRows ? (nRows-1)+j*stp : (j>>1)*stp+i-1;
                else
                    pos = i==nRows ? (nRows-1)+j*stp : (j>>1)*stp+stp-i+1;
                if (cnt>len||pos>=len) break;
                c = s[pos];
                res.push_back(c);
                cnt++;
            }
        }
    }
    return res;
}
int main()
{
    cout << convert("AB", 3) << endl;
    cout << n("AB", 3) << endl;
    return 0;
}
