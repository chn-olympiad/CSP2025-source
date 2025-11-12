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
cint N=1e4;
int MAXN,MAXM,MAXK,V;
int n,m,k;
int p[N+1];
void spc()
{
    for(int i=0;i<=n;++i)princh(ran(0,V),' ');
    putchar('\n');
}
int main()
{
    freopen("nmkv.txt","r",stdin);
    freopen("road.in","w",stdout);
    MAXN=read();
    MAXM=read();
    MAXK=read();
    V=read();
    n=ran(1,MAXN);
    m=ran(n-1,MAXM);
    k=ran(0,MAXK);
    princh(n,' ');
    princh(m,' ');
    princh(k,'\n');
    for(int i=1;i<=n;++i)
    {
        p[i]=i;
        swap(p[i],p[ran(1,i)]);
    }
    for(int i=2;i<=n;++i)
    {
        princh(p[i],' ');
        princh(p[ran(1,i-1)],' ');
        princh(ran(0,V),'\n');
    }
    for(int i=n;i<=m;++i)
    {
        princh(ran(1,n),' ');
        princh(ran(1,n),' ');
        princh(ran(0,V),'\n');
    }
    for(int i=1;i<=k;++i)spc();
    return 0;
}