/*
 * =====================================================================================
 *
 *       Filename:  test1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2013 11:18:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<iostream>
using namespace std;
bool func1(int x)
{
    bool result = true;
    int len = 0;
    int times_10 = 1;
    if (x == -x)
        x -= 1;
    else
        x = x<0?-x:x;
    cout << "x changed to : " << x << endl;
    if (x<0)
        cout << "nag" << endl;
    else
        cout << "not nag" << endl;
    while (x) {
        x /= 10;
        if (len)
            times_10 *= 10;
        ++len;
    }
    cout << len << endl << endl;
    if (len < 2)
        return true;

    int pos_front = 1;
    int tmp = x;
    if (tmp>0)
        cout << "nag" << endl;
    else
        cout << "not nag" << endl;
    while (tmp > 0 && pos_front <= len/2) {
        cout << "f : " << tmp / times_10 << endl;
        cout << "e : " << tmp % 10 << endl;
        if ( tmp / times_10 != tmp % 10)
            return false;
        tmp -= tmp / times_10 * times_10;
        tmp /= 10;

        pos_front++;
        times_10 /= 100;
    }
    return result;
}
    int
main ( int argc, char *argv[] )
{
    int x  = -2147483648;
    int y = 1<<32-1; 
    cout << "y: " << y <<endl;
    cout << "-y: " << -y <<endl;
    bool b1 = y==-y;
    cout << b1 << endl;
    cout << y+1 << endl;
    cout << y-1 << endl;
    cout << -y-1 << endl;
    cout << -y+1 << endl;
    
    int z = (1 << 32-1) & (1 << 31 - 1);
    cout << "z : " << z << endl;
    cout << func1(x) << endl;

    return 0;
}				/* ----------  end of function main  ---------- */
