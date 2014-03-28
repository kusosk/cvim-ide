#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <unordered_map>

using namespace std;

void ra(vector<int>& in, int p, int l)
{
    int sz=in.size();
    if (!sz || p<0 || p >= sz ) return ;
    l %= sz;
    if (!l) return;
    reverse(in.begin(), in.begin()+p-1);
    reverse(in.begin()+p, in.end());
    reverse(in.begin(), in.end());
}

int main()
{
    vector<int> in{0,1,2,3,4,5,6};
    for (int i = -1; i < 7; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << i << " " << j << endl;
            ra(in, i, j);
            copy(in.begin(), in.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }

    return 0;
}
