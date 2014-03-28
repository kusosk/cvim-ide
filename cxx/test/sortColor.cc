#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

void sortColors(int A[], int n) {   
    // Start typing your C/C++ solution below   
    // DO NOT write int main() function   
    int redSt=0, bluSt=n-1;   
    int i=0;   
    while(i<bluSt+1)   
    {   
    for(int j=0;j<9;++j)
        cout<< A[j] <<" ";
    cout << endl;
        if(A[i]==0)   
        {   
            std::swap(A[i],A[redSt]);   
            redSt++;   
            i++;   
            continue;   
        }   
        if(A[i] ==2)   
        {   
            std::swap(A[i],A[bluSt]);   
            bluSt--;    
            continue;   
        }   
        i++;   

    }   
}   
int main()
{
    int A[9]={2,2};
    sortColors(A,2);
    return 0;
}
