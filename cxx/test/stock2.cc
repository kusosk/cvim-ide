/*
 * =====================================================================================
 *
 *       Filename:  stock2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2013 07:19:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int curr_profit = 0; 
            int last_price = -1;
            int curr_price = -1;

            vector<int>::iterator first = prices.end();
            vector<int>::iterator last = prices.end();

            for (vector<int>::iterator curr = prices.begin();
                    curr != prices.end(); curr++) {
                curr_price = *curr;
                if (curr_price > last_price) {
                    if (first == prices.end())
                        first = last = curr;
                    else
                        last = curr;
                    last_price = curr_price;
                } else if (curr_price < last_price) {
                    if (first == prices.end()) {
                        last_price = curr_price;
                        continue;
                    }
                    curr_profit += last_price - *first;
                    last = prices.end();
                    first = curr;
                    last_price = curr_price;
                }
            }

            if (first != prices.end())
                curr_profit += curr_price - *first;

            return curr_profit;
        }
};


int main()
{
    Solution s;
    vector<int> prices;
    prices.push_back(4);
    prices.push_back(1);
    prices.push_back(2);
    cout << s.maxProfit(prices) << endl;
    return 0;
}
