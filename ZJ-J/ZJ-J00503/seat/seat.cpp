#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e3+10;
int cj[maxn];
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;++i)
    {
        scanf("%lld",&cj[i]);
    }
    int xr=cj[1];
    sort(cj+1,cj+n*m+1,greater<>());
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int idx=(i-1)*n+j;
            if(cj[idx]==xr)
            {
                if(i&1)
                {
                    printf("%lld %lld\n",i,j);
                }
                else
                {
                    printf("%lld %lld\n",i,n-j+1);
                }
                return 0;
            }
        }
    }
}