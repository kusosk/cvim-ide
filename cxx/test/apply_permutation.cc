#include	<iostream>
#include	<climits>
#include    <string>
#include    <exception>
#include    <stdexcept>
#include    <algorithm>
#include    <vector>
#include    <iterator>
#include    <cassert>
#include    <unordered_map>

using namespace std;
void a_p(vector<int> &p, vector<int> &A)
{
    for (int i = 0; i<A.size(); ++i) {
        if (p[i] >=0) {
            int a = i;
            int temp = A[i];
            do {
                int next_a = p[a];
                int next_temp = A[next_a];
                A[next_a]=temp;

                p[a] -= p.size();
                a=next_a, temp = next_temp;
            } while(a != i);
        }
    }

    size_t s = p.size();
    for_each(p.begin(), p.end(), [s](int &x) {x+=s;});
}

void s1(vector<int>& p, vector<int>& A) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] > 0) {
            int j = i;
            while (j>=0 && p[j] != i) {
                swap(A[j], A[p[j]]);
                int t = j;
                j = p[j];
                p[t] -= p.size(); 
            }
        }
    }
}

void s2(vector<int>& p, vector<int>& A) {
    unordered_map<int, int> pos;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] != i) {
            if (p[i] >= 0) {
                swap(A[i], A[p[i]]);
                pos.emplace(i, p[i]);
                p[i] = -p[i];
            } else {
                swap(A[i], A[pos[i]]);
            }
        } 
    }
}

void s3(vector<int>& p, vector<int>& A) {
    vector<int> res;
    for (int i = 0; i < p.size(); ++i) {
        res.push_back(A[p[i]]);
    }
    for (int i = 0; i < p.size(); ++i) {
        A[i] = res[i];
    }
}
void s4_(vector<int>& p, vector<int>& A) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] > 0) {
            int j = i;
            cout << "@ " << i << " " << p[i] << endl;
            while(p[j] != i) {
                if (p[p[j]] < 0) break;
                swap(A[j], A[p[j]]);
                int oj = j;
                j = p[j];
                p[oj] = -p[oj];
    copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
            }
            cout << "*" << i+1 <<"\n";
    copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
    cout << "\n###########"<< endl;
        }
    }
    for (int i = 0; i < p.size(); ++i) {
        p[i] = p[i]<0?-p[i]:p[i];
    }
}

template<typename T>
void s5(vector<int>& p, vector<T>& A) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] > 0) {
            int j = i;
            while(p[j] != i) {
                if (p[p[j]] < 0) break;
                swap(A[j], A[p[j]]);
                int oj = j;
                j = p[j];
                p[oj] = -p[oj];
            }
        }
    }
    for (int i = 0; i < p.size(); ++i) {
        p[i] = p[i]<0?-p[i]:p[i];
    }
}

void s4(vector<int>& p, vector<int>& A) {
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] > 0) {
            int j = i;
            while(p[j] != i) {
                if (p[p[j]] < 0) break;
                swap(A[j], A[p[j]]);
                int oj = j;
                j = p[j];
                p[oj] = -p[oj];
            }
        }
    }
    for (int i = 0; i < p.size(); ++i) {
        p[i] = p[i]<0?-p[i]:p[i];
    }
}

void assert_equal(vector<int>& v1, vector<int>& v2)
{
    for (int i = 0; i<v1.size(); ++i) {
        assert(v1[i] == v2[i]);
    }
}

void assert_equal_char(vector<int>& v1, vector<char>& v2)
{
    for (int i = 0; i<v1.size(); ++i) {
        assert(v1[i] == (v2[i]-'A'));
    }
}
void test_s5()
{
    vector<char> A1;
    vector<int> p;
    int cnt = 0;
    int v=-26;
    for (int i = 26; i < 27; ++i) {
        A1.resize(i);
        p.resize(i);
        iota(A1.begin(), A1.end(), 0x41);
        iota(p.begin(), p.end(), 0);
        for (int j=0; j<1; ++j) {
            random_shuffle(p.begin(), p.end());
            s5(p, A1);
            cnt++;
#ifdef DEBUG
    copy(A1.begin(), A1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
            assert_equal_char(p, A1);
            iota(A1.begin(), A1.end(), 0);
        }
    }
    cout << cnt << " cases passed"<<endl;
    
}
void test_s4()
{
    vector<int> A1;
    vector<int> p;
/*
    p.resize(10);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i<10; ++i) {
        random_shuffle(p.begin(), p.end());
        copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
        cout << "\n###########"<< endl;
    iota(p.begin(), p.end(), 0);
    }
    return 0;
*/
    int cnt = 0;
    for (int i = 10; i < 1000; ++i) {
        A1.resize(i);
        p.resize(i);
        iota(A1.begin(), A1.end(), 0);
#ifdef DEBUG
    copy(A1.begin(), A1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
        iota(p.begin(), p.end(), 0);
        for (int j=0; j<100; ++j) {
            random_shuffle(p.begin(), p.end());
#ifdef DEBUG
    copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
    cout << "\n###########"<< endl;
#endif
    //a_p(p, A);
//    copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
//    cout << endl<< endl<< endl;
            s4(p, A1);
            cnt++;
#ifdef DEBUG
    copy(A1.begin(), A1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
            assert_equal(p, A1);
            iota(A1.begin(), A1.end(), 0);
        }
    }
    cout << cnt << " cases passed"<<endl;
}
int main()
{
    test_s5();
    return 0;
}
