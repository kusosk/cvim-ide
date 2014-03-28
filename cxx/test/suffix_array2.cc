#include <cstdio> 
#include <cstring> 
#include <algorithm> 
#include <iostream> 

using namespace std; 

#define MAXN 65536 
#define MAXLG 17 

char str[MAXN]; 
struct entry { int nr[2], pos; 
} ranks[MAXN]; 

int SA[2][MAXN], N, i, round, step; 

int cmp(struct entry a, struct entry b) 
{ 
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0); 
} 

void display()
{
    for(int i = 0; i<N; ++i)
    {
        cout << SA[(round-1)%2][i] << " ";
    }
    cout << endl;
}
void buildSA(const char* str)
{
    for (N = strlen(str), i = 0; i < N; i ++) 
        SA[0][i] = str[i] - 'a'; 

    for (round = 1, step = 1; step >> 1 < N; round ++, step <<= 1) { 
        for (i = 0; i < N; i ++) {
            ranks[i].nr[0] = SA[(round - 1)%2][i]; 
            ranks[i].nr[1] = i + step < N ? SA[(round - 1)%2][i + step] : -1; 
            ranks[i].pos = i; 
        } 
        sort(ranks, ranks + N, cmp); 
        for (i = 0; i < N; i ++) 
            SA[round%2][ranks[i].pos] = 
                i > 0 && 
                ranks[i].nr[0] == ranks[i - 1].nr[0] && 
                ranks[i].nr[1] == ranks[i - 1].nr[1] ? 
                    SA[round%2][ranks[i - 1].pos] : i; 
        cout << "round " << round << " ";
        for(int i = 0; i<N; ++i)
        {
            cout << SA[round%2][i] << " ";
        }
        cout << endl;
    } 
}
int main(void) 
{ 
    gets(str); 
    buildSA(str);
    display();
    return 0;
}
