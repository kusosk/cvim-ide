#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

void InsertSort(int* v, int l)
{
    int tmp = 0;
    for (int i=1; i<l; i++) {
        tmp = v[i];
        for (int j = i; j>0 && v[j] > tmp; j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}

void ShellSort(int* v, int l)
{
    int i, j, inc;
    int tmp;
    for (inc=N/2; inc>0; inc/=2) {
        for (i=inc; i<l; i++) {
            tmp = v[i];
            for (j=i; j>0&&v[j]>tmp; j--) {
                v[j] = v[j-1];
            }
        }
    }
}

int main()
{
    
    return 0;
}
