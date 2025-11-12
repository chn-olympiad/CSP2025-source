#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int maxn = 5e5+10;
int a[maxn];
int xsum[maxn];

void subC()
{
    
}
signed main()
{
    int maxai = 0,acnt = 0;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%lld%lld",&n,&k);
    for(int i = 1;i<=n;++i)
    {
        scanf("%lld",a+i);
        maxai = max(maxai,a[i]);
        xsum[i] = xsum[i-1]^a[i];
        ++acnt;
    }
    if(acnt == n&&k == 0&&maxai == 1)//subA
    {
        int ans = n/2;
        printf("%lld\n",ans);
    }
    else
    {
        int ans = 0;
        int last = 0;
        for(int i = 1;i<=n;++i)
        {
            for(int j = last;j<i;++j)
            {
                int qwq = xsum[i]^xsum[j];
                if(qwq == k)
                {
                    ++ans;
                    last = i;
                    break;
                }
            }
        }
        printf("%lld",ans);
    }
    return 0;
}
