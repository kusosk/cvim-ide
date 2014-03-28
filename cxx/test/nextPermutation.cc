#include	<iostream>
#include	<iterator>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <map>

using namespace std;

void nextPermutation(vector<int> &num) {
    int sz=num.size();
    int i, j;
    int curr;
    map<int,int> len2swap;
    for (i=sz-1; i>=0; --i) {
        curr=num[i];
        for (j = i-1; j>=0&&num[j]>=curr; --j) {
        }
        len2swap[i]=j;
    }
    int pos=sz-1, begin=len2swap[sz-1];
    for (i=sz-2; i>=0 && i>begin; --i) { // i>begin to omit lots of impossible case
        if (len2swap[i]>begin) {//1437652 16598762
            pos=i;
            begin=len2swap[i];
        }
    }
    cout << "num["<<begin<<"]="<<num[begin]<<endl;
    if (begin==-1) {
        reverse(num.begin(), num.end());
        return;
    } else {
        swap(num[begin], num[pos]);
        sort(num.begin()+begin+1, num.end());
    }
}
int main()
{
    vector<int> i{1,5,1};
    nextPermutation(i);
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
