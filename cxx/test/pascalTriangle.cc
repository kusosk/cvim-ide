#include	<iostream>
#include	<vector>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

vector<vector<int> > generate(int numRows)
{
   vector<vector<int> > res;
   for(int i=1;i<=numRows;++i) {
        vector<int> curr(i);
        curr[0] = 1;
        if (i==1) {
            res.push_back(curr);
            continue;
        }
        curr[1]=i;
        for (int j=2;i>1&& j<i-2; ++j) {
            curr[j] = res[i-2][j-1]+res[i-2][j];
            cout << j <<endl;
        }
        if (i>2)
            curr[i-2]=i;
        curr[i-1] = 1;
        res.push_back(curr);
   }
   return res;
}

void display(vector<vector< int > >& d)
{
    for (size_t i = 0; i < d.size(); ++i) {
        vector<int> curr = d[i];
        for (size_t j=0; j<curr.size(); ++j)
            cout << curr[j] << " ";
        cout << endl;
    }
}
int main()
{
    vector<vector< int > > result = generate(5);
    display(result);
    return 0;
}
