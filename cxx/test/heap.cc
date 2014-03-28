#include	<iostream>
#include    <string>
#include    <vector>
#include    <algorithm>

using namespace std;

const int MAX=1000;
int heap[MAX];

void buildHeap(int *v, int len, int& last_pos)
{
    int idx = 0;
    for (int i=0;i<len;++i) {
        idx = last_pos;
        heap[last_pos++] = v[i];
        while(idx>0) {
            if (heap[idx]<heap[(idx-1)/2])
                std::swap(heap[idx], heap[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }
}

void display(int l)
{
    for (int i=0; i<l; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main()
{
    int v[10] = {10,7,1,16,8,90,2,9};
    int last_pos =0;
//    for (int i =1; i<=4; i++)
//    {
//        buildHeap(v, i, last_pos);
//        display(last_pos);
//    }
    buildHeap(v, 6, last_pos);
    display(last_pos);
    vector<int> v1(10, 1);
    vector< vector< int > > v2;
    v2.push_back(v1);
    v2.push_back(v1);
    cout << v2[1][9] << endl;
/*
    v1[0] = 1;
    v1[2] = 2;
    v2[0][0] = 3;
    v2[0][1] = 3;
    v2[0][2] = 3;
    v2[1][0] = 3;
    v2[1][1] = 3;
    v2[1][2] = 3;

    cout << v2[1][1] << endl;
  */
    return 0;
}
