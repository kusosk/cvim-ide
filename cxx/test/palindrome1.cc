#include	<iostream>
#include	<cstring>
#include	<cstdio>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;
char buff[10001];
void FindPalindrome(const char* s, size_t l)
{
    if (!s || l < 2)
        return;
    size_t max_len = (l<<1)+2;
    char* str = NULL;
    int * p = NULL;
    size_t id = -1;
    size_t maxid = -1;
    size_t i = 0;
    try {
        str = new char[max_len+1];
        memset(str, 0, max_len+1);
        try {
            p = new int[max_len];
            memset(p, 0, sizeof(int)*max_len);
        } catch(bad_alloc&) {
            delete[] str;
            cout << "Cannot alloc memory to record max_len"<<endl;
            return;
        }
    } catch (bad_alloc&){
        cout << "Cannot alloc memory to extend string"<<endl;
        return;
    }
    str[0] = '$';
    for (i=0; i<l; i++) {
        str[i*2+1] = '#';
        str[i*2+2] = s[i];
    }
    str[max_len-1]='#';
    str[max_len] = '\0';
    cout << str<<endl;
    p[0]=0;
    maxid=id=0;
    for (i=1;i<max_len;i++) {
        if (maxid > i)
            p[i] = maxid-i<p[2*id-i] ? maxid-i : p[2*id-i];
        else
            p[i] = 1;
        while (str[i+p[i]] == str[i-p[i]])
            p[i]++;
        if (i+p[i]-1 > maxid) {
            maxid = i+p[i]-1;
            id = i;
        }
    }
    for (i = 0; i < max_len; ++i)
        cout << p[i];
    cout << endl;


    int maxp=2;
    size_t idx=0;
    string s_origin(s);
    cout << "origin string: " << endl<<s <<endl;
    for (i = 0; i < max_len; i++)
        cout << i%10;
    cout << endl;
    for (i = 0; i < l; i++)
        cout << p[(i<<1)+2]-1;
    cout << endl;
    for (i=0; i<max_len; i++) {
        if (p[i] >= maxp) {
            try {
            cout << s_origin.substr((i-p[i])/2, p[i]-1) << " length="<< p[i]-1<<endl;
            } catch (out_of_range& e) {
                cout << e.what() << " : @" << i << endl;
            }
            idx = i;
            maxp = p[i];
        }
    }
    delete[] p;
    delete[] str;
}

int main()
{
    while (1) {
        scanf("%s", &buff);
        if (!strcmp(buff, "!"))
            break;
        FindPalindrome(buff, strlen(buff));    
    }
    return 0;
}
