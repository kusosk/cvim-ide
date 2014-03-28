#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>
#include    <stdexcept>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    // IMPORTANT: Please reset any member data you declared, as
    //         // the same Solution instance will be reused for each test case.
    vector<int> result;
    vector<int> copy;
    for (int i = 0; i < numbers.size(); ++i) {
        copy.push_back(numbers[i]);
    }
    sort(copy.begin(), copy.end());
    size_t first = 0;
    size_t second = copy.size()>0?copy.size()-1:0;
    while(first <= second) {
        int sum = copy[first]+copy[second];
        if (sum < target) 
            ++first;
        else if (sum > target)
            --second;
        else {
            first = copy[first];
            second = copy[second];
            break;
        }
    }

    cout << first << " " << second << endl;
    for (int i = 0; i < numbers.size(); ++i) 
        cout << numbers[i] << " ";
    cout << endl;    

    for (int i = 0; i < numbers.size(); ++i) 
        if(numbers[i] == first) {
            first = i;
            break;
        }
    cout << first << " " << second << endl;
    for (int i = 0; i < numbers.size(); ++i) {
        if(numbers[i] == second)
            second = i;
    }
    cout << first << " " << second << endl;
    if(first>=second) {
        result.push_back(second+1);
        result.push_back(first+1);
    } else  {
        result.push_back(first+1);
        result.push_back(second+1);
    }
    return result;
}

int main()
{
    vector<int> in;
    in.push_back(150);
    in.push_back(24);
    in.push_back(79);
    in.push_back(50);
    in.push_back(88);
    in.push_back(345);
    in.push_back(3);
    vector<int> res = twoSum(in, 200);
    for (int i =0; i<res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
