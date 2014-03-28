#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <bitset>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <queue>

using namespace std;
#ifdef TTT
vector<int> grayCode(int n) {
    vector<int> res, tmp;
    bool z2o = true;
    if (n<1) return res;
    res.push_back(0);
    res.push_back(0);

    int code = 0;
    for (int i=2; i<n; ++i) {
        for (vector<int>::iterator it=res.begin(); it!=res.end(); ++it) {
            code <<= 1;
            if (z2o) {
                tmp.push_back(code);
                tmp.push_back(code & 1);
            } else {
                tmp.push_back(code & 1);
                tmp.push_back(code);
            }
            z2o = !z2o;
        }
        res = tmp;
        tmp.erase();
    }

    return res;
}
#endif
vector<int> grayCode0(int n) {
    vector<int> res;
    bool flip=false;
    res.push_back(0);
    res.push_back(1);

    for (int i = 1; i<n; ++i) {
        int cnt=0;

        while(cnt < (1<<i)) {
            int t = res.front();
            res.erase(res.begin());
            res.push_back((t<<1) | flip);
            res.push_back((t<<1) | !flip);
            flip = !flip;
            cnt++;
        }
        flip = false;
    }

    return res;
}
int main()
{
    vector<int> r = grayCode0(4);
    copy(r.begin(), r.end(), ostream_iterator<bitset<5>>(cout, " "));
    return 0;
}
