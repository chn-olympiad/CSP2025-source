#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int maxn = 1e2+10;
int sc[maxn];
int n,m;
bool cmp(int a,int b){return a>b;}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i<=n*m;++i)
    {
        scanf("%lld",sc+i);
    }
    int qwq = sc[1];
    int qwa = n*m;
    sort(sc+1,sc+qwa+1,cmp);
    int cnt = 0;
    for(int i = 1;i<=m;++i)
    {
        for(int j = 1;j<=n;++j)
        {
            ++cnt;
            if(sc[cnt] == qwq)
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
    return 0;
}
