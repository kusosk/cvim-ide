/*
 * =====================================================================================
 *
 *       Filename:  new.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/2013 01:17:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <iostream>
using namespace std;
class Test1 {
    public:
        Test1() {cout << " Test1 alive " <<endl;}
};
class Test2 {
    public:
        Test2(string s) {cout << " Test1 alive " << s << endl;}
};
int main() {
    // your code goes here
    void* pt1 = malloc(sizeof(Test1));
    cout << "memory ready" << endl;
    Test1* t1 = new (pt1) Test1;

    Test1* t11 = (Test1*)malloc(sizeof(Test1));
    t11 = new (t11) Test1();

//    Test1* t12 = NULL;
//    cout << "t12: " << t12 << endl;
//    ::operator new(sizeof(Test1), t12);
//    cout << "t12: " << t12 << endl;

    void* pt2 = malloc(sizeof(Test2));
    cout << "memory ready" << endl;
    Test2* t2 = new (pt2) Test2("test2");

    //delete (void*)NULL;
    delete t2;
    //delete t12;
    delete t11;
    delete t1;
    return 0;
}
