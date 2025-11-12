#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
const int N=1000005;
struct edge{
    int u;
    int v;
    int w;
}e[N];
int f[N];
int find(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    else
    {
        return f[x]=find(f[x]);
    }
}
bool cmp(edge q,edge p)
{
    return q.w<p.w;
}
int cnt=0,ans=0;
void kru()
{
    for(int i=1;i<=m;i++)
    {
        int rtu=find(e[i].u),rtv=find(e[i].v);
        if(rtu==rtv)
        {
            continue;
        }
        ans+=e[i].w;
        f[rtu]=rtv;
        cnt++;
        if(cnt==n-1)
        {
            break;
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)
    {
        for(int i=1;i<=m;i++)
        {
            f[i]=i;
            cin>>e[i].u>>e[i].v>>e[i].w;
        }
        sort(e+1,e+m+1,cmp);
        kru();
        cout<<ans;
    }
    else
    {
        cout<<0<<'\n';
    }
    return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
