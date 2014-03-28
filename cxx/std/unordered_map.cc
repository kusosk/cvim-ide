#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <unordered_map>

using namespace std;

int main()
{
    unordered_map< pair<int, int>, int> hm;
    hm.emplace(pair<int,int>(0, 0), 1);
    hm.emplace(pair<int,int>(0, 1), hm[pair<int,int>(0,0)]+1);
    cout << hm[pair<int,int>(0,1)]<<endl;
    return 0;
}
