#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include "gtest/gtest.h"

using namespace std;
int gcd(int a, int b)
{
    if (a==b) return a;
    while(a&&b) {
        if (a>b) swap(a, b);
        b -= a;
    }
    if (!a) return b;
    if (!b) return a;

}
TEST(gcd, ALL)
{
    ASSERT_EQ(gcd(54, 24), 6);
}
