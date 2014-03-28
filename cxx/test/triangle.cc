#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    int m = triangle.size();
    if (!m) return 0;
    if (m==1) return triangle[0][0];
    int* r=new int[m];
    int pr=0;
    int res = 0;
    r[0]=triangle[0][0];
    res=r[0];
    for (int i=1; i<m; ++i) {
        res=INT_MAX;
        for (int j=0; j<=i; ++j) {
            r[j] = j==0? r[j]+triangle[i][0]:min(r[j-1], r[j])+triangle[i][j];
            if (r[j] < res) res=r[j];
        }
    }
    
    if (r) delete[] r;
    return res;
}
int main()
{

    return 0;
}
