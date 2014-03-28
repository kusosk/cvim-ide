#include "gtest/gtest.h"
#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <cstring>

using namespace std;

template <int N=32>
class Bitmap {
    char* storage_;
    const size_t sz;
    size_t capacity;
    size_t len;
    public:
        Bitmap() : sz(N) {
            len = N%8 ? ((N>>3)+1) : (N>>3);
            cout << "sz: " << sz << endl;
            capacity = len<<3;
            storage_ = new char[ len ];            
            if (!storage_) throw std::bad_alloc();
            memset(storage_, 0, len);
        }
        virtual ~Bitmap() {
            if (storage_) delete[] storage_;
        }
        void Display(ostream& out)
        {
            cout << "Bitmap[" << sz << "]:" << endl;
            for (int i = 0; i < len; ++i) {
                for (int b = 0 ; b < 8; ++b)
                    out << ( (storage_[i] & (1LU<<(7-b))) ? 1 : 0 );
                if (i != len-1)
                    out << " | ";
            }
            /*
            cout << "\tRAW: " << endl;
            for (int i = 0; i < len; ++i) {
                out << hex << (int)storage_[i] ;
                if (i != len-1)
                    out << " | ";
            }
            */
            cout << endl;
        }
        bool Set(int i)
        {
            if (i < 0 && i > capacity)
                return false;
            if ( (1<<(7-i%8)) & storage_[i/8] ) {
                cout << "bit[" << i <<"] already set" << endl;
                return false;
            } else {
                storage_[i/8] |= (1<<(7-i%8));
                return true;
            }
        }
        bool Unset(int i)
        {
            if (i < 0 || i > capacity)
                return false;
            if ( (1<<(7-i%8)) & storage_[i/8] ) {
                storage_[i/8] &= ~(1<<(7-i%8));
                return true;
            } else {
                return false;
            }

        }
        size_t Size() const
        {
            return sz;
        }
        size_t Capacity() const
        {
            return capacity;
        }
        void Clear()
        {
            memset(storage_, 0, len);
        }
        bool IsSet(int i)
        {
            return (1<<(7-i%8)) & storage_[i/8];
        }
};

void SortByBitmap(int* v, int sz)
{
    if (!v || sz < 2)
        return;
    Bitmap<100> vs;
    for (int i = 0; i<sz; ++i)
        vs.Set(v[i]);

    for (int i = 0; i < 100; i++)
        if (vs.IsSet(i))
            cout << i << " ";
    cout << endl;
}
TEST(Bitmap, size)
{
    Bitmap<1> b1;
    ASSERT_EQ(b1.Size(), 1);
    ASSERT_EQ(b1.Capacity(), 8);

    Bitmap<9> b2;
    ASSERT_FALSE(b2.IsSet(9));
    cout << "b2.Set(9)=" << b2.Set(9) << endl;
    b2.Display(cout);
    ASSERT_TRUE(b2.IsSet(9));
/**/
    cout << "b2.Set(9)=" << b2.Set(9) << endl;
    b2.Display(cout);
    ASSERT_TRUE(b2.IsSet(9));

    cout << "b2.Set(8)=" << b2.Set(8) << endl;
    b2.Display(cout);
    ASSERT_TRUE(b2.IsSet(8));

    cout << "b2.Unset(10)=" << b2.Unset(10) << endl;
    b2.Display(cout);
    ASSERT_FALSE(b2.IsSet(10));

    cout << "b2.Unset(9)=" << b2.Unset(9) << endl;
    b2.Display(cout);
    ASSERT_FALSE(b2.IsSet(9));


    int v1[] = {1, 99, 5, 12, 87, 94, 70, 3, 10};
    SortByBitmap(v1, 9);
}

