#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

void func1(int *num, int len, int target)
{
    //2 sum
    int i = 0; //头指针
    int j = len - 1; //尾指针
    while(i < j) {
        int sum = num[i] + num[j];
        if(sum == target) {
            //store num[i] and num[j] somewhere;
            cout << num[i] << "+" << num[j] << "=" << target <<endl; 
            do ++i, --j;
        }
        else if(sum < target)
            ++i;
        else
            --j;
    }
}

int main()
{

    return 0;
}
