#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stack>
#include    <algorithm>
#include    <vector>

using namespace std;

int trap(int A[], int n) {
    int i=1;//i should be 1 not 0
    int res=0;
    stack<int> v, pos;
    if (n<=0) return res;
    v.push(A[0]);
    pos.push(0);
    while(i<n) {
        if (v.empty() || pos.empty()) return res;
        cout << i << " " << pos.top() << " " << v.top() << endl;
        if (A[i] < v.top()) {
            pos.push(i);
            v.push(A[i]);
        } else {
            int lv=v.top();
            int lp=pos.top();
            v.pop(); pos.pop();
            if (v.empty() || pos.empty())// wrong: return res;
            {
                v.push(A[i]); pos.push(i); 
                i++; // Wrong!!!! I missed it here
                continue; // right: add current as new lowest, skip the former one
            }
            if (A[i] <= v.top()) {
                res+=(i-lp)*(A[i]-lv);
                v.push(A[i]);
                pos.push(lp);//not i, merge the lowest into new height(higher)
            } else {
                while(!v.empty() && A[i] > v.top()) {// not >=!!, if A[i]==v.top(), continue the processing
                    int lowv=v.top();
                    int lp2=pos.top();
                    v.pop(); pos.pop();
                    res+=(lowv-lv)*(i-lp);
                    lv=lowv;
                    lp=lp2;
                }
                if (A[i]<=v.top()) 
                    res+=(A[i]-lv)*(i-lp);//I missed this, it will miss some part
                if (A[i]<v.top()) {// if A[i]==v.top(), continue without push current value
                    pos.push(lp);
                    v.push(A[i]);
                }
            }
        }
        i++;
    }
    return res;
}

int main()
{
    int A[]={4,2,0,3,2,5};
    cout << trap(A, 6) << endl; 
    return 0;
}
