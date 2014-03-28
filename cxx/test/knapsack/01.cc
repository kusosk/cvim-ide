#include<cstdio>
using namespace std;
#define MAXN 1000
#define MAXC 100000

int V[MAXN], W[MAXN];
int d[MAXN][MAXC];

int main(){
    freopen("data.in", "r", stdin);//重定向输入流
    freopen("data.out", "w", stdout);//重定向输出流
    int n, C;
    while(scanf("%d %d", &n, &C) != EOF){
        for(int i=0; i<n; ++i)   scanf("%d %d", &V[i], &W[i]);

        for(int i=0; i<=n; ++i){
            for(int j=0; j<=C; ++j){
                d[i][j] = i==0 ? 0 : d[i-1][j];
                if(i>0 && j>=V[i-1]) 
                    d[i][j] = d[i-1][j] < d[i-1][j-V[i-1]]+W[i-1] ?\
                              d[i-1][j-V[i-1]]+W[i-1] : d[i-1][j];
            }
        }
        printf("%d\n", d[n][C]);//最终求解的最大价值
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
