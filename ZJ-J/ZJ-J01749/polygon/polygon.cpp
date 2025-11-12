#include <bits/stdc++.h>
using namespace std;
#define int long long
#define itn long long

constexpr int maxn = 5e3+10;
constexpr int mod = 998244353;
int a[maxn];
int sum[maxn];
int tmp[maxn];
int tmpsum;
int ans;
int n;
void solve(int r,int len)
{
    int cnt = 0;
    while(1)
    {
        if(cnt<len)
        {
            ++cnt;
            tmp[cnt] = tmp[cnt-1]+1;
            tmpsum+=a[tmp[cnt]];
        }
        else
        {
            int pos = tmp[cnt]+1;
            while(tmpsum+a[pos]<=a[r]&&pos<r)
            {
                ++pos;
            }
            ans += max(r-pos,0ll);
            ans %= mod;
            tmpsum -= a[tmp[cnt]];
            ++tmp[cnt];
            tmpsum += a[tmp[cnt]];
            while(tmp[cnt] >= r-len+cnt&&cnt > 0)
            {
                tmpsum -= a[tmp[cnt]];
                --cnt;
                ++tmp[cnt];
            }
        }
        if(tmp[0] == r-len)
        {
            tmp[0] = 0;
            break;
        }
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1; i<=n; ++i)
    {
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    for(int i = 1; i<=n; ++i)
    {
        sum[i] = sum[i-1]+a[i];
    }
    for(int i = 3; i<=n; ++i) //max
    {
        for(itn len = 2;len<i;++len)
        {
            solve(i,len-1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
