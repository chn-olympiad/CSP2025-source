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
int MAXT,MAXN,V;
int n;
void solve()
{
    n=(ran(1,MAXN>>1)<<1);
    princh(n,'\n');
    for(int i=1;i<=n;++i)
    {
        princh(ran(0,V),' ');
        princh(ran(0,V),' ');
        princh(ran(0,V),'\n');
    }
}
int main()
{
    freopen("tnv.txt","r",stdin);
    freopen("club.in","w",stdout);
    MAXT=read();
    MAXN=read();
    V=read();
    int T=ran(1,MAXT);
    princh(T,'\n');
    while(T--)solve();
    return 0;
}