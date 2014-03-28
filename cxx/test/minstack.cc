/*
 * =====================================================================================
 *
 *       Filename:  t.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2013 01:27:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<stack>

using namespace std;

template <typename T>
class MinStack {
    T minimal; 
    stack< T > _stack;        
    public:
        void push(const T& t) 
        {
            if (_stack.size() == 0)
                minimal = t;
            else {
                if (t < minimal)
                    minimal = t;
            }
            _stack.push(t);
        }
        T pop()
        {
            T top = _stack.top();
            _stack.pop();
            return top;
        }
        T min()
        {
            return minimal;
        }
        
};
    int
main ( int argc, char *argv[] )
{
    MinStack< int > stack;
    stack.push(-1);
    stack.push(0);
    stack.push(100);
    cout << stack.min() << endl;
    stack.pop();
    cout << stack.min() << endl;

    return 0;
}				/* ----------  end of function main  ---------- */
