#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 1e3+10;

int n,m;
int ai[maxn];

signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;++i)
    {
        scanf("%lld",ai+i);
    }

    int a1=ai[1];
    sort(ai+1,ai+1+n*m,greater<int>());

    int num=0;
    for(int i=1;i<=n*m;++i)
    {
        if(ai[i]==a1)
        {
            num=i;
        }
    }

    int k=num/n;
    int r=num%n;
    if(r)
    {
        if(k&1)
        {
            printf("%lld %lld\n",k+1,n-r+1);
        }
        else
        {
            printf("%lld %lld\n",k+1,r);
        }
    }
    else
    {
        if(k&1)
        {
            printf("%lld %lld\n",k,n);
        }
        else
        {
            printf("%lld %lld\n",k,1);
        }
    }

    return 0;
}
