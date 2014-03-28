#include    <vector>
#include	<iostream>

using namespace std;

void swap(int& p1, int& p2)
{
    p1 = p1 ^ p2;
    p2 = p1 ^ p2;
    p1 = p1 ^ p2;
}

void GenPermulation(string str, int i, int j)
{
    if (str.size() == 0)
        return;
    if (i == j) {
        cout << str << endl;
        return ;
    }
    for (int p = i; p <= j; ++p) {
        swap(str[i], str[p]);
        GenPermulation(str, i+1, j);
        swap(str[i], str[p]);
    }

}

void permulation(string str)
{
   GenPermulation(str, 0, str.size()-1); 
   cout << "-----------END" << endl;
}
    int
main ( int argc, char *argv[] )
{
    string s1("");
    permulation(s1);

    string s2("abcd");
    permulation(s2);
    return 0;
}				/* ----------  end of function main  ---------- */
