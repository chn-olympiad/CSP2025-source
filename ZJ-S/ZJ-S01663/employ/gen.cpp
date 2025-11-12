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
int MAXN;
int n;
int main()
{
    freopen("n.txt","r",stdin);
    freopen("employ.in","w",stdout);
    MAXN=read();
    n=ran(1,MAXN);
    princh(n,' ');
    princh(ran(1,n),'\n');
    for(int i=1;i<=n;++i)putchar(ran('0','1'));
    putchar('\n');
    for(int i=1;i<=n;++i)
    {
        princh(ran(0,n),' ');
    }
    return 0;
}