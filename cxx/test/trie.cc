#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <cassert>
#include    <memory>
#include    <stdexcept>

using namespace std;

#define BRANCHNUM    256
#define NUMS    100

static int v = 0;
template<int N>
struct Tries {
    Tries<N>* bs[N];
    bool isword;
    Tries():bs{nullptr}, isword{false} {
    }
    virtual ~Tries() {
        for (auto t:bs) {
            if (t) {
                delete t;
            }
        }
    }
    void insert(string s) {
        if (!s.size()) return;
        Tries<N>* curr=this;
        for (char c:s) {
            if(!curr->bs[c]){
                curr->bs[c]=new Tries<N>();
            }
            curr = curr->bs[c];
        }
        curr->isword=true;
    }
    bool find(const string s) {
        bool res = false;
        Tries<N>* curr = this;
        for (char c:s) {
            if (curr->bs[c])
                curr=curr->bs[c];
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Tries<256> root;
    cout << "1" << endl;
    root.insert(string("abcd"));
    root.insert(string("bcd"));
    root.insert(string("acd"));
    cout << root.find(string("cab")) << endl;
    return 0;
}
