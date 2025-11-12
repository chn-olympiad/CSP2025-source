#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 5e5+10;
constexpr int maxm = 1.5e6+10;

int ll[maxm];// sum[i]^k de xiabiao
int n,k;
int sum[maxn];

signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%lld%lld",&n,&k);
    int rr=0;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",sum+i);
        sum[i]^=sum[i-1];
        // printf("%lld ",sum[i]);
        if((ll[sum[i]^k] || !(sum[i]^k)) && ll[sum[i]^k]+1>rr)
        {
            ++ans;
            rr=i;
        }
        ll[sum[i]]=i;
    }

//    putchar('\n');
//    for(int i=1;i<=n;++i)
//    {
//        printf("%lld ",sum[i]^k);
//    }
//    putchar('\n');

    printf("%lld",ans);

    return 0;
}
