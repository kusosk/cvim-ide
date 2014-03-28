#include "gtest/gtest.h"
#include	<iostream>
#include	<climits>
#include    <string>
#include    <cassert>

using namespace std;

TEST(, )
{
    ASSERT_EQ(, );
}

int
main ( int argc, char *argv[] )
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int atoi(const char* str)
{
    long long result = 0;
    bool positive = true;
    int curr_pos = 0;

    if (!str || str == "")
        return 0;

    if (str[curr_pos] == ' ') {
        bool found_digit_sign = false;
        for (int pos = 1; str[pos] != '\0'; ++pos) {
            if (str[pos] == ' ') continue;
            if (str[pos] == '+')
                found_digit_sign = true;
            else if (str[pos] == '-') {
                found_digit_sign = true;
                positive = !positive;
            } else if (str[pos] >= '0' && str[pos] <= '9') {
                curr_pos = pos;
                break;
            } else
                return 0; // unexpected char found, invlid string
        }
        return 0; // "                  " found, return 0
    }

    if (str[curr_pos] == '+') {
        curr_pos ++;
    } else if (str[curr_pos] == '-') {
        positive = !positive;
        curr_pos ++;
    }
    for (; str[curr_pos] != '\0'; curr_pos++) {
        if (str[curr_pos] == '0' && result == 0)
                        continue;
        if (str[curr_pos] >= '0' && str[curr_pos] <= '9') {
            result = result*10 + str[curr_pos] - '0';
        } else
            break; // found non-digit
    }

    result = positive ? result : -result;

    if (result > INT_MAX)
        return INT_MAX;
    else if (result < INT_MIN)
        return INT_MIN;
    else
        return (int)result;
}

TEST(atoi, LEADING_SPACES)
{
    ASSERT_EQ(atoi(NULL), 0);
}

    int
main0 ( int argc, char *argv[] )
{
    /*
    char* c0 = NULL;
    assert(atoi(c0) == 0);
    char* c01 = "";
    assert(atoi(c01) == 0);
    char* c1 = "     ";
    assert(atoi(c1) == 0);
    char* c2 = "  +   ";
    assert(atoi(c2) == 0);
    char* c3 = "  -   ";
    assert(atoi(c3) == 0);
    char* c4 = "  +1   ";
    assert(atoi(c4) == 0);
    char* c5 = "  -1   ";
    assert(atoi(c5) == 0);
    char* c6 = "+1";
    assert(atoi(c6) == 1);
    char* c7 = "1";
    assert(atoi(c7) == 1);
    char* c8 = "-1";
    assert(atoi(c8) == -1);
    char* c9 = "12354";
    assert(atoi(c9) == 12354);
    char* c10 = "123a54";
    assert(atoi(c10) == 123);
    char* c11 = "12354abcd";
    assert(atoi(c11) == 12354);
    char* c12 = "-12354";
    assert(atoi(c12) == -12354);
    char* c13 = "-123a54";
    assert(atoi(c13) ==-123);
    char* c14 = "-12354abcd";
    assert(atoi(c14) == -12354);

    char* c15 = "1234567890123456";
    assert(atoi(c15) == INT_MAX);
    char* c16 = "-1234567890123456";
    assert(atoi(c16) == INT_MIN);
    char* c17 = "2147483647";
    assert(atoi(c17) == INT_MAX);
    char* c18 = "-2147483648";
    assert(atoi(c18) == INT_MIN);
    char* c19 = "010";
    cout << atoi(c19) << endl;
    char* c20 = " 010";
    cout << atoi(c20) << endl;


    cout << "succeed" << endl;
*/
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}				/* ----------  end of function main  ---------- */
