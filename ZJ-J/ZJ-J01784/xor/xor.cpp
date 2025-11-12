#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e5+10;
int a[maxn];
int b[maxn];
int sum[maxn];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        b[i]=1;
        sum[i]=sum[i-1]^a[i];
    }
    int ans=0;
    int l,r,g=0;
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=n-j+1;++i)
        {
            l=i;
            r=i+j-1;
            for(int p=l;p<=r;++p)
            {
                if(b[p]==0)
                {
                    g=1;
                    break;
                }
            }
            if(g==1)
            {
                g=0;
                continue;
            }
            if(sum[r]^sum[l-1]==k)
            {
                ++ans;
                printf("%lld ",l);
                for(int w=l;w<=r;++w)
                {
                    b[w]=0;
                }
            }
            i=r;
        }
    }
    printf("%lld",ans);
    return 0;
}