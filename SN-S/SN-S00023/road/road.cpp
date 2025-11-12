#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;

#define endl '\n'

const int inf=1e9+7;

int n,m,k;

vector<pii>G[10005];

int c[15][10005],f[10005];
bool vis[10005];



int dfs(int now,int cost,set<int>pst)
{
    if(pst.size()==n)
    {
        return cost;
    }
    int ans=inf;
    for(auto edge:G[now])
    {
        if(!vis[edge.first])
        {
            auto pst_n = pst;
            pst_n.insert(edge.first);
            vis[edge.first]=1;
            ans=min(ans,dfs(edge.first,cost+edge.second,pst_n));
            vis[edge.first]=0;
        }
    }
    return ans;
}

int dfs2(int now,int cost,set<int>pst,set<int>fx)
{
    if(pst.size()==n)
    {
        return cost;
    }
    int ans=inf;
    if(now!=0)
        for(int i=1;i<=k;i++)
        {
            for(int to=1;to<=n;to++)
            {
                if(to==now)
                {
                    continue;
                }
                if(vis[to])
                {
                    continue;
                }
                auto pst_n=pst;
                vis[to]=1;
                pst_n.insert(to);
                if(fx.count(i))
                {
                    ans=min(ans,dfs2(to,cost+c[i][now]+c[i][to],pst_n,fx));
                }
                else
                {
                    auto fx_n=fx;
                    fx_n.insert(i);
                    ans=min(ans,dfs2(to,cost+c[i][now]+c[i][to],pst_n,fx_n)+f[i]);
                }
                vis[to]=0;
            }
        }
    for(auto edge:G[now])
    {
        if(!vis[edge.first])
        {
            auto pst_n = pst;
            pst_n.insert(edge.first);
            vis[edge.first]=1;
            ans=min(ans,dfs2(edge.first,cost+edge.second,pst_n,fx));
            vis[edge.first]=0;
        }
    }
    return ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,c;i<=m;i++)
	{
		cin>>u>>v>>c;
		G[u].push_back({v,c});
		G[v].push_back({u,c});
	}
	for(int i=1;i<=n;i++)
    {
        G[0].push_back({i,0});
    }
    if(k==0)
    {
        cout<<dfs(0,0,{})<<endl;
        return 0;
    }
	for(int i=1;i<=k;i++)
    {
        cin>>f[i];
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
    cout<<dfs2(0,0,{},{})<<endl;
	return 0;
}
