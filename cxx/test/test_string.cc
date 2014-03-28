#include "gtest/gtest.h"
#include	<iostream>
#include	<algorithm>
#include    <string>
#include    <cassert>

using namespace std;

void ReverseByWordInplace(string& str)
{
    int len = str.size();
    int start_index = -1;
    if (len < 2) return;
    for(int i=0; i<str.size(); ++i) {
        if (str[i] !=' ') {
            if (start_index != -1)
                start_index = i;
        } else {
          if (start_index != -1) {
            reverse(str.begin() + start_index, str.begin()+i);
            start_index = 0;
          }
        } 
    }
    if (start_index != -1)
        reverse(str.begin()+start_index, str.end());
    reverse(str.begin(), str.end());
}

TEST(ReverseByWordInplace, string)
{
    string s1("");
    string s2("a");
    string s3("a ");
    string s4("a b");
    string s5("a    b");
    string s6("a b ");
    string s7(" a");
    string s8(" a ");
    string s9(" ab ");
    string s10("ab cd ef");
    string s11(" ab cd ef");
    string s12("ab cd ef ");
    string s13(" ab cd ef ");
    
    ReverseByWordInplace(s1);
    EXPECT_STREQ(s1.c_str(), "");

    ReverseByWordInplace(s2);
    EXPECT_STREQ(s2.c_str(), "a");

    ReverseByWordInplace(s3);
    EXPECT_STREQ(s3.c_str(), " a");

    ReverseByWordInplace(s4);
    EXPECT_STREQ(s4.c_str(), "b a");

    ReverseByWordInplace(s5);
    EXPECT_STREQ(s5.c_str(), "b    a");

    ReverseByWordInplace(s6);
    EXPECT_STREQ(s6.c_str(), " b a");

    ReverseByWordInplace(s7);
    EXPECT_STREQ(s7.c_str(), "a ");

    ReverseByWordInplace(s8);
    EXPECT_STREQ(s8.c_str(), " a ");

    ReverseByWordInplace(s9);
    EXPECT_STREQ(s9.c_str(), " ba ");

    ReverseByWordInplace(s10);
    EXPECT_STREQ(s10.c_str(), "fe dc ba");

    ReverseByWordInplace(s11);
    EXPECT_STREQ(s11.c_str(), "fe dc ba ");

    ReverseByWordInplace(s12);
    EXPECT_STREQ(s12.c_str(), " fe dc ba");

    ReverseByWordInplace(s13);
    EXPECT_STREQ(s13.c_str(), " fe dc ba ");

    //EXPECT_STREQ(s1.c_str(), "");

}

void DisplayBin(ostream& out, int v, int len=32)
{
    for (int i = len-1; i>0; --i) 
        out << ( (v&(1LU<<i)) >>i);
    out << (v&1LU);
}

void MultipyWithCurrent(int* a, int len)
{
    if (len < 2) return;

    int* b = new int[len];
    int* c = new int[len];
    int* d = new int[len];
    cout << "A[] : "<<endl;
    for (int i=0; i<len; ++i) {
        DisplayBin(cout, a[i]) ;
        cout << endl;
        c[i] = i>1?c[i-1]*a[i]:a[0];
    }
    cout << endl;
    cout << "B[] : " << endl;
    for (int i=len-1; i>0; --i)
        d[i] = i==len-1?a[len-1]:d[i+1]*a[i];

    for (int i=0; i<len; ++i) {
        b[i] = i==0 ? d[1] : (i==len-1 ? c[i-1] : c[i-1]*d[i+1]);
        DisplayBin(cout, b[i]);
        cout <<  endl;
    }
        cout <<  endl;
    DisplayBin(cout, (int)(a[0]*b[0]));
        cout <<  endl;
    
    delete d;
    delete c;
    delete b;
}


TEST(string, operation)
{
    string s0;
    char s[20] = "a";
    int* p = (int*)s;
    p[0] = 0x61626364;
    p[1] = 0x31323334;
    p[2] = 0x41424344;
    
    for (int i =0; s[i]; ++i)
        cout << hex << (int)s[i] << "\t";
    cout<<endl;
    for (int i =0; s[i]; ++i)
        cout << s[i] << "\t";
    cout<<endl;


    cout << s0.size() << " " <<s0.max_size() << " " << s0.capacity() <<endl;
    string s1("");
    string s2("test1");
    string s3("abcdef");
    ASSERT_EQ(s1.size(), 0);
    ASSERT_EQ(s1.size(), 0);
    EXPECT_EQ(s2.size(), 5);

    EXPECT_EQ(s3.at(2), 'b');
    EXPECT_EQ(s3.front(), 'a');
    EXPECT_EQ(s3.back(), 'f');

    s2.resize(2);
    EXPECT_STREQ(s2.c_str(), "te");
    s2.clear();
    EXPECT_STREQ(s2.c_str(), "");

    EXPECT_STREQ((s2+s3).c_str(), s3.c_str());

    s2.append(s3);
    EXPECT_STREQ(s2.c_str(), s3.c_str());

    s1.push_back('a');
    EXPECT_EQ(s1[0], 'a');

    s1.assign("test001");
    EXPECT_EQ(s1.size(), 7);

    s1.insert(1, string("i"));
    EXPECT_EQ(s1[2], 'e');

    s1.insert(s1.begin(), s3.begin(), s3.end());
    EXPECT_EQ(s1[3], 'e');
}

TEST(MultipyWithCurrent, SHORT)
{
    int a[] = {2, 4, 8, 16, 32}; 
    MultipyWithCurrent(a, 5);
//    cout << "BIN: " << DisplayBin(cout, 8) << " " << DisplayBin(cout, 16) << endl;

    DisplayBin(cout, 8);

    char c1 = 'z';
    char c2 = 'Z';
    cout << (char)(c1&(~('a'^'A'))) << "|" << (char)(c1|('a'^'A')) << "|" << (char)(c1^('a'^'A')) <<endl;
    cout << (char)(c1&(~('A'^'a'))) << "|" << (char)(c1|('A'^'a')) << "|" << (char)(c1^('A'^'a')) <<endl;
    DisplayBin(cout, c1);
    cout << endl;
    DisplayBin(cout, 'a'^'A');
    cout << endl;
    
    DisplayBin(cout, ~('a'^'A'));
    cout << endl;
    cout << hex << (int)'a' << " ^ " << (int)'A' << " = " << ('a'^'A') << endl;
}

