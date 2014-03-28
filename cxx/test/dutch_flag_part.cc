#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <iterator>
#include    <vector>

using namespace std;

template <typename T>
void DFPart(vector<T>& in, int i)
{
    if (!in.size()) return;
    T t = in[i];
    int l=0, m=0, r=in.size()-1;
    while(m <= r) {
        if (in[m] < t) {
            swap(in[m], in[l]);
            l++;
        } else if (in[m] == t)
            m++;
        else {
            //if (
            swap(in[m], in[r]);
            r--;
        }
    }
}
int main()
{
    vector<int> in1{1,2,3};
    vector<int> in2(in1);
    copy(in2.begin(), in2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
