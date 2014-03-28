#include	<iostream>
#include	<algorithm>
#include    <string>
#include    <map>
#include    <vector>

using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    map<int, int> last;
    int total=0;
    if (gas.size() != cost.size()) return -1;
    if (!gas.size()) return -1;
    int sz=gas.size();

    for(int i=0; i<sz; ++i) {
        int curr = gas[i] - cost[i];
        last[curr] = i;
        total+=curr;
    }
    if (total < 0) return -1;
    //sort(last.begin(), last.end());

    for(map<int, int>::reverse_iterator it=last.rbegin(); it!=last.rend() && it->first >=0; ++it) {
        int idx = it->second;
        int v = it->first;
        int i=idx;
        total=0;
        for (;i<idx+sz;++i) {
            total+=gas[i%sz]-cost[i%sz];
            if(total<0) break;
        }
        if (i==idx+sz)
            return idx;
    }
    return -1;
}

int main()
{
    vector<int> g{1, 2, 3, 4, 5};
    vector<int> c{3, 4, 5, 1, 2};
    cout << canCompleteCircuit(g, c)<<endl;
    return 0;
}
