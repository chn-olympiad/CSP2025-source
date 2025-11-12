#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=1e5+10;
int t,n,ans;
int a[Maxn][3],f[2][5010][5010],tmp[Maxn];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        memset(f,0,sizeof(f));
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            if(a[i][1] || a[i][2]) flag=1;
        }
        if(n>=1e5 && !flag)
        {
            for(int i=1;i<=n;i++) tmp[i]=a[i][0];
            sort(tmp+1,tmp+1+n);
            for(int i=n;i>n/2;i--) ans+=tmp[i];
            printf("%d\n",ans);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=min(n/2,i);j++)
            {
                for(int k=0;k<=min(n/2,i);k++)
                {
                    if(j+k>i) break;
                    if(j>0) f[i%2][j][k]=max(f[i%2][j][k],f[(i%2)^1][j-1][k]+a[i][0]);
                    if(k>0) f[i%2][j][k]=max(f[i%2][j][k],f[(i%2)^1][j][k-1]+a[i][1]);
                    if(i-j-k>0 && i-j-k<=n/2) f[i%2][j][k]=max(f[i%2][j][k],f[(i%2)^1][j][k]+a[i][2]);
                    ans=max(ans,f[i%2][j][k]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
