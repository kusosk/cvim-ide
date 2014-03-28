#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;

int maxArea(vector<int> &height) {
        if (!height.size()) return 0;
        int sz=height.size();
        int res=0;
        
        int l=0, r=sz-1;
        while(l<r) {
            int tmp=min(height[l], height[r])*(r-l);
            res = max(tmp, res);
            if (height[l] < height[r]) {
                if (l+1==r) break;
                int i =0;
                while(height[l]>=height[l+1]){ l++; i++; }
                if (!i) l++;
            } else {
                if (r-1==l) break;
                int i = 0;
                while(height[r]>=height[r-1]){ r--; i++;}
                if (!i) r--;
            }
        }
        return res;
    }
int main()
{
    vector<int> res={1,2,1};
    cout << maxArea(res) <<endl;    
    return 0;
}
