#include <bits/stdc++.h>
using namespace std;
const int inf=214748360;
const int Maxn=10100;
int n,m,k;
struct ro
{
    int u,v,w;
    bool flag=false;
}road[1001000];
vector <int> city[Maxn];
int wt[Maxn];
bool vis[Maxn];
long long cnt;
void dj(int site)
{
    vis[site]=true;
    for(int i=1;i<=city[site].size();i++)
    {
        if(road[i].flag==true)
        {
            continue;
        }
         if(road[i].u==site)
        {
            wt[road[i].v]=min(wt[road[i].v],road[i].w);
            road[i].flag=true;
        }
        else
        {
            wt[road[i].u]=min(wt[road[i].u],road[i].w);
            road[i].flag=true;
        }
    }
    int Min=inf,si=-1;
    for(int i=1;i<=n;i++)
    {
        if(wt[i]<Min and vis[i]==false)
        {
            Min=wt[i];
            si=i;
        }
    }
    if(si==-1)
    {
        return;
    }
    else
    {
        dj(si);
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(vis,0,sizeof(vis));
    memset(wt,0x3f,sizeof(wt));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>road[i].u>>road[i].v>>road[i].w;
        city[road[i].u].push_back(i);
        city[road[i].v].push_back(i);
    }
    wt[1]=0;
    dj(1);
    for(int i=1;i<=n;i++)
    {
        cnt+=wt[i];
    }
    cout<<cnt;
    return 0;
}
