#include	<iostream>
#include	<cstring>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

struct prefix {
    int cnt;
    int first;
    bool word;
    struct prefix* br[128];
    prefix() : cnt(0), word(false), first(-1) {memset(br, 0, sizeof(prefix*)*128);}
};
bool buildPre(prefix& r, string& s) {
    if (!s.size()) return false;
    prefix* curr=&r;
    for (int i=0; i<s.size(); ++i) {
        if (!curr->br[s[i]]) {
            curr->br[s[i]] = new prefix();
            curr->cnt++;
            if(curr->first==-1) curr->first=s[i];
        }
        curr=curr->br[s[i]];
        if (r.cnt>1) return false;
    }
    curr->word=true;
    return true;
}
string findLCP(prefix& r)
{
    int l=0;
    string res;
    prefix* curr=&r;
    while(curr->cnt==1 && !curr->word) {
        res.push_back((char)curr->first);
        curr=curr->br[curr->first];
        l++;
    }
    return res;
}
string longestCommonPrefix(vector<string> &strs) {
    string res;
    if (!strs.size()) return res;
    prefix r;
    for(int i=0; i<strs.size(); ++i) {
        if(!buildPre(r, strs[i])) return res;
    }
    res=findLCP(r);
    return res;
}
int main()
{
    vector<string> in;
    in.push_back("a");
//    in.push_back("abcdd");
//    in.push_back("abcccd");
//    in.push_back("abbcd");
//    in.push_back("abacd");
//    in.push_back("abdcd");
//    in.push_back("abecd");
//    in.push_back("abacd");
//    in.push_back("bacd");

    cout << longestCommonPrefix(in) << endl;
    return 0;
}
