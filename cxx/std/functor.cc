/*
 * =====================================================================================
 *
 *       Filename:  functor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2013 03:11:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<cstdio>
using namespace std;

class functor1 {
    int i;
    int j;
    public:
        functor1(int i, int j) : i(i), j(j){}
        int operator()() {
            return i*j;
        }
};
    int
main ( int argc, char *argv[] )
{
    functor1 f1(2, 6);
    cout << f1() << endl;
    return 0;
}				/* ----------  end of function main  ---------- */
