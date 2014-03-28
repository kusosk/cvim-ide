
#include <stdio.h>  
#include <iostream>
using namespace std;

char s[200002];  
char str[400010];  
int p[400010];  

int min(int a,int b){  
    return a < b ? a : b;  
}  

int pre(){  
    int i,j = 0;  
    str[j++] = '$';//加入字符串首部的字符串  
    for(i = 0;s[i];i++){  
        str[j++] = '#';  //分隔符
        str[j++] = s[i];  
    }  
    str[j++] = '#';  
    str[j] = '\0';  //尾部加'\0'
    cout<<str<<endl;
    return j;  
}  

void manacher(int n){  
    int mx = 0,id,i;  
    p[0] = 0;  
    for(i = 1;i < n;i++){  
        if(mx > i)  //在这个之类可以借助前面算的一部分
            p[i] = min(mx - i,p[2 * id - i]); //p[2*id-i]表示j处的回文长度 
        else  //如果i大于mx，则必须重新自己算
            p[i] = 1;  
        while(str[i - p[i]] == str[i + p[i]])  //算出回文字符串的半径
            p[i]++;  
        if(p[i] + i > mx){  //记录目前回文字符串扩展最长的id
            mx = p[i] + i;  
            id = i;  
        }  
    }  
}  


int main(int argc, char const *argv[]){  

    while(scanf("%s",s) != EOF){  
        int n = pre();  
        manacher(n);  
        int ans = 0,i,idx;  
        for(i = 1;i < n;i++)  
            if(p[i] > ans) {  
                ans = p[i]; 
                idx = i;
            }
        printf("%d\n",ans - 1); 
        string res(s);
        cout << res.substr((idx-p[idx])/2, p[idx]-1)<<endl; 
    }  
    return 0;  
}


