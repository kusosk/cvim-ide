#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;
string addBinString(string& s, string& l, int sz, int diff){
    int pos = sz-1;
    bool incnext=false;
    string res;
    while(pos>=0) {
        int tmp = (pos<diff ? 0 : (s[pos-diff]-'0')) + l[pos]-'0' + (incnext?1:0);
        incnext = tmp>>1;
        cout << incnext << " tmp : " << tmp << " " << s[pos] << " " << l[pos]<<endl;
        res = string(tmp&1?"1":"0")+res;
        pos--;
    }
    if (incnext)
        res = string("1")+res;
    return res;
}

string addDecString(string& s, string& l, int sz, int diff)
{
    bool incnext=false;
    string res;
    int tmp=0;
    int i=sz-1;
    while(i>=0) {
        tmp=l[i]-'0' + (i<diff?0:s[i-diff]-'0') + (incnext?1:0);
        incnext = tmp/10;
        res = string(1, '0'+(tmp%10))+res;
        i--;
    }
    if (incnext)
        res = string("1")+res;
    return res;
}
string addNumber(string a, string b, int base) {
    if (!a.size() && !b.size()) return string("");
    if (!a.size()) return b;
    if (!b.size()) return a;
    int sza=a.size(), szb=b.size();
    if (sza <= szb)
        return base==2?addBinString(a, b, szb, szb-sza):addDecString(a, b, szb, szb-sza);
    else
        return base==2?addBinString(b, a, sza, sza-szb):addDecString(b, a, sza, sza-szb);
}
int main()
{
    cout << addNumber("1111", "101", 2) << endl;
    cout << addNumber("99989", "111", 10) << endl;
    return 0;
}
