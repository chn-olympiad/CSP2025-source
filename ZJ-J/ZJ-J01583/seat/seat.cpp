#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e2+10;
int s[maxn][maxn],a[maxn],b[maxn],f[maxn];
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;++i)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n*m;++i)
    {
        int maxm=-1;
        int q=0;
        for(int j=1;j<=n*m;++j)
        {
            if(f[j]==0&&a[j]>maxm)
            {
                q=j;
                maxm=a[j];
            }
        }
        b[i]=a[q];
        f[q]=1;
    }
    for(int i=1;i<=m;++i)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;++j)
            {
                s[j][i]=b[(i-1)*n+j];

            }
        }
        else
        {
            for(int j=n;j>=1;--j)
            {
                s[j][i]=b[(i-1)*n+(n-j+1)];

            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(s[i][j]==a[1])
            {
                printf("%lld %lld\n",j,i);
                return 0;
            }
        }
    }
}
