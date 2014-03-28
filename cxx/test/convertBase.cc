#include "gtest/gtest.h"
#include	<iostream>
#include	<climits>
#include    <algorithm>
#include    <cassert>

using namespace std;

string ConvertByBase(int v, int base)
{
    if (base < 2 || v < 0 || base == INT_MAX)
        return string("");
    string str;
    int i = 0;
    while (v) {
        str[i++] = '0'+ (v % base);
        v /= base;
    }

    if (i>1)
        reverse(str.begin(), str.begin() + i);
    return str;
}
TEST(ConvertByBase, NotValid)
{
    ASSERT_STREQ(ConvertByBase(-1, -1).c_str(), "");
    ASSERT_STREQ(ConvertByBase(-1, 0).c_str(), "");
    ASSERT_STREQ(ConvertByBase(-1, 2).c_str(), "");
}
TEST(ConvertByBase, Valid)
{
    ASSERT_STREQ(ConvertByBase(1, 10).c_str(), to_string(1).c_str());
    ASSERT_STREQ(ConvertByBase(27, 13).c_str(), to_string(21).c_str());
    ASSERT_STREQ(ConvertByBase(7, 7).c_str(), to_string(10).c_str());
    ASSERT_STREQ(ConvertByBase(16, 2).c_str(), to_string(10000).c_str());
}

