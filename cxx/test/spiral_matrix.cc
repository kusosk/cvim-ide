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
vector<vector<int> > gen_spiral_matrix(int m, int n, int s)
{
    vector<vector<int> > r(m);
 /*
    int t=0, b=m-1, l=0, r=n-1;
    while(t<=b && l<=r) {
        for (int i=l; i<r; ++i) 
            r[b].push_back(s++);
        for (int j=b; j<t; ++j)
            r
    }
*/
    bool f=true;
    for (int i = 0; i < m; ++i)
        r[i].resize(n);
        for (int j = f?0:n-1; f?j<n:j>=0; f?++j:--j) {
            r[i][j] = s++;
        }
        f = !f;
    }
}
void spiral_clockwise(vector<vector<int> > &m)
{

}

int main()
{
    vector<vector<int> > 
    return 0;
}
