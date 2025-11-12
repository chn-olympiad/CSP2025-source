#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 5e5+10;
constexpr int maxm = 1e7+10;

typedef struct line
{
    int l,r;
    bool operator<(const line& o)const
    {
        return r<o.r;
    }
}line;

/// n^2
int sum[maxn];
line lin[maxm];
int n,k,idx;

signed main()
{
    freopen("xor.in","r",stdin);
    freopen("pai.out","w",stdout);

    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",sum+i);
        sum[i]^=sum[i-1];
    }
    for(int len=1;len<=n;++len)
    {
        for(int i=1,j=i+len-1; j<=n ;++i,++j)
        {
            if((sum[j]^sum[i-1])==k)
            {
                lin[++idx].l=i;
                lin[idx].r=j;
            }
        }
    }

    sort(lin+1,lin+1+idx);
    int ans=0;
    int rr=0;
    for(int i=1;i<=idx;++i)
    {
        if(lin[i].l>rr)
        {
            ++ans;
            rr=lin[i].r;
        }
    }
    printf("%lld\n",ans);

    return 0;
}
