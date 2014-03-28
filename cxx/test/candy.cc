#include	<iostream>
#include	<vector>
#include    <string>
#include    <exception>
#include    <stdexcept>

using namespace std;

void func1()
{

}
int candy(vector<int> &ratings) {
    vector<int> candies(ratings.size());
    for (size_t i = 0; i < ratings.size(); ++i) {
        if (i > 0 && ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1]+1;
        }
    }
    int res = ratings.size() > 0 ?
        ratings.size() + candies[ratings.size()-1] : ratings.size(); 
    for (int i = ratings.size()-2; i>=0; --i) {
        if (ratings[i] > ratings[i+1]) {
            candies[i] = candies[i] < candies[i+1]+1 ? 
                candies[i+1]+1 : candies[i];
        }
        res += candies[i];
    }
    return res;
}
int candy1(vector<int> &r) {
    size_t sz=r.size();
    if (sz < 2) return sz;

    int order = -1;// -1 undef, 0 desc, 1 asc
    int res = 1, cnt=0, cv=1;
    for (int i=1; i<sz; ++i) {
        if (order == -1) {
            if (r[i]> r[i-1]) { // missed cnt=0;
                order=1;
                //cnt=0;
            }
            else if (r[i] < r[i-1]) {
                order=0;             
                //cnt=0;
            } else 
                cnt--; // don't count numbers on the equal range
        }
        // } else if (!order) { wrong will skip some case
    if (!order) {
        if (r[i]>=r[i-1]) {
            res += (1-cv)*(cnt+1);
            //cv = 2; // 4 3 2 1 2 2 2 .... || 4 3 2 1 4 3 2 || 4 3 2 1 4 5 6 
            if (r[i]==r[i-1]) {
                cv=1;
            } else 
                cv=2;
            order=-1;
            cnt=0;
        } else if (r[i]<r[i-1]) 
            --cv;
    } else if (order==1) {
        if (r[i] <= r[i-1]) {
            cv = 1;
            order=-1; 
            cnt=0;
        } else if (r[i] > r[i-1])
            ++cv;
    }
    res += cv;
    ++cnt;
}
cout << "1: " << res<<endl;
// last part
if (!order && cv!=1) 
    res += (1-cv)*(cnt+1);
    return res;
    }

int candy3(vector<int> &r)
{
    vector<int> c(r.size(), 0);
    for (int i=1; i<r.size(); ++i)
        c[i] = c[i]>c[i-1] ? c[i-1]+1 : c[i];
}
int main()
{
    vector<int> input(15);
    input[0] = 1;
    input[1] = 2;
    input[2] = 3;
    input[3] = 10;
    input[4] = 9;
    input[5] = 8;
    input[6] = 7;
    input[7] = 6;
    input[8] = 3;
    input[9] = 4;
    input[10] = 5;
    input[11] = 3;
    input[12] = 7;
    input[13] = 2;
    input[14] = 8;
    cout << candy(input) << endl;
    vector<int> in{1, 2, 4, 3, 2, 1};
    vector<int> in2{3, 3, 3, 1};
    cout << candy(in2) << endl;
    cout << candy1(in2) << endl;
    return 0;
}
