#include	<climits>
#include	<stack>
#include	<iostream>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;
int largestRectangleArea(vector<int> &h) {  
    stack<int> S;  
    h.push_back(0);  
    int sum = 0;  
    for (int i = 0; i < h.size(); i++) {  
        if (S.empty())
            cout << "@" << i << " "<<h[i] << " top:NULL" <<  endl;
        else
            cout << "@" << i << " "<<h[i] << " top:" << S.top() << endl;
        if (S.empty() || h[i] > h[S.top()]) S.push(i);  
        else {  
            int tmp = S.top();  
            S.pop();  
            sum = max(sum, h[tmp]*(S.empty()? i : i-S.top()-1));  
            cout << i <<" sum:" << sum <<endl;
            i--;  
        }  
    }  
    return sum;  
}  

int largestRectangleArea1(vector<int> &height) {
        int sz=height.size();
        if (!sz) return 0;
        if (sz==1) return height[0];
        int res=0;
        stack<int> highest;
        int curr;
        for (int i = 0; i<=sz; i++) {
            if (i==sz)  curr=-1;
            else curr=height[i];
            if (highest.empty() || curr>height[highest.top()]) highest.push(i); 
            else {
                if(height[highest.top()] > curr) {
                    int idx = highest.top();
                    highest.pop();
                    res=max(res, height[idx]*(highest.empty()?i:i-idx-1));
                }
                i--;
            }
        }
        return res;
    }
int main()
{
    vector<int> i{7,2,3};    
    cout << largestRectangleArea(i) << endl;
    cout << largestRectangleArea1(i) << endl;
    return 0;
}
