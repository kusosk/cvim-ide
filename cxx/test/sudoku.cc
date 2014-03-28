#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <unordered_map>

using namespace std;
bool checkLine(vector<vector<char> > &b, int mode)
{
    for (int i = 0; i< 9; ++i) {
        vector<bool> e(10, false);
        for (int j = 0; j<9; ++j) {
            if (mode?b[j][i]:b[i][j] == '.') continue;
            if (e[mode?b[j][i]:b[i][j] -'0'])
                return false;
            else
                e[mode?b[j][i]:b[i][j] -'0'] = true;
        }
    }
    return true;
}
bool checkBlock(vector<vector<char> > &b, int r, int c)
{
    for (int i = 0; i<3; ++i) {
        vector<bool> e(10, false);
        for (int j = 0; j<3; ++j) {
            if(b[r+i][c+j] == '.') continue;
            if (e[b[r+i][c+j] -'0'])
                return false;
            else
                e[b[r+i][c+j] -'0'] = true;
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char> > &b) {

    bool rv= !checkLine(b, 0) || !checkLine(b, 1);
    cout << "1" << rv <<endl;

    if (!rv) return !rv;

    cout <<"2" <<  rv <<endl;
    rv = !checkBlock(b, 0, 0) || !checkBlock(b, 3, 0) || !checkBlock(b, 6, 0) || !checkBlock(b, 0, 3) || !checkBlock(b, 3, 3) || 
        !checkBlock(b, 6, 3) || !checkBlock(b, 0, 6) || !checkBlock(b, 3, 6) || !checkBlock(b, 6, 6);
    return !rv;
}
int main()
{
    vector<vector<char> > in {
        {"....8..."},
        {},
        {},
        {},
        {},
        {}
    };
    cout << in.size() << endl;
    return 0;
}
