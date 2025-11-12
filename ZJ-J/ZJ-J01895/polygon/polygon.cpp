#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5005];
int ans;
int c[5005][5005];
void dfs(int p,int m,int maxx,int sum)
{
    if(p==n+1)
    {
        if(m>=3&&sum>2*maxx)ans++;
        ans%=mod;
        return;
    }
    dfs(p+1,m+1,max(maxx,a[p]),sum+a[p]);
    dfs(p+1,m,maxx,sum);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>1)flag=0;
    }
    if(!flag)dfs(1,0,0,0);
    else
    {
        c[0][0]=1;
        for(int i=1;i<=n+1;i++)
        {

            for(int j=1;j<=i;j++)
            {
                c[i][j]=c[i-1][j]+c[i-1][j-1];
                c[i][j]%=mod;
            }
        }
        for(int i=3;i<=n;i++)
        {
            ans+=c[n+1][i+1];
            ans%=mod;
        }
    }
    printf("%d",ans);
    return 0;
}
