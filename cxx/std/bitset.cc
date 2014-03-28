#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <bitset>
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

int main()
{
    const int n = 10;
    bitset<n> bs;
    bs.set(3);
    cout << bs << endl;
    return 0;
}
