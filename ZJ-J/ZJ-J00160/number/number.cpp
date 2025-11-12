#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 1e6+10;

char s[maxn];
int cnt[maxn];

signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    scanf("%s",s+1);
    for(int i=1;s[i];++i)
    {
        if(s[i]<='9' && s[i]>='0')
        {
            ++cnt[s[i]^48];
        }
    }

    for(int i=10;i>=0;--i)
    {
        for(int j=1;j<=cnt[i];++j)
        {
            printf("%lld",i);
        }
    }


    return 0;
}
