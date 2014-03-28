#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

typedef vector<int> vint;
int main()
{
    vint r;
    for (int i=0; i<5; ++i) 
        r.insert(r.begin(), i);
    for (int i=0; i<5; ++i) 
        cout << r[i] << " ";
    cout << endl;
    return 0;
}
