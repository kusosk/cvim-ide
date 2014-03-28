/*
 * =====================================================================================
 *
 *       Filename:  tier_t1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/24/2013 05:28:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include "tier.h"

#include	<iostream>
#include	<stack>
#include	<cstring>
#include    <string>

void func1()
{
    Tier root;
    int last_found_idx = -1;
    std::cout << "root@" << &root<<endl;
    std::cout << root.PeekWord("ABC", last_found_idx)<< " last pos:" << last_found_idx << endl;
    Tier* curr = root.SearchWord("AA", true, last_found_idx, true, true);
    if (curr)
        std::cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        std::cout << "NOT FOUND, last pos:"<< last_found_idx << endl;

    curr = root.PeekWord("AB", last_found_idx);
    if (curr)
        std::cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        std::cout << "NOT FOUND, last pos:"<< last_found_idx << endl;

    curr = root.PeekWord("BA", last_found_idx);
    if (curr)
        std::cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        std::cout << "NOT FOUND, last pos:"<< last_found_idx << endl;

    curr = root.SearchWord("BA", true, last_found_idx, true, true);
    if (curr)
        std::cout << curr << curr->cnt << " last pos:"<< last_found_idx << endl;
    else
        std::cout << "NOT FOUND, last pos:"<< last_found_idx << endl;

    /*

*/
};

int main()
{
    func1();
    return 0;
}
