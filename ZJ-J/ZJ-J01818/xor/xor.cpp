#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+13;
constexpr int inf=(LONG_LONG_MAX>>1)-1;

int n,k;
int a[maxn];
int xor_sum[maxn];
int max_a;
int ans;
int last;
void sub1()
{
    for(int i=1; i<=n; ++i)
    {
        scanf("%lld",&a[i]);
        xor_sum[i]=(xor_sum[i-1]^a[i]);
        if(a[i]==k)
        {
            xor_sum[i]=0;
            ++ans;
            int now=last;
            int to=inf;
            //printf("%lld %lld\n",i,ans);
            mmm:;
            for(int start=now+1; start<=min(i-1,to); ++start)
            {
                for(int j=start+1; j<=min(i-1,to); ++j)
                {
                    if((xor_sum[j]^xor_sum[start-1])==k)
                    {
                        to=min(to,j);
                        break;
                    }
                }
            }
            if(to!=inf)
            {
                ++ans;
                now=to;
                to=inf;
                goto mmm;
            }
            last=i;
        }
        //printf("%lld ",xor_sum[i]);
    }
    //printf("%lld\n",ans);
    int i=n+1;
    xor_sum[i]=0;
    ++ans;
    int now=last;
    int to=inf;
    ggg:;
    to=inf;
    for(int start=now+1; start<=min(i-1,to); ++start)
    {
        for(int j=start+1; j<=min(i-1,to); ++j)
        {
            //printf("%lld %lld %lld %lld %lld\n",start,j,xor_sum[j]^xor_sum[start-1],xor_sum[start-1],xor_sum[j]);
            if((xor_sum[j]^xor_sum[start-1])==k)
            {
                to=min(to,j);
                break;
            }
        }
    }
    if(to!=inf)
    {
        ++ans;
        xor_sum[to]=0;
        now=to;
        goto ggg;
    }
    last=i;
    printf("%lld\n",ans-1);
}
void sub2()
{
    if(k==1)
    {
        for(int i=1;i<=n;++i)
        {
            if(a[i]==1)
            {
                ++ans;
            }
        }
        printf("%lld\n",ans);
    }
    else if(k==0)
    {
        int last=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]==0)
            {
                ++ans;
                ans+=(i-last-1)/2;
                last=i;
            }
        }
        printf("%lld\n",ans);
    }
}
int dp[maxn][2];
int LAST[(1LL<<21)];
void sub3()
{
    LAST[0]=n+1;
    for(int i=1;i<=n;++i)
    {
        xor_sum[i]=(xor_sum[i-1]^a[i]);
        dp[i][1]=ans;
        if(LAST[xor_sum[i]^k])
        {
            dp[i][0]=dp[LAST[xor_sum[i]^k]][1]+1;
            if((xor_sum[i]^k)==0)
            {
                dp[i][1]=dp[i][0];
            }
        }
        //printf("%lld %lld %lld\n",xor_sum[i],dp[i][1],dp[i][0]);
        ans=max(ans,dp[i][0]);
        LAST[xor_sum[i]]=i;
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%lld%lld",&n,&k);
    if(n<=1e4)
    {
        sub1();
    }
    else
    {
        bool o=1;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            if(a[i]>1)
            {
                o=0;
            }
        }
        if(o==1&&k<=1)
        {
            sub2();
        }
        else
        {
            sub3();
        }
    }



    return 0;
}

