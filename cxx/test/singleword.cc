#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

void func1()
{

}

int sol2(int A[], int n)
{
    int one = 0, two = 0, three = 0;
    for (int i = 0;i < n;++i) {
        two |= one & A[i];
        one ^= A[i];
        three = one & two;
        one &= ~three;
        two &= ~three;
        cout << one << " " << two << " " << three << endl;
    }
    return one;
}
int main()
{
    int A[7] = {3,5,3,100,3,5,5};
    cout << sol2(A, 7) << endl;
    return 0;
}
