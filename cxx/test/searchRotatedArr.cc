#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

int search(int A[], int n, int target) {
    if (n<=0) return -1;
    int l=0, r=n-1, e, m;
    if (A[l]==target) return l;
    if (A[r]==target) return r;

    if (A[l] > A[r]) {
        if (target>A[r] && target<A[l]) return -1;
        e=l;
        while(e+1<n && A[e] <A[e+1]) e++;
        cout << "e:" << e<<endl;
        if (A[e] == target) return e;
        else if (A[e] < target) return -1;
        else { 
            if (target>A[l]) r=e-1;
        }

        if (A[e+1] == target) return e+1;
        else if (A[e+1] > target) return -1;
        else { 
            if (target<A[r]) l=e+2;
        }
    }
    cout << l << " " << r << endl;        
    while(l<n && r<n && l <= r) {
        m=(l+r)>>1;
        if (A[m] == target) return m;
        else if (A[m] > target) r=m-1;
        else l=m+1;
    }
    return -1;
}

int main()
{
    int a[7]={4,5,6,7,0,1,2};
    cout << search(a, 7, 5)<<endl;
    return 0;
}
