#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[105],a[105][10015];
int e[10015][10015];
bool f[10015][10015],ar[10015];
long long ans;
bool check()
{
    for (int i=1;i<=n;i++)
        if (!ar[i])
            return false;
    return true;
}
void fi(int no,long long s)
{
    if (check())
    {
        ans=min(ans,s);
        return;
    }
    for (int i=1;i<=10000;i++)
    {
        if (e[no][i]&&!f[no][i]&&!f[i][no])
        {
            f[no][i]=true;
            ar[i]=true;
            fi(i,e[no][i]);
            f[no][i]=false;
            ar[i]=false;
        }
    }
    if (!check())
        return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++)
    {
        cin >> u >> v >> w;
        e[u][v]=w;
        e[v][u]=w;
    }
    for (int i=1;i<=k;i++)
    {
        cin >> c[i];
        for (int j=1;j<=n;j++)
            cin >> a[i][j];
    }
    fi(1,0);
    cout << ans;
    return 0;
}
