/*
 * =====================================================================================
 *
 *       Filename:  callable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/27/2013 05:09:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include <memory>
#include <future>

#include <unistd.h>

using namespace std;

auto l = [] (int x, int y) { cout << "l execd..." << endl; cout<< x+y << endl;};

void func1 (int x , int y)  { cout<< x-y << endl;}
void func2 (int x, int y) {
    for ( int i = 0; i < 5; i++) {
        usleep(1000);
        cout << "func2 sleep ...." <<endl;
    }
    cout << x/y << endl;
}
class C1 {
    public:
        C1() { cout << "C1 up" << endl;}
        void mfunc(int x, int y) { cout<< x*y << endl;}      
};

int main()
{
    C1 c1;
    std::shared_ptr<C1> ptr(new C1);

    std::bind(l, 10, 5)();
    bind(func1, 10, 5)();
    bind(&C1::mfunc, c1, 10, 5)();
    
    async(func1, 10, 5);
    async(func2, 10, 5);
    usleep(100000);
    return 0;
}

