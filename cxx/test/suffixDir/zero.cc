#include	<iostream>
#include	<climits>
#include    <string>
#include    <limits>
#include    <stdexcept>

using namespace std;

void func1()
{
    cout << numeric_limits<double>::epsilon() << " " << numeric_limits<float>::epsilon()
        << " " << numeric_limits<int>::epsilon();
}

template<typename T>
int compare(T t1, T t2)
{
    T epsilon = numeric_limits<T>::epsilon();
    if (t1-t2 > epsilon) {
        return 1;
    } else {
        if (t2-t1 <= epsilon)
            return 0;
        else 
            return -1;
    }
}

int main()
{
    func1();
    
    return 0;
}
