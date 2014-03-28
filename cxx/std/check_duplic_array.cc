/*
 * =====================================================================================
 *
 *       Filename:  check_duplic_array.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/18/2013 06:17:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<cstring>

using namespace std;

bool CheckArrayHasDuplicatedItem(int* array)
{
    bool result = false;
    return result;
}
void swap(char &a, char &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

void reverse2(char *s){
    int n = strlen(s);
    for(int i=0; i<n/2; ++i)
        swap(s[i], s[n-i-1]);
}
void reverse_cstr(char* str)
{
    char* front = str;
    char* end = NULL;
    if (!str || str=="")
        return;
    char* pos = front;
    while(*pos) {
        pos++;
    }
    if (pos != front)
        end = pos - 1;
    while ( front < end ) {
        char tmp = *front;
        cout << "curr : [" << str<< "] [" <<*front << "][" <<*end <<"]"<< endl;
        *front = *end;
        *end = tmp;
        ++front;
        --end;
    }

}
void reverse(char* s)
{
    char* f = s;
    char* e = s;
    if (!s || s == "")
        return;

    int len = strlen(s);
    for (int i = 0; i < len/2; ++i) {
        s[i] = s[i] ^ s[len-i-1];
        s[len-i-1] = s[i]  ^ s[len-i-1];
        s[i] = s[i] ^ s[len-i-1];
    }
}

    int
main ( int argc, char *argv[] )
{
    char* s1 = new char[6];
    strcpy(s1, "abcde");
    cout << s1 << endl;
    cout << "s1 len" << sizeof(s1) << endl;
    cout << s1 << endl << endl;
    reverse2(s1);
    cout << s1 << endl << endl;
    reverse_cstr(s1);
    cout << ":" << s1 << ": " << endl;
    reverse(s1);
    cout << ":" << s1 << ": " << endl;
    int a = 100;
    int b = 9;
    a=a^b;
    cout << a << endl;
    cout << b << endl;
    cout << a << endl;
    b=a^b;
    cout << b << endl;
    a=a^b;
    cout << a << endl;
    cout << b << endl;

    return 0;
}				/* ----------  end of function main  ---------- */
