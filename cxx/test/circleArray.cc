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
bool isCycleArray(int A[], int n)
{
    unordered_map<int, bool> visited;
    for (int i=0; i<n; ++i) {
        visited.clear();
        int j=i;
        do {
            if (visited.find(j) != visited.end()) {
                if (visited.size() == n)
                    return true;
                else 
                    break;
            }
            int ni=A[i]+i;
            if (ni >= n) {
                ni %= n;
            }
            if (ni < 0)
                ni = n-(-ni)%n;
            visited.emplace(j, true);
            j=ni;
        } while(j != i);
    }
    return false;
}
int main()
{
    
    return 0;
}
