#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

bool valid(char& c)
{
    return c>='0' && c<='9';
}
void gen(string& str, int s, int idx, string curr, vector<string>& res)
{
    if (s==str.size()) {
        if (idx==4) {
            res.push_back(curr);
            return;
        } else return;
    } else if (s>str.size() || idx>4) return;
    cout <<"l" << idx << " @" << s <<" ["<< curr<< "]"<< str.substr(s) << endl;
    if (str.size()-s > (4-idx)*3) return;
    if (!valid(str[s])) return;
    if (str[s] == '0') {
        gen(str, s+1, idx+1, curr+(!idx?"":".")+"0", res);
    } else  {
        if (s+1<=str.size()) 
            gen(str, s+1, idx+1, curr+(!idx?"":".")+str.substr(s,1), res);
        else
            return;
        if (s+2<=str.size())
            gen(str, s+2, idx+1, curr+(!idx?"":".")+str.substr(s,2), res);
        else
            return;
        if (str[s] == '1')
            gen(str, s+3, idx+1, curr+(!idx?"":".")+str.substr(s,3), res);
        if (str[s] == '2' && s+2<=str.size()) {
            int t = (str[s+1]-'0')*10+(str[s+2]-'0');
            if (t<56)
                gen(str, s+3, idx+1, curr+(!idx?"":".")+str.substr(s,3), res);
        }

    }
}
vector<string> restoreIpAddresses(string s) {
    int idx=0;
    string curr;
    vector<string> res;
    int st = 0;
    gen(s, st, idx, curr, res);
    return res;
}
void p(string s)
{
    cout << s << " ";
}
int main()
{
    vector<string> r=restoreIpAddresses("172162541");
    for_each(r.begin(), r.end(), p);
    cout << endl;
    return 0;
}
