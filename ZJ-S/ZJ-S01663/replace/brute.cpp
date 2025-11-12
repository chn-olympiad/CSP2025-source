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
cint N=2e5,Q=2e5;
int n,q;
string s[N+1],t[N+1];
string qs,qt;
void query()
{
    cin>>qs>>qt;
    if(qs.size()!=qt.size()||qs==qt)
    {
        princh(0,'\n');
        return;
    }
    int ans=0;
    for(int p=0;p<qs.size();++p)
    {
        for(int i=1;i<=n;++i)
        {
            if(p+(int)s[i].size()>(int)qs.size())continue;
            // printf(">%d\n",i);
            for(int j=0;j<s[i].size();++j)
            {
                if(qs[p+j]!=s[i][j]||qt[p+j]!=t[i][j])goto nxt;
            }
            // printf(">%d\n",i);
            for(int j=p+s[i].size();j<qs.size();++j)if(qs[j]!=qt[j])goto nxt;
            ++ans;
            // printf(">%d\n",i);
            nxt:;
        }
        if(qs[p]!=qt[p])break;
    }
    princh(ans,'\n');
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("brute.out","w",stdout);
    n=read();
    q=read();
    for(int i=1;i<=n;++i)
    {
        cin>>s[i]>>t[i];
    }
    while(q--)query();
    return 0;
}