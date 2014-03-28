#include "gtest/gtest.h"
#include	<iostream>
#include	<climits>
#include    <string>
#include    <cassert>

using namespace std;

TEST(string, InitAndClear)
{
    string s0;
    cout << s0.capacity() << " " << s0.max_size() << endl;
    string s1("test");
    string s2("ABC");
    //ASSERT_STREQ(s1.c_str(), "test");
    s1 = string("test", 3);
    cout << s1 << endl;
    s1 = string(s2);
    cout << s1 << endl;
    s1 = string(s2, 1, 2);
    cout << s1 << endl;
    s1 = string(10, 'a');
    cout << s1 << endl;

    string s3;
    s3 = string("abcd");
    s3 = string("abcd", 3);
    s3 = string(s2);
    s3 = string(s2, 0, 2);
    s3 = string(2, 'a');
    
    s3.resize(10);
    s3.erase(0, 2);
    cout << s3 << " " << s3.size() << " " << s3.capacity() << endl;

    s2 = string("123456789.00 123");
    size_t n;
    cout << (double)stod(s2, &n) << "|" << stoi(s2.substr(n), &n)<< " N=" << n << endl;
}

