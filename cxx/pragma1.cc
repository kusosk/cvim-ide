/*
 * =====================================================================================
 *
 *       Filename:  progma.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/2013 01:42:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <limits>
#define TEST1 100
using namespace std;

void test1()
{
    cout << std::numeric_limits<unsigned long>::max() << std::endl;
    cout << max(100, 1) << ": correct " <<endl;
}

int max(int x, int y){return x+y;}
void test2()
{
#pragma push_macro("max")
#undef max
    cout <<max(100,1)<< ": wrong " <<endl;
}
void test3()
{
#undef max
#pragma pop_macro("max")
    cout <<max(100,1)<< ": restore " <<endl;
}

#pragma push_macro("TEST1")
int main()
{
    cout << TEST1 << endl;
#undef TEST1
#define TEST1 1
    cout << TEST1 << endl;
#pragma pop_macro("TEST1")
    cout << TEST1 << endl;

    test1();
    test2();
    test3();


    return 0;
}
