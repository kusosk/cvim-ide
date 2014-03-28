/*
 * =====================================================================================
 *
 *       Filename:  pragma2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/2013 02:08:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <limits>
#include <cassert>

using namespace std;

//#pragma push_macro("max")
//#undef max

template<typename T>
struct _stable_limits{
    static T min() { return std::numeric_limits<T>::min(); }
    static T max() { return static_cast<T>(9); }
};

int main()
{
    cout << max(1,2) <<endl;
#undef max
    cout << max(1,2) <<endl;
    assert(&max(1,2) == &std::max(1,2));
    cout << std::numeric_limits<int>::max() << endl;
    cout << _stable_limits<int>::max() << endl;
#pragma pop_macro("max")
    cout << std::numeric_limits<int>::max() << endl;
    return 0;
}
