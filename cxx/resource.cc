/*
 * =====================================================================================
 *
 *       Filename:  resource.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2013 06:15:39 PM
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

template <typename T, int sz=1>
class Wrapper {
    T* ptr;
    public:
        class RangerError {};
        Wrapper() {
            ptr = new T[sz];
            cout << "Wrapper inited..."<<endl;
        }
        ~Wrapper() {
            delete [] ptr;
            cout << "Wrapper cleaned up..." << endl;
        }
        T& operator [] (int i) throw(RangerError) {
        //
        }
};

class T1 {
    virtual void func1 (int i) { cout << "T1::func2: " << i << endl;};
    public:
    virtual void func2 (int i) { cout << "T1::func2: " << i << endl;}
};

class T2 : T1{
    void func1 (int i) { cout << "T2::func1: " << i << endl;};
};

int main(void)
{
    T1* pt2 = new T1;

    //pt2->func1(1);

    delete pt2;
    return 0;
}
