#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e3+10;
constexpr int mod=998244353;
int a[maxn],b[maxn],f[maxn];
int n;
int cnt=0;
int power(int m)
{
    int p=1;
    while(m--)
    {
        p=p*2;
    }
    return p%mod;
}
void find_edge(int t,int r)
{
    for(int i=t+1;i<=n;++i)
    {
        if(b[i]>r)
        {
            cnt+=power(n-i);
        }
        else
        {
            find_edge(i,r-b[i]);
        }
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);


    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        int maxm=-1;
        int q=0;
        for(int j=1;j<=n;++j)
        {
            if(f[j]==0&&a[j]>maxm)
            {
                maxm=a[j];
                q=j;
            }
        }
        b[i]=maxm;
        f[q]=1;
    }
    for(int i=1;i<=n-2;++i)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;++k)
            {
                if(b[j]+b[k]>b[i])
                {
                    cnt+=power(n-k);
                }
                else
                {
                    find_edge(k,i-j-k);
                }
            }
        }
    }
    printf("%lld\n",cnt%mod);
    return 0;
}
