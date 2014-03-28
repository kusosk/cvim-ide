#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;
inline bool valid(char c)
{
    return c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9';
}
bool equal_(char c1, char c2)
{
    c1 = c1>='A'&&c1<='Z'? c1^('a'^'A') : c1;
    c2 = c2>='A'&&c2<='Z'? c2^('a'^'A') : c2;
    return c1==c2;
}
bool isPalindrome(string s) {
    // IMPORTANT: Please reset any member data you declared, as
    //         // the same Solution instance will be reused for each test case.
    if (s.size()<2) return true;
    int left=0, right=s.size()-1;
    while(left <= right) {
        cout << left << " " << right<<endl;
        if (!valid(s[left])) { left++; continue;}
        if (!valid(s[right])) { right--; continue;}
        if (left+1==right) {
            return equal_(s[left], s[right]);
        }
        if (left==right)
            return true;
        if (!equal_(s[left],s[right]))
            return false;
        else {
            ++left; 
            --right;
        }
    }
    return true;
}

int main()
{
    cout << isPalindrome(string("Live on evasions? No, I save no evil."))<<endl;
    return 0;
}
