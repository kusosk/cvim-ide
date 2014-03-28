#include	<iostream>
#include	<vector>
#include	<cstring>
#include    <string>

using namespace std;

int data[] = {12, 21, 34, 43, 58, 85, 7, 64, 66};

void Display(int * v, size_t len)
{
    for (size_t pos = 0; pos < len; ++pos) {
        cout << v[pos] << " ";
    }
    cout << endl;
}

typedef vector<int> IntVec;
class Bucket {
    vector<int> ns;
    public:
    void Insert(int pn) { ns.push_back(pn);}
    size_t Size() const { return ns.size();}
    size_t PlaceToTarget(int *place)
    {
        for (IntVec::iterator pos = ns.begin(); pos!=ns.end(); ++pos) {
            *place++ = *pos;
        }
        return Size();
    }
    void Clear() {ns.clear();}
};

class RadixSorter {
    Bucket buckets[10];
    int max;
    void InsertBucket(int n, size_t pos_from_right)
    {
        int v_pow_10 = 1;
        while(--pos_from_right)
            v_pow_10 *= 10;
        buckets[n/v_pow_10%10].Insert(n);
    }

    void ClearData()
    {
        for (size_t i=0; i<10; ++i)
            buckets[i].Clear();
    }

    void PlaceData(int *v, size_t len)
    {
        size_t pos=0;
        for (size_t i=0; pos<len&&i<10; ++i) {
            buckets[i].PlaceToTarget(v+pos);
            pos += buckets[i].Size();
        }
    }
    public:
    RadixSorter():max(-1){}
    void operator ()(int* v, size_t len)
    {
        // checker here TODO
        for (size_t pos = 0; pos < len; ++pos) {
            max = v[pos]>max? v[pos] :max;
        }
        size_t pos_from_right = 1;
        while (max) {
            for (size_t pos = 0; pos < len; ++pos) {
                InsertBucket(v[pos], pos_from_right);
            }

            PlaceData(v, len);
            max /= 10;
            pos_from_right++;
            ClearData();
        }
        ClearData();
    }
};

class SuffixArray {
    int trank[100001];
    int sa[100001];
    int rank[100001];
    int sum[100001];
    RadixSorter sorter;
    public:
    friend void Display(int* v, size_t len);

void S(int len)
{
    int i = 0;
    cout << "*********************************" <<endl;
    cout << "idx";
    for (;i<=len; i++)
        cout << "\t" << i;
    cout << endl;

    cout << "trank";
    for (i=0;i<=len; i++)
        cout << "\t" << trank[i];
    cout << endl;

    cout << "sum";
    for (i=0;i<=25; i++)
        cout << "\t" << sum[i];
    cout << endl;

    cout << "sa";
    for (i=0;i<=len; i++)
        cout << "\t" << sa[i];
    cout << endl;

    cout << "rank";
    for (i=0;i<=len; i++)
        cout << "\t" << rank[i];
    cout << endl;
}
    void BuildSuffixArray(const char* str, size_t len)
    {
        memset(sa, 0, sizeof(int)*(len+1));
        memset(rank, 0, sizeof(int)*(len+1));
        memset(sum, 0, sizeof(int)*(len+1));
        memset(trank, 0, sizeof(int)*(len+1));

        for (size_t i = 0; i<len; i++) {
            trank[i+1]=str[i]>'Z'?str[i]-'a':(str[i]|('a'^'b'))-'a';
        }
        S(len);
        for (size_t i = 1; i<=len; i++) {
            sum[ trank[i] ]++;
        }
        for (size_t i = 1; i<=len; i++) {
            sum[i] += sum[i-1];
        }
        S(len);
        for (size_t i = len; i>0; i--)
            sa[ sum[ trank[i] ]-- ] = i;
        S(len);
        rank [ sa[1] ] = 1;
        for (size_t i=2,p=1; i<=len; i++)
        {
            if (trank[ sa[i] ]!=trank[ sa[i-1] ]) p++;
            rank[ sa[i] ]=p;
        }
        cout << "for round 0" << " " ;
        ::Display(rank, len+1);
        for (size_t range = 1; range <= len; range*=2) {
            sum[0] = 0;
            for (size_t i = 1; i <= len; i++)
                sum[i] = i+range<=len ? rank[i]*10+rank[i+range] : rank[i]*10;
            sorter(sum, len+1); 
            for (size_t i = 1; i <= len; i++)
                rank[ sum[i]/10 ] = sum[i]/10;
            cout << "for round " << range << " " ;
            ::Display(rank, len+1);
        }
    }
};

void TestRadixSorter()
{
    RadixSorter sorter;
    sorter(data, 9);
    Display(data, 9);

    Bucket b;
    b.Insert(101);
    b.Insert(121);
    b.Insert(1);
    int v[]= {101, 21, 1000032, 15, 70, 10000, 4};
    sorter(v, 7);
    Display(v, 7);
}

int main()
{
    SuffixArray sa;
    sa.BuildSuffixArray("abcdab", 6);
    return 0;
}
