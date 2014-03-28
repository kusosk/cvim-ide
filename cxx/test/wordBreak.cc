#include	<iostream>
#include	<set>
#include	<unordered_set>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    // IMPORTANT: Please reset any member data you declared, as
    //         // the same Solution instance will be reused for each test case.
    if (!s.size() || !dict.size()) return false;
    size_t s_len = s.size();
    size_t dict_len = dict.size();
    size_t start = 0;
    for (size_t p = 1; p <=s_len; ++p) {
        string curr = s.substr(start, p-start);
        for (size_t di=0; di < dict_len; ++di) {
            unordered_set<string>::iterator is_exist = dict.find(curr);
            if (is_exist != dict.end()) {
                start = p;
                cout << "found " << *is_exist << " " << curr << endl;
                break;
            }
        }
    }
    return start==s_len?true:false;
}
int main()
{
    unordered_set<string> ts;
    ts.emplace("abaa");
    ts.emplace("aab");
    cout << wordBreak("aababaa", ts) << endl;
    return 0;
}
