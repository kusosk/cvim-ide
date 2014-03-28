/*
 * =====================================================================================
 *
 *       Filename:  t.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/22/2013 07:23:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;
void shift(int v, int len, bool right)
{
    //right? cout << (v&(1>>len)) : 1;
}
void DisplayBin(ostream& out, int v)
{
    for (int i = 31; i>0; --i) 
        out <<((v&(1LU<<i))>>i);
    out << (v&1LU);
}
int main()
{
    cout <<( (11 & (1LU << 31)) >> 31 ) << "|" << (0>>1) << "|" << (11>>2) <<endl;
    DisplayBin(cout, 11);
    return 0;
}


