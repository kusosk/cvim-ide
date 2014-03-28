#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <unordered_map>

using namespace std;

unordered_map<int, int> f;

int numTrees(int n) {
    // IMPORTANT: Please reset any member data you declared, as
    //         // the same Solution instance will be reused for each test case.
    if (n==0) return 1;
    if (n<3) return n;
    f[0] = f[1] = 1;
    f[2] = 2;
    for (int i=3; i<=n; ++i) {
        f[i] = 0;
        for (int j=0; j<(i-1)/2; ++j) {
            f[i] += (f[j]*f[i-1-j])<<1;
            cout <<j<<" "<<i-1-j<< " "<< f[i]<< endl;
        }
        if (i%2)
            f[i] += f[i/2]*f[i/2];
        cout << i << " "<<f[i]<<endl;
    }
    return f[n];
}
int main()
{
    cout << numTrees(4) << endl;
    return 0;
}
