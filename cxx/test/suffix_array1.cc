#include	<iostream>
#include	<cstdio>
#include    <string>
#include    <cstring>
#include    <exception>
#include    <stdexcept>

using namespace std;

char buff[10001];
int sum[10001];
int trank[10001];
int rank[10001];
int tsa[10001];
int sa[10001];
string s;
int maxlen;

static int level = 2;

void S(int l);

void sorting(int j)//对步长j的各个位置进行基数排序
{
    // sum 数组归零
    memset(sum,0,sizeof(sum));
    for (int i=1; i<=s.size(); i++) 
        if (i+j<=s.size()) sum[ rank[i+j] ]++;
    S(2);
    for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
    S(2);
    for (int i=s.size(); i>0; i--)
        if (i+j<=s.size()) 
            tsa[ sum[ rank[i+j] ]-- ]=i;
    S(2);
    //对第二关键字计数排序，tsa代替sa为排名为i的后缀是tsa[i] 

    memset(sum,0,sizeof(sum));
    for (int i=1; i<=s.size(); i++) sum[ rank[i] ]++;
    S(2);
    for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
    S(2);
    for (int i=s.size(); i>0; i--)
        sa[ sum[ rank[ tsa[i] ] ]-- ]= tsa[i]; 
    S(2);
    //对第一关键字计数排序,构造互逆关系 
    cout << "round " << j << " soring ends" << endl;
}

