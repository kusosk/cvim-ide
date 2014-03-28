#include	<iostream>
#include	<climits>
#include    <string>
#include    <algorithm>
#include    <stdexcept>

using namespace std;
int searchInsert(int A[], int n, int target) {
    // IMPORTANT: Please reset any member data you declared, as
    //         // the same Solution instance will be reused for each test case.
    if (!n) return 0;
    if (A[0] > target) return 0;
    if (A[0] == target) return 0;
    if (A[n-1]<target) return n;
    if (A[n-1]==target) return n-1;
    int l=0, r=n-1, m;
    while(l<=r) {
        if (l==r) {
            if (A[l] < target)
                return l+1;
            else if(A[l] > target) {
                return !l?0:l-1;
            } else {
                cout << "l==r" << l << " " << A[l]<<endl;
                return l;
            }
        } 
        if (l+1==r) {
            if (A[l] >target)
                return !l?0:l-1;
            else if (A[l]==target)
                return l;
            else {
                if (target <=A[r])
                    return r;
                else if (target>A[r])
                    return r+1;
            }
        }
        m = (l+r)/2;
        if (A[m] < target) {
            l=m+1;
        } else if (A[m]>target) {
                r=m-1;
        } else 
            return m;
    }
}

int main()
{
    int A[100] = {1};
    cout << searchInsert(A, 1, 1)<<endl;
    string r("abcd");
    cout << std::reverse(r.begin(), r.end()) << endl;
    string s;
    for (int i = 0; i<10; ++i)
        s+='0'+i;
    cout << s << " " << std::reverse(s.begin, s.end()) << endl;
    return 0;
}
