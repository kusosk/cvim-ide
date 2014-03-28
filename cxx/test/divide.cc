#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>

using namespace std;
class t1 {
    static vector<int> v1;
public:

    void func1() {
        v1.push_back(100);
        cout << v1.size() << endl;
    }
};
vector<int> t1::v1;
int main()
{
    t1 t11;
    t11.func1();
    return 0;
}
