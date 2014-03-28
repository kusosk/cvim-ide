#include	<iostream>
#include	<cstring>
#include    <string>

using namespace std;
bool** isPal;

bool is_parlindrome(string str, int m, int n)
{
    if (m==n) 
    {
    isPal[m][m]=true;
    return isPal[m][m];
    }
    if (n-m>2)
        return isPal[m][n]=isPal[m+1][n-1]&&str[m]==str[n];
    else
        return isPal[m][n]=str[m]==str[n];
}
string longestPalindrome(string str) {
    // IMPORTANT: Please reset any member data you declared, as
    //         // the same Solution instance will be reused for each test case.
    if (!str.size()) return "";
    int l = str.size();
    
    isPal = new bool* [l];
    try {
    for(int i = 0; i<l;i++)
        isPal[i] = new bool[l];
    } catch (bad_alloc& e){
        cout << e.what() << endl;
        delete [] isPal;
        return "";
    }
    cout << "1" << endl;
    for (int m=l-1; m>=0; --m)
        for(int n=m; n<l; ++n)
        {
            is_parlindrome(str, m, n);
        }
    cout << "2" << endl;
    string res(str);
    for (int m=0, n=l-1; m<n&&n-m<l; ) {
        if (m+1<n&&isPal[m][n]) {
            return res.substr(m, n-m+1);
        } else if (m+1<n&&isPal[m+1][n]) {
            return res.substr(m+1, n-m);
        } else if (m+1<n&&isPal[m][n-1]) {
            return res.substr(m, n-m);
        } else {
            ++m, --n;
        }
    }
       cout << "free0" << endl;
    for(int i = 0; i<l;i++)
    {   cout << "free1" << endl;
        delete[] isPal[i];
    }
    cout << "free2" << endl;
    delete[] isPal;
    cout << "free3" << endl;
    return "";

}
int main()
{
    string s("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
    cout << s.size() << endl;
    string res = longestPalindrome(s);
    cout << res<<endl;
    return 0;
}
