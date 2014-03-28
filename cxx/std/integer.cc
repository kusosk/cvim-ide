/*
 * =====================================================================================
 *
 *       Filename:  integer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/18/2013 01:26:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<bitset>
#include	<climits>
#include	<typeinfo>

using namespace std;

    int
main ( int argc, char *argv[] )
{
    int max = (int)(((unsigned int)1)<<31 - 1);
    int min = (int)((unsigned long)1<<32 - 1);
    int t1 = (((long long)1 << 32) - 1) & (((long long)1 << 31) -1); 
    int t2 = (1LL << 32 -1) & (1LL << 31 -1);
    long long t3 = ( (1LL<<32) -1) & ( (1LL<<31) -1);
    cout << "int bits: " << sizeof(int)*8 << endl;
    cout << "long bits: " << sizeof(long)*8 << endl;
    cout << "long bits: " << sizeof(1LL)*8 << endl;
    cout << "long bits: " << sizeof(1ll<<32)*8 << endl;
    cout << "long bits: " << sizeof(1ll<<32-1)*8 << endl;
    cout << (int)'0' << " " << (int)'1' << " " << (int)'9' << endl;
    cout << (char)91 << " " << (char)96 << " " << (int)'a' << " " << (int)'z' << " " << (int)'A' << " " << (int)'Z' <<endl;

    int min2 = (int)((1uLL<<32) -1);
    cout << "min2:" << min2 << endl;
    cout << typeid(1LL).name() << " " << typeid(1uLL).name() << " " << typeid(1).name() << endl;
    bitset<64> b1(t3);
    bitset<64> b2((1LL<<32)-1);
    bitset<64> b3(1LL<<33);
    cout << "max\t" << max << endl; 
    cout << "min\t" << min << endl; 
    cout << "t1\t" << t1 << endl; 
    cout << "t2\t" << t2 << endl; 
    cout << "t3\t" << t3 << endl; 
    cout << "t3 bit\t" << b1 << endl; 
    cout << "b2 bit\t" << b2 << endl; 
    cout << "b3 bit\t" << b3 << endl; 
    cout << INT_MAX <<endl;
    cout << INT_MIN <<endl;
    bool b00 = false;
    cout << !b00 <<endl;

    try {
        int i = 1<<32;
    } catch (...) {
        cout << "overflow1..." << endl;
    }

    try {
        int i = 1<<33;
    } catch (...) {
        cout << "overflow2..." << endl;
    }

    return 0;
}				/* ----------  end of function main  ---------- */
