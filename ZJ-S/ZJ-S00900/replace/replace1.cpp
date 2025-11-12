/*
最暴力的做法是对于每一个询问（t1，t2）去枚举所有的n个（s1，s2）然后用kmp找一下在（t1，t2）中的哪里出现，然后要求前后相同，由于t1！=t2也就是说每一对（s1，s2）至多有一个合法的位置使得t1变成t2
然后kmp做这个寻找应该是拼一个 s1+t1，然后做一遍kmp，对于s2，t2也是这样
但是如果这样的话，那时间复杂度就是nT2+qT1了
然后就飞了

看特殊性质有一档q=1
发现我们可以对与这个做法进行优化，也就是发现我们找到的（s1，s2）一定满足存在（t1，t2）的不一样的部分，且与（t1，t2）相同，那既然这样，我们就去对于n个（s1，s2）看谁满足这个条件
然后发现假设（t1，t2）不同的部分长度为x，那么最多有(T1/x)对（s1，s2）是满足条件的，这样我们对于（s1，s2）的枚举总长就不会超过T1
对于这个部分，我们可以按照每对（s1，s2）两个字符串之间的差别数量进行排序，或者直接长度排序好像会更好

接着在这个基础上，我们发现会出问题的部分在于q没有限制的情况下，我们每次都要对（t1，t2）不同的部分进行n次扫描，这个部分很大，我们希望那个把这个部分省掉
所以我们可以魔改kmp，把拼接部分的前半截扫描省掉，反正我们永不上前半截的kmp数组
至此复杂度应该就是合法的了

然后就是因为字符串长度不固定，所以需要用string存字符串

不对，现在的复杂度好像仍然有一个qT1
但是q=1肯定是能过的，先写一下
*/
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=2e5+5,maxm=5e6+5;
const ull base=23333,Mod=1e9+9;
int n,q,Faill[maxm],Failr[maxm];
char S[maxm],S_[maxm];
struct node{
    int diff,len;
    string s,s_;
}a[maxn];
int rd(){
    int res=0,y=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
    while(isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
    return res*y;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=rd();q=rd();
    for(int i=1;i<=n;i++){
        scanf("%s %s",S+1,S_+1);
        a[i].len=strlen(S+1);
        a[i].s="";
        a[i].s_="";
        for(int j=1;j<=a[i].len;j++){
            a[i].s+=S[j];
            a[i].s_+=S_[j];
            a[i].diff+=(S[j]!=S_[j]);
        }
    }
    while(q--){
        scanf("%s %s",S+1,S_+1);int res=0;
        int nowlen=strlen(S+1),nowlen_=strlen(S_+1);
        if(nowlen!=nowlen_){puts("0");continue;}
        string nowl="|",nowr="|";
        for(int l=1;l<=nowlen;l++) nowl+=S[l],nowr+=S_[l];
        for(int _=1;_<=n;_++){
            int posa=nowl.find(a[_].s),posb=nowr.find(a[_].s_);
            if(posa==-1||posb==-1||posa!=posb||posa+a[_].len-1>nowlen) continue;
            // printf("%d %d\n",posa,posb);
            bool flg=1;
            for(int i=0;i<posa;i++) flg&=(nowl[i]==nowr[i]);
            for(int i=posa+a[_].len;i<=nowlen;i++) flg&=(nowl[i]==nowr[i]);
            res+=flg;
        }
        printf("%d\n",res);
    }
    return 0;
}