#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=506+27;
constexpr int maxm=506+13;
constexpr int mod=998244353;
constexpr int inf=(LLONG_MAX>>1)-1;

int n,m;
char s[maxn];
int c[maxn];
int could;
void sub1()
{
    int ans=0;
    string b="";
    for(int i=1;i<=n;++i)
    {
        b+=(char)(i+'0');
    }
    do
    {
        int out=0;
        int yes=0;
        for(int i=1;i<=n;++i)
        {
            int now=b[i-1]-'0';
            if(out>=c[now])
            {
                ++out;
            }
            else
            {
                if(s[i]=='1')
                {
                    ++yes;
                }
                else
                {
                    ++out;
                }
            }
        }
        ans+=(yes>=m);
    }
    while(next_permutation(b.begin(),b.end()));
    printf("%lld\n",ans%mod);
}
void subA()
{
    int ans=1;
    for(int i=1;i<=n;++i)
    {
        ans=ans*i%mod;
    }
    printf("%lld\n",ans);
}
int qpow(int a,int b,int p)
{
    int res=1;
    a%=p;
    while(b)
    {
        if(b&1)
        {
            res=res*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
}
void sub3()
{
    int ans=0;
    sort(c+1,c+n+1);
    for(int i=1;i<=n;++i)
    {
        if(c[i]<i)
        {
            printf("0\n");
            return ;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(c[i]>=i)
        {
            ans=ans*i%mod;
        }
        else
        {
            ans=ans*qpow(i,mod-2,mod)%mod;
        }
    }
    printf("%lld\n",ans);
}
void sub2()//1
{
    int ans=1;
    for(int i=1;i<=n;++i)
    {
        ans=ans*i%mod;
    }
    printf("%lld\n",ans);
}
void sub5()
{
    int ans=1;
    int tot=0;
    sort(c+1,c+n+1);
    for(int i=1;i<=n;++i)
    {
        if(c[i]>=i)
        {
            ++tot;
            ans=ans*i%mod;
        }
    }
    if(tot<m)
    {
        ans=0;
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        could+=s[i]-'0';
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&c[i]);
    }
    if(could<m)
    {
        printf("0\n");
    }
    else if(n<=10)
    {
        sub1();
    }
    else if(m==n)
    {
        sub3();
    }
    else if(could==n)
    {
        subA();
    }
    else if(m==1)
    {
        sub2();
    }
    else
    {
        sub5();
    }

    return 0;
}

