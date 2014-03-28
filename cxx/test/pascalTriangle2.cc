#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>

using namespace std;
vector<int> getRow(int rowIndex) {
    vector<int> res;
    int k = rowIndex;

    if (k < 1) return res;

    res.push_back(1);
    if (k==1) return res;

    for (int i = 2; i <= k; ++i) {
        int pos=((i+1)>>1)-1;
        if (i % 2)
            res.push_back( res[pos-1]<<1 );//not res[pos]<<1
        else {if (pos>=1) // not else if (pos>=1)
            res[pos]+=res[pos-1];   
        }
        for (int j = pos-1; j>=1; --j)
            res[j] += res[j-1];
    }

    int pos = ((k+1)>>1)-1;
    if (k%2 == 0)
        res.push_back(res[pos]);
    for (int i = pos-1; i>=0; --i)
        res.push_back(res[i]);
    return res;
}
int main()
{
    cout << "++++++++++++++++++++++++++" << endl;
    vector<int> r = getRow(1);
    copy(r.begin(), r.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    return 0;
}
