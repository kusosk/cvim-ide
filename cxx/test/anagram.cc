#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <memory>
#include    <map>
#include    <unordered_map>

using namespace std;
typedef multimap<pair<int,int>,int>::iterator MPI;
int strhash(const string& s)
{
    int r = 0;
    for (char c:s)
        r+=1<<(c-'a');
    return r;
}
class PairLess {
    public:
        bool operator() (const pair<int, int>& l, const pair<int, int>& r)
        {
            return l.first < r.first || (l.first==r.first && l.second < r.second);
        }
};
vector<vector<string> > anagrams(vector<string> &S)
{
    vector<vector<string> > res;
    multimap<pair<int, int>, int, PairLess> h;

    if (!S.size()) return res;
    for (int i = 0; i< S.size(); ++i) {
        h.emplace(make_pair(S[i].size(), strhash(S[i])), i);
    }

    auto spos=h.begin();
    for (auto k=h.begin(); k!=h.end();) {
        vector<string> curr;
        auto lb = h.lower_bound((*k).first);
        auto ub = h.upper_bound((*k).first);
        for (MPI pos=lb; pos!=ub; ++pos)
            curr.push_back(S[(*k).second]);
        res.push_back(curr);
        k = ub;
        curr.clear();
    }
    return res;
}
void test1()
{
    pair<int, int> l{1, 3}, r{2, 4}, l1{1,14}, l2{1,1}, l3{2, 1}, l0{1,2};
    multimap<pair<int, int>, int> h;
    h.emplace(l, 10);
    h.emplace(l1, 9);
    h.emplace(l0, 4);
    h.emplace(r, 8);
    h.emplace(l1, 1);
    h.emplace(l, 2);
    h.emplace(r, 5);
    h.emplace(l2, 3);
    h.emplace(l, 6);
    h.emplace(l2, 7);
    /*
       for (auto k=h.begin(); k!=h.end(); ){
       pair<MPI,MPI> range = h.equal_range((*k).first);
       if (range.second-range.first == 1) {
       cout << (*k).first.first<< "," << (*k).first.second << "|" << (*k).second << endl;
       cout << "*****************************" << endl;
       ++k;
       continue; 
       }
       for (auto pos=range.first; pos!=range.second; ++pos)
       cout << (*pos).first.first<< "," << (*pos).first.second << "|" << (*pos).second << endl;
       cout << "*****************************" << endl;
       if (range.second == h.end()) break;
       k = ++range.second;

    //cout <<k.first.first<< "," << k.first.second << "|" << k.second << endl;

    }
    */
    for (auto k = h.begin(); k != h.end();) {
        auto u = h.upper_bound((*k).first);
        auto l = h.lower_bound((*k).first);
        for (MPI pos=l; pos!=u; ++pos)
            cout << (*pos).first.first<< "," << (*pos).first.second << "|" << (*pos).second << endl;
        cout << "*****************************" << endl;
        k = u;
    }
}
void test2()
{
    vector<string> ins{"a", "ab", "bca", "ca", "bac", "cbb", "aa", "ac", "bb", "c"};
    vector<vector<string> >res = anagrams(ins);
    for (auto i : res) {
        for (string s: i)
            cout << s << ",\t";
        cout << endl;
    }
}
struct Pair {
    int first;
    int second;
    bool operator== (const Pair& p) const {
        return first==p.first && second==p.second;
    }
};
template<typename T>
class PairHash {
};
namespace std{
    template<>
        class hash<Pair> {
            public:
                std::size_t operator() (const Pair& v) const
                {
                    size_t h1=std::hash<int>()(v.first);
                    size_t h2=std::hash<int>()(v.second);
                    return h1 ^ (h2<<1);
                }
        };
}
void test3()
{
    unordered_map<Pair, int> h;
    h.emplace(Pair{1, 3}, 5);
    h.emplace(Pair{2, 3}, 4);
    cout << h[Pair{1,3}] << endl;
    return;
}
namespace std {
    struct Pair {
        int first;
        int second;
        bool operator==(const Pair& p) const
        {
            return first==p.first && second==p.second;
        }
    };
    template<>
        class hash<Pair> {
            public:
                size_t operator()(const Pair& p) const 
                {
                    size_t h1 = std::hash<int>()(p.first);
                    size_t h2 = std::hash<int>()(p.second);
                    return h1 ^ (h2<<1);
                }
        };
    class Solution {
        public:
            static int strhash(const string& s)
            {
                int ret=0;
                for (char c:s)
                    ret += 1<<(c-'a');
                return ret;
            }

            typedef unordered_map<Pair, int> MP;
            typedef unordered_map<Pair, int>::iterator MPI;
            static vector<string> anagrams(vector<string> &strs) {
                MP h;
                vector<string> res;
                int p=-1;
                int thv=-1, tlen=-1;
                if (!strs.size()) return res;
                for (int i = 0; i<strs.size(); ++i) {
                    int hv=strhash(strs[i]);
                    if (strs[i] == "hut" || strs[i]=="tit")
                        cout << strs[i] << " # " << hv << endl;
                    Pair cp {hv, (int)strs[i].size()};//warning: narrowing conversion of ‘(&(& strs)->std::vector<_Tp, _Alloc>::operator[]<std::basic_string<char>, std::allocator<std::basic_string<char> > >(((std::vector<std::basic_string<char> >::size_type)i)))->std::basic_string<_CharT, _Traits, _Alloc>::size<char, std::char_traits<char>, std::allocator<char> >()’ from ‘std::basic_string<char>::size_type {aka unsigned int}’ to ‘int’ inside { } [-Wnarrowing] 
                    MPI pos=h.find(cp);
                    if (pos != h.end()) {
                        if (h[cp]!=-1) {
                            res.push_back(strs[h[cp]]);
                            h[cp]=-1;
                        }
                        res.push_back(strs[i]);
                    } else {
                        h.emplace(cp, i);
                    }
                }
                return res;
            }
    };
};
void test4()
{
    vector<string> ins{"ron","huh","gay","tow","moe","tie","who","ion","rep","bob","gte","lee","jay","may","wyo","bay","woe","lip","tit","apt","doe","hot","dis","fop","low","bop","apt","dun","ben","paw","ere","bad","ill","fla","mop","tut","sol","peg","pop","les"};//"a", "bac", "ba", "c", "bb", "ca", "acb", "ac"};
    vector<string> outs=Solution::anagrams(ins);
    copy(outs.begin(), outs.end(), ostream_iterator<string>(cout, ","));
    cout << endl;
}
void test5()
{
    cout << Solution::strhash(string{""}) << " " << Solution::strhash(string{"huh"})<<endl;
}
int main()
{
    test4();
    int* t[10] {nullptr};
    cout << t[5] << endl;
    return 0;
}
