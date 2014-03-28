#include	<iostream>
#include	<climits>
#include    <string>
#include    <algorithm>
#include    <stdexcept>

using namespace std;

void func1()
{
    string s("abcd");
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main()
{
    func1();
    return 0;
}
