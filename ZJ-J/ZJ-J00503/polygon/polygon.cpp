#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e3+10;
constexpr int MOD=998244353;
void exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
int ny(int a)
{
    int x,y;
    exgcd(a,MOD,x,y);
    return ((x%MOD)+MOD)%MOD;
}
int jc[maxn];
int jcny[maxn];
void init(int n)
{
    int now=1;
    for(int i=1;i<=n;++i)
    {
        now=now*i%MOD;
        jc[i]=now;
        jcny[i]=ny(now);
    }
}

int C(int n,int m)
{
    return jc[n]*jcny[m]%MOD*jcny[n-m];
}

int solvea1(int n)
{
    int res=0;
    for(int i=3;i<=n;++i)
    {
        res=(res+C(n,i))%MOD;
    }
    return res;
}

int a[maxn];
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%lld",&n);
    init(n);
    bool a1=true;
    for(int i=0;i<n;++i)
    {
        scanf("%lld",&a[i]);
        if(a[i]>1)
        {
            a1=false;
        }
    }
    if(a1)
    {
        printf("%lld\n",(solvea1(n)+1)%MOD);
        return 0;
    }
    if(n<=20)
    {
        int res=0;
        for(int i=0;i<1<<n;++i)
        {
            int maxnum=0;
            int sum=0;
            int cnt=0;
            for(int j=0;j<n;++j)
            {
                if((i>>j)&1)
                {
                    ++cnt;
                    maxnum=max(maxnum,a[j]);
                    sum+=a[j];
                }
            }
            if(cnt<3) continue;
            if(sum<=maxnum<<1) continue;
            ++res;
        }
        printf("%lld\n",res%MOD);
        return 0;
    }
    return 0;
}