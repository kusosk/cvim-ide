#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <queue>
#include    <set>
#include    <deque>
#include    <list>
#include    <stack>
#include    <iterator>
#include    <cassert>
#include    <memory>
#include    <unordered_map>
#include    <unordered_set>

using namespace std;
int sqrt(int x) {
    if (x<0) throw invalid_argument("Wrong input");
    if (!x || x==1) return x;
    int e=0;
    
    while(e<x) {
        ++e;
        if ((1<<(e<<1))>=x) break;
    }
    int l = 1<<(e-1);
    int r = 1<<e;
    while (l<r) {
        int m=l+((r-l)>>1);
        int t1 = m*m;
        int t2 = t1 + (m<<1) + 1, t3 = t1 - (m<<1) +1;
        if (t1 == x) return m;
        else if (t1 <x) {
            if (x == t2) return m+1;
            else if (x < t2) return m;
            else l=m+1;
        } else {
            if (t3 >= x) return m-1;
            else 
                r = m-1;
        }
    }
    return l;
}
int compareDouble(const double x, const double y)
{
    double diff = x-y;
    return diff < -numeric_limits<double>::epsilon() ? -1 :
        diff > numeric_limits<double>::epsilon();
}
int compareDouble1(const double x, const double y)
{
    double diff = (x-y)/y;
    return diff < -numeric_limits<double>::epsilon() ? -1 :
        diff > numeric_limits<double>::epsilon();
}
double sqrt_d(double x)
{
    if (compareDouble(x, 0) == -1) throw invalid_argument("Negtive input"); 
    if (!compareDouble(x, 0) || !compareDouble(x, 1.0)) return x;
    double l,r,t,m;
    if (compareDouble(x, 1) < 0) { l=x, r=1;}
    else {l=1, r=x;}
    int cnt=0;
    while (compareDouble(l,r)<0) {
        cout << r-l << endl;
        m = l+0.5*(r-l);
        if (!compareDouble(m,t)) break;
        /*
        t = x/m;
        cnt++;
        int cr = compareDouble(t,m);
        if (!cr) {
            cout << "[cnt] " << cnt << endl;
            return m;
        }
        else if (cr<0) r=m;
        else l=m;
        */
        t = m*m;
        cnt++;
        int cr = compareDouble(t,x);
        if (!cr) {
            cout << "[cnt] " << cnt << endl;
            return m;
        }
        else if (cr>0) r=m;
        else l=m;
    }
    cout << "[cnt] " << cnt << endl;
    return r;
}
void test1()
{
    cout << sqrt(3) << " " << sqrt(15) << " " << sqrt(27) << " "
        << sqrt(35) << " " << sqrt(48) << " " << sqrt(52) << endl;
}
void test2()
{
    cout << sqrt_d(8) << endl;
}
int main()
{
    //test2();
    //2.22045e-16
    double d1 = 2.22045e-17;//0.1e-20;
    cout << d1 << " "<<d1-numeric_limits<double>::epsilon() << " | " << numeric_limits<double>::epsilon() << " "<< compareDouble(d1, numeric_limits<double>::epsilon()) << endl;
    cout << compareDouble(d1, 0.0) << endl;
    cout << compareDouble1(d1, 0.0) << endl;

    cout << sizeof(unsigned long long) << endl;
    cout << sizeof(long) << endl;
    return 0;
}
