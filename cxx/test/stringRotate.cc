/*
 * =====================================================================================
 *
 *       Filename:  stringRotate.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/22/2013 01:17:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
using namespace std;

string rotateStr(const string& str, int len)
{
    if (!str.size() || len < 1)
        return string("");
    
    int size = str.size();
    if (len > size)
        len %= size;

    
}
