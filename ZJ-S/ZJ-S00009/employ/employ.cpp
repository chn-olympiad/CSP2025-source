#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,mcnt,s[510],c[510],f[(1<<18)+10][20],maxn[(1<<18)+10];
void add(int &x,int y)
{
    x+=y;
    if(x>=mod)x-=mod;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%1d",&s[i]);
        mcnt+=s[i];
    }
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    f[0][0]=1;
    for(int i=0,cnt;i<(1<<n);i++)
    {
        cnt=__builtin_popcount(i);
        for(int j=0;j<=maxn[i];j++)
        {
            for(int k=0;k<n;k++)
            {
                if((i>>k)&1)continue;                
                add(f[i|(1<<k)][j+(s[cnt+1]==0||j>=c[k+1])],f[i][j]);
                maxn[i|(1<<k)]=max(maxn[i|(1<<k)],j+(s[cnt+1]==0||j>=c[k+1]));
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)if(n-i>=m)add(ans,f[(1<<n)-1][i]);
    printf("%d\n",ans);
    return 0;
}