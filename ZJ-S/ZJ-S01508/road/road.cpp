#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int num=0,sign=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?sign=-1:sign=1,ch=getchar();
    while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return sign>0?num:-num;
}
const int MAXN=1e4+30;
const int MAXM=2e6;
const int MAXK=10+8;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,cnt,ans=INF;
int dis[MAXN],c[MAXK],mp[MAXK][MAXN];
bool vis[MAXN],ban[MAXN];
vector<pair<int,int>>edges[MAXN];
int prim(int s)
{
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    priority_queue<pair<int,int>>q;
    if(s==0)
    {
        vis[s]=1;
        for(int i=0;i<edges[s].size();i++)
        {
            int v=edges[s][i].first,w=edges[s][i].second;
            if(!ban[v]) continue;
            dis[v]=w,q.push({-dis[v],v});
        }
    }
    else dis[s]=0,q.push({0,s});
    bool flag=false;
    for(int i=1;i<=k;i++)
    {
        if(ban[i+n])
        {
            flag=true;
            break;
        }
    }
    if(flag==false) return INF;
    int res=0;
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]||(u>n&&!ban[u])) continue;
        vis[u]=1;
        res+=dis[u];
        for(int i=0;i<edges[u].size();i++)
        {
            int v=edges[u][i].first,w=edges[u][i].second;
            if(!ban[v]) continue;
            if(dis[v]>w) dis[v]=w,q.push({-dis[v],v});
        }
    }
    return res;
}
void dfs(int pos)
{
    if(pos==k+1)
    {
        int res=prim(0);
        //cout<<res<<"\n";
        ans=min(ans,res);
        return;
    }
    ban[pos+n]=true;
    dfs(pos+1);
    ban[pos+n]=false;
    dfs(pos+1);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1,u,v,w;i<=m;i++)
    {
        u=read(),v=read(),w=read();
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) ban[i]=1;
    ans=prim(1);
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        edges[0].push_back({i+n,c[i]});
        //edges[i+n].push_back({0,c[i]});
        for(int j=1,x;j<=n;j++)
        {
            x=read();
            edges[i+n].push_back({j,x});
            //edges[j].push_back({i+n,mp[i][j]});
        }
    }
    dfs(1);
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
