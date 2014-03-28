#include	<iostream>
#include	<iterator>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

//vector< vector<int> > subsetWithDup(vector<int>& S) {
//
//}    
int main()
{
//    vector<int> in{1,9,2,3,1,2,1,4};
    vector<int> in{4,1,0};
    sort(in.begin(), in.end());
    copy(in.begin(), in.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
