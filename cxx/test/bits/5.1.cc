#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <bitset>

using namespace std;

void showMergedValue(int M, int N, int i, int j)
{
    int M_mast = M;
    M_mast = ~M;
    cout << (bitset<32>)M_mast << endl;
    M_mast = (~(M_mast << i)) & ~((1<<i)-1);
    cout << (bitset<32>)M_mast << endl;
    M_mast &= (1<<(j+1))-1;
    cout << (bitset<32>)M_mast << endl;
    
}

int main()
{
    showMergedValue(0b10010, 0b10000000000, 2, 6);
    return 0;
}
