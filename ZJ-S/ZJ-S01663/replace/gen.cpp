#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull const unsigned long long
#define cull const unsigned long long
using namespace std;
ll read()
{
    ll x=0;
    bool zf=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')zf=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch-'0');
        ch=getchar();
    }
    return x;
}
void print(cll x)
{
    if(x<0)
    {
        putchar('-');
        print(-x);
        return;
    }
    if(x<10)
    {
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
void princh(cll x,const char ch)
{
    print(x);
    putchar(ch);
}
mt19937 mt(chrono::system_clock().now().time_since_epoch().count());
inline int ran(cint l,cint r)
{
    return l+mt()%(r-l+1);
}
int MAXN,MAXQ,L,C,P;
void str(cint len,const char ch)
{
    for(int i=1;i<=len;++i)putchar(ran('a','a'+C-1));
    putchar(ch);
}
int n,q;
int main()
{
    freopen("nqlcp.txt","r",stdin);
    freopen("replace.in","w",stdout);
    MAXN=read();
    MAXQ=read();
    L=read();
    C=read();
    P=read();
    n=ran(1,MAXN);
    q=ran(1,MAXQ);
    princh(n,' ');
    princh(q,'\n');
    for(int i=1;i<=n;++i)
    {
        cint len=ran(1,L);
        str(len,' ');
        str(len,'\n');
    }
    for(int i=1;i<=q;++i)
    {
        int len1=ran(1,L),len2=ran(1,L);
        if(ran(1,100)<=P)len2=len1;
        str(len1,' ');
        str(len2,'\n');
    }
    return 0;
}