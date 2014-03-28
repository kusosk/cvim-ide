//#include "gtest/gtest.h"
#include	<iostream>
#include	<exception>
#include    <string>
#include    <cstring>
#include    <cassert>
#include    <cstdio>

using namespace std;
/*
void display(const int* v, size_t len, bool sep=false, char delim=' ')
{
    for(int i=0; i<len; ++i) {
    //    if (sep)
            cout << v[i] << delim;
//        else
//            cout << v[i];
    }

    cout << endl;
}
*/
void func1(const char* s, int len)
{
    if (!s || len < 2)
        return ;
    int max_len = (len<<1) + 2;
    char* str = NULL;
    int* p = NULL;
    int id = 0;
    int maxid = 0;
    try {
        //str = new char[max_len%4 ? (max_len/4+1)*4 : max_len];
        str = new char[max_len+1];
        try {
            p = new int[max_len];
        } catch (std::bad_alloc&) {
            delete[] str;
            return;
        }
    } catch (std::bad_alloc&) {
        return;
    }
    memset(p, 0, sizeof(int)*max_len);
    memset(str, 0, max_len+1);
    str[0] = '$';
    for (int i = 0; i < len; ++i) {
        int pos = i << 1;
        str[pos+1] = '#';
        str[pos+2] = s[i];
    }
    str[2*len+1] = '#';
    str[max_len]='\0';
    cout << str << endl;
    //display<char>(str, max_len+1);

    p[0] = 0;
    for (int i = 1; i < max_len; ++i) {
        if (maxid > i)
            p[i] = p[2*id-i] > (maxid-i) ? (maxid-i):p[2*id-i];
        else
            p[i] = 1;
        while (i+p[i]<max_len && i-p[i]>=0 && str[i+p[i]] == str[i-p[i]]) p[i]++;
        if (maxid < i+p[i])
        {
            id = i;
            maxid = i+p[i];
        }
    }
    //display<int>(p, max_len);

    int max = 0;
    int idx = 0;
    for (int i = 0; i<max_len+1; ++i)
    {
        if (p[i] >= max) {
            max = p[i];
            idx = i;
        }
    }
    cout << "max_len: " << max << " @[" << idx << "]" << endl;
    string res(s);
    //string res1(str);
    //cout << res1.substr(idx-max, 2*max) << endl;
    int resl = (max%2?max-1:max);
    cout << res.substr((idx-max)/2, max-1 ) << " len:" << resl << endl;
    delete[] str;
    delete[] p;
}
//TEST(, )
//{
//    ASSERT_EQ(, );
//}
void func2()
{
    try {
        throw int(2);
    } catch (int &) {
        cout << "got it" <<endl;
    }
    cout << "continue" << endl;
}

char s1[10000001] ;
int main()
{
    while (scanf("%s", s1) != EOF) 
    {
        scanf("%s", s1);
        cout << "["<<s1<<"]"<<endl;
        func1(s1, strlen(s1));
    }

    return 0;
}
