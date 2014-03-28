#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int lis(int A[], int n){
    int *d = new int[n];
    int len = 1;
    for(int i=0; i<n; ++i){
        d[i] = 1;
        for(int j=0; j<i; ++j)
            if(A[j]<=A[i] && d[j]+1>d[i])
                d[i] = d[j] + 1;
        if(d[i]>len) len = d[i];
    }
    delete[] d;
    return len;
}

int lis2(int d[], int n){
    int *B = new int[n];
    int left, right, mid, len = 1;
    for (int i = 0;i<n;++i)
        B[i] = INT_MAX;
    B[0] = d[0]; //为了和上面的一致，我们从1开始计数吧:)
    for(int i = 1; i < n; ++i){
        left = 0, right = len;
        while(left <= right){
            mid = (left + right) / 2;
            if(B[mid] < d[i]) left = mid + 1; //二分查找d[i]的插入位置
            else right = mid - 1;
        }
        cout << "insert @ left["<<left<<"] :" << B[left] << " with new v " << d[i]<<endl;
        B[left] = d[i]; //插入
        if(left >= len) {
            len++; //d[i]比现有的所有数字都大，所以left 才会大于 len。
            cout << "++\n" ;
        }
    }
    delete[] B;
    return len;
}

void func1(int* A, int l)
{
    cout<<lis(A, l)<<endl;
    cout<<lis2(A, l)<<endl;
    
}
int main(){
    int A[] = {
        99, 98, 4, 8, 6, 7, 12, 10, 2, 22, 1, 34, 2, 4, 22, 12, 23
    };
    for (int i = 1; i <=16; i++) {
        func1(A, i);
        cout << "**************************" << endl;
    }
    return 0;
}
