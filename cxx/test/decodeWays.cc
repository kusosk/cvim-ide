#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

string int2AA(int i)
{
    string r;
    if (!i) return r;
    while(i>=26) {
        r.push_back('A'+i/26-1);
        i/=26;
    }
    r.push_back('A'+i%26-1);
    return r;
}

int main()
{
    cout << int2AA(27) << " " << int2AA(53) << " " << int2AA(26*26+27) << endl;
    cout << int2AA(11) << " " << int2AA(111) << " " << int2AA(1111) << endl;
    return 0;
}
