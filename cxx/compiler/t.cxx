/*
 * =====================================================================================
 *
 *       Filename:  t.cxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/03/2013 03:34:17 PM
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

class Test1 {
    public:
        Test1(){cout << "Test1 inst live"<<endl;}
        ~Test1() {cout << "Test1 inst quit"<<endl;}
};

class Test2 {
    public operator new(size_t sz) {
        cout << "new Test2 operator" << endl;
        throw sz;
    }
};

static Test1 test1_1;

int main()
{
    Test1 test1_l1[3];

    try {
        Test2 t2_1;
    } catch (...) {
        cout << "catch exception..." << endl;
    }
    return 0;
}
