#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+8;
const int MOD=998244353;
int n,ans;
int a[MAXN],pfx[MAXN],t[MAXN],c[MAXN][MAXN];
void dfs(int pos,int sum,int stick,int id)
{
    if(sum<=a[id]||stick<2) return;
    if(pos==0)
    {
        if(sum>a[id]&&stick>=2) ans=(ans+1)%MOD;
        return;
    }
    dfs(pos-1,sum-a[pos],stick-1,id);
    dfs(pos-1,sum,stick,id);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],t[a[i]]++;
    if(t[1]==n)
    {
        int res=0;
        for(int i=0;i<=n;i++) c[i][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
        for(int i=3;i<=n;i++) res=(res+c[n][i])%MOD;
        cout<<res<<"\n";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pfx[i]=pfx[i-1]+a[i];
    for(int i=3;i<=n;i++)
    {
        if(pfx[i-1]<=a[i]) continue;
        dfs(i-1,pfx[i-1],i-1,i);
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
