#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

string expandFrom(string s, int i, int j) {
    while (i >= 0 && j < s.length() && s[i] == s[j]) {
        i--;
        j++;
    }
    return s.substr(i + 1, j-i-1);
}
string longestPalindrome(string s) {
    string max = "";
    for (int i = 0; i < s.length(); i++) {
        string odd = expandFrom(s, i, i);
        string even = i != s.length() - 1 ? expandFrom(s, i, i + 1) : "";
        odd = odd.size() < even.size() ? even : odd;
        max = max.size() < odd.size() ? odd : max;
    }
    return max;
}
int main()
{
    string s1("aabcdcbd");
    cout << longestPalindrome(s1) << endl;
    return 0;
}
