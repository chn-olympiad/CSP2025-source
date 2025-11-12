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
cint N=500;
cint mod=998244353;
int n,m;
bool a[N+1];
int c[N+1];
void input()
{
    char ch=getchar();
    while(ch!='0'&&ch!='1')ch=getchar();
    for(int i=1;i<=n;++i)
    {
        a[i]=ch-'0';
        ch=getchar();
    }
}
int ans;
bool check()
{
    int now=0;
    for(int i=1;i<=n;++i)
    {
        if(!a[i]||i-now-1>=c[i])continue;
        ++now;
    }
    return (now>=m);
}
void dfs(cint p)
{
    if(p>n)
    {
        (ans+=check())>=mod?(ans-=mod):0;
        return;
    }
    for(int i=1;i<=p;++i)
    {
        swap(c[i],c[p]);
        dfs(p+1);
        swap(c[i],c[p]);
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("brute.out","w",stdout);
    n=read();
    m=read();
    input();
    for(int i=1;i<=n;++i)
    {
        c[i]=read();
    }
    dfs(1);
    print(ans);
    return 0;
}