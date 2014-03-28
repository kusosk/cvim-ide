#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;
int div1(int m, int n)
{
    int r=0;

    int k = n, i=0, p;
    while( m>k ) {
        p=k;
        k<<=1;
        i++;
    }
    if (m==k) return 1<<i;




    return r;
}
int main()
{
    
    return 0;
}
