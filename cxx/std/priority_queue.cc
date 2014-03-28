#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <memory>
#include    <unordered_map>
#include    <queue>

using namespace std;
class ComparePair {
    public:
        bool operator()(pair<int, int>& l, pair<int, int>& r) {
            return l.first > r.first;
        }
};
typedef priority_queue<pair<int, int> > PPI;

void test1()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, ComparePair> ppi;
    ppi.push(make_pair(6, 5));
    ppi.push(make_pair(10, 4));
    ppi.push(make_pair(2, 11));
    ppi.push(make_pair(8, 14));
    ppi.push(make_pair(1, 24));
    ppi.push(make_pair(3, 34));
    ppi.push(make_pair(1, 44));

    while(!ppi.empty()) {
        pair<int, int> t = ppi.top();
        ppi.pop();
        cout << t.first << " ";
    }
    cout << endl;
}

int main()
{
    test1();    
    return 0;
}
