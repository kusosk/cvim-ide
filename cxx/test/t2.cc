#include <iostream>
#include <bitset>

using namespace std;

void DumpHex(int v)
{
    cout << hex << v << endl;
}
template <typename T, int N=32>
void DumpBin(T v)
{
    cout << (bitset<N>)v << endl;
}
void func1(const int& N, int i)
{
    /*
    unsigned long long v1 = 1LLU;
    cout << hex <<  ~v1 << endl;
    cout << hex <<  (v1>>1) << endl;
*/
    unsigned long long v0 = 1LLU << (N-1);
    DumpBin<unsigned long long>(v0);
    DumpBin<unsigned long long>(v0>>i);
}
    int
main ( int argc, char *argv[] )
{
    func1(4, 2);
    cout << endl;
    func1(32, 7);
    cout << endl;
    func1(32, 1);
    cout << endl;
    func1(32, 31);
    cout << endl;
    func1(32, 32);

    cout << endl;
    DumpBin<unsigned long long>(1LLU<<32);
    return 0;
}				/* ----------  end of function main  ---------- */