void S(int l)
{
    if (l<level)
        return ;
    int i = 0;
    cout << "*********************************" <<endl;
    cout << "idx";
    for (;i<s.size(); i++)
        cout << "\t" << i;
    cout << endl;

    cout << "s";
    for (i=0;i<s.size(); i++)
        cout << "\t" << s[i];
    cout << endl;

    cout << "trank";
    for (i=0;i<=s.size(); i++)
        cout << "\t" << trank[i];
    cout << endl;

    cout << "sum";
    for (i=0;i<=25; i++)
        cout << "\t" << sum[i];
    cout << endl;

    cout << "sa";
    for (i=0;i<=s.size(); i++)
        cout << "\t" << sa[i];
    cout << endl;

    cout << "tsa";
    for (i=0;i<=s.size(); i++)
        cout << "\t" << tsa[i];
    cout << endl;


    cout << "rank";
    for (i=0;i<=s.size(); i++)
        cout << "\t" << rank[i];
    cout << endl;
}
void get_sa()
{
    memset(trank, 0, sizeof(int)*(s.size()+1));
    memset(sum, 0, sizeof(int)*(s.size()+1));
    memset(sa, 0, sizeof(int)*(s.size()+1));
    memset(rank, 0, sizeof(int)*(s.size()+1));
    /*
       idx	0	1	2	3	4	5	6
       s	a	b	c	d	a	
       */
    int p;
    // trank 记录增广字串(从下标1开始)中的字符相对于'a'的差值('b'为1,所有大写转换为小写)
    for (int i=0; i<s.size(); i++) trank[i+1]=s[i]>'Z'?s[i]-'a':( (s[i]|('a'^'A')) - 'a');
    S(1);
    /*
       idx	0	1	2	3	4	5	6
       s	a	b	c	d	a	b	
       trank	NA	a	b	c	d	a	b
       NA	0	1	2	3	0	1
       */
    // 扫描增广下标数组trank,根据trank中字符下标统计其对应得每个字符('a'-'z')的出现次数
    for (int i=1; i<=s.size(); i++) sum[ trank[i] ]++;
    S(1);
    /*
       idx	0	1	2	3	4	5	6
       s	a	b	c	d	a	b	
       trank	NA	a	b	c	d	a	b
       NA	0	1	2	3	0	1
       sum		2	2	1	1 (对应a , b , c, d出现次数)
       */
    // 累加,统计首字符不大于'a'+i(如i=2,则为'c')开始的后缀串数量
    for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
    S(1);
    /*
       idx	0	1	2	3	4	5	6
       s	a	b	c	d	a	b	
       trank	NA	a	b	c	d	a	b
       NA	0	1	2	3	0	1
       sum		2	4	5	6 
       */
    // 反向扫瞄trank数组,通过当前字符C('a'+trank[i]),查找首字符不比当前字符C大的后缀串的数量,将该数量作为下标(0开始,故减一),
    // 		使用sa数组记录该字符出现的第一个位置(最左,且从1开始计数)
    // sa[i] 记录了第i小的后缀串开始的下标位置(从1开始)
    // 此时sa维护了所有出现过的字符为首字符的字串的第几小排序到其开始位置下标(从1开始)的对应,
    //		但是如果该首字符出现多次,每计算一次,需要sum[trank[i]]减去1(去除当前后缀的计数)
    for (int i=s.size(); i>0; i--) 
        sa[ sum[ trank[i] ]-- ]=i;
    /*
       idx	0	1	2	3	4	5	6
       s	a	b	c	d	a	b	
     trank	$	a	b	c	d	a	b
       NA	0	1	2	3	0	1
       sum		2	4	5	6 (对应a , b , c, d)
       sa	0	1	5	2	6	3	4 
       rank	0	0	0	0	0	0	0
       sa[1] = 1 =>最小的后缀串为从下标1(即原串中下标0)开始的子串 abcdab$(正确的值应该为5,后面会修正回来)
       对于后缀ab$,由于它首字符一样,故此时未计算其sa值
       */
    //  rank[ sa[i] ]=i;
    S(1);

    rank[ sa[1] ]=1;
    for (int i=2,p=1; i<=s.size(); i++)
    {
        //第i小的后缀首字符不等于第i-1小的后缀首字符(如果sa[i]为0,则trank[0]为$,则一定不等于),计数加1
        if (trank[ sa[i] ]!=trank[ sa[i-1] ]) p++;
        // 如果sa[i]已经计算过(其值非0),则第i小后缀的rank为当前计数;
        // 否则,暂时记录不计算第i小后缀的rank,(始终设rank[0]=p)
        rank[ sa[i] ]=p;
    }//第一次的sa与rank构造完成
    S(1);
    /*
       idx	0	1	2	3	4	5	6
       s	a	b	c	d	a	b	
       trank	NA	a	b	c	d	a	b
       NA	0	1	2	3	0	1
       sum		2	4	5	6 (对应a , b , c, d)
       sa	0	1	5	2	6	3	4	
       rank	0	0	0	0	0	0	0
       i=1
       rank[sa[1]=1;
       rank	0	1	0	0	0	0	0
       i=2		trank[ sa[i] ]==trank[ sa[i-1] ]	都为a -> p=1
       rank[sa[2]] = rank[5]=1
       i=3		p=2	rank[sa[3]] = rank[2]=2
       i=4		trank[ sa[i] ]==trank[ sa[i-1] ]	都为b -> p=2
       rank[sa[4]] = rank[6]=2
       i=5		p=3	rank[sa[5]] = rank[3]=3
       i=6		p=4	rank[sa[6]] = rank[4]=4
       rank	0	1	2	3	4	1	2

       ab$
       abcddab$
       b$
       bcdab$
       cdab$
       dab$
       */
    for (int j=1; j<=s.size(); j*=2)
    {
        sorting(j);
        trank[ sa[1] ]=1; 
        p=1; //用trank代替rank 
        for (int i=2; i<=s.size(); i++)
        {
            if ((rank[ sa[i] ]!=rank[ sa[i-1] ]) || (rank[ sa[i]+j ]!=rank[ sa[i-1]+j ])) p++;
            trank[ sa[i] ]=p;//空间要开大一点，至少2倍
        }
        for (int i=1; i<=s.size(); i++) rank[i]=trank[i];
    }
}

void sort_ranks(int range)
{
    for (int i=1; i <=s.size(); ++i) 
        tsa[i] = i+range <= s.size() ? rank[i]*10+rank[i+range] :rank[i]*10;
}

void calc_suffix_array()
{
    memset(trank, 0, sizeof(int)*(s.size()+1));
    memset(sum, 0, sizeof(int)*(s.size()+1));
    memset(tsa, 0, sizeof(int)*(s.size()+1));
    memset(sa, 0, sizeof(int)*(s.size()+1));
    memset(rank, 0, sizeof(int)*(s.size()+1));

    for (int i=0; i<s.size(); i++) trank[i+1]=s[i];
    for (int i=1; i<=s.size(); i++) sum[ trank[i] ]++;
    for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
    for (int i=s.size(); i>0; i--) 
        sa[ sum[ trank[i] ]-- ]=i;
    rank[ sa[1] ]=1;
    for (int i=2,p=1; i<=s.size(); i++)
    {
        if (trank[ sa[i] ]!=trank[ sa[i-1] ]) p++;
        rank[ sa[i] ]=p;
    }//第一次的sa与rank构造完成

    for (int i = 1; i<s.size(); i*=2)
    {
        sort_ranks();
    }

}

int main()
{
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, " "))
            break;
        s=buff;
        maxlen = s.size()+1;
        get_sa();
    }
    return 0;
}
