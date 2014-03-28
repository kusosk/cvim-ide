#include	<iostream>
#include	<map>
#include    <string>
#include    <utility>
#include    <stdexcept>

using namespace std;

void test1()
{
    multimap<string, int> res;
    res.insert(pair<string, int>("test1", 11));
    res.insert(pair<string, int>("test3", 31));
    res.insert(pair<string, int>("test3", 32));
    res.insert(pair<string, int>("test2", 21));
    res.insert(pair<string, int>("test1", 12));
    res.insert(pair<string, int>("test3", 33));
    res.insert(pair<string, int>("test2", 22));
    res.insert(pair<string, int>("test1", 13));
    res.insert(pair<string, int>("test1", 14));
    res.insert(pair<string, int>("test3", 34));

    for (multimap<string, int>::reverse_iterator rit=res.rbegin();
            rit!=res.rend(); ++rit) {
        cout<<rit->first << ":" << rit->second <<endl;
    }
}

int main()
{
    test1();
    return 0;
}
