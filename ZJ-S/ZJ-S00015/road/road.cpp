#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
const int maxm=1e6+7;
const int maxk=17;
int n,m,k;
long long build_cost[maxk];
struct edge
{
    int u,v;
    long long w;
    bool operator<(const edge&ed)const
    {
        return w<ed.w;
    }
};
struct dsu
{
    vector<int>fa;
    long long intree_mincost[maxk][maxn];
    dsu(int n)
    {
        fa.reserve(n+7);
        for(int i=0;i<=n;++i)
        fa.push_back(i);
    }
    int find(int x)
    {
        if(fa[x]==x)return x;
        else return fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        if(find(x)==find(y))return;
        int xf=find(x);int yf=find(y);
        for(int i=1;i<=k;++i)
        {
            intree_mincost[i][yf]=min(intree_mincost[i][yf],intree_mincost[i][xf]);
        }
        fa[xf]=yf;
    }
};
vector<long long>addif_cost[maxk];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    vector<edge>all_edges;
    for(int i=1;i<=m;++i)
    {
        edge ed;
        cin>>ed.u>>ed.v>>ed.w;
        all_edges.push_back(ed);
    }
    // kruskal
    sort(all_edges.begin(),all_edges.end());
    dsu D(n);
    for(int i=1;i<=k;++i)
    {
        cin>>build_cost[i];
        for(int j=1;j<=n;++j)
        {
            cin>>D.intree_mincost[i][j];
        }
    }
    vector<edge>important_edge;
    long long noadd_ans=0;
    for(int edc=0;edc<all_edges.size();++edc)
    {
        edge edtmp=all_edges[edc];
        int u=edtmp.u;
        int v=edtmp.v;
        long long w=edtmp.w;
        if(D.find(u)!=D.find(v))
        {
            for(int i=1;i<=k;++i)
            {
                int fu=D.find(u),fv=D.find(v);
                long long mincost=D.intree_mincost[i][fu]+D.intree_mincost[i][fv];
                if(mincost>w)
                mincost=w;
                addif_cost[i].push_back(mincost);
            }
            noadd_ans+=w;
            D.merge(u,v);
            important_edge.push_back(edtmp);
        }
    }
    // test
    // for(int i=1;i<=k;++i)
    // {
    //     for(int j=0;j<addif_cost[i].size();++j)
    //     {
    //         cerr<<addif_cost[i][j]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    
    // zhuangya DP
    long long ans=noadd_ans;
    for(int status=0;status<(1<<k);status++)
    {
        // cerr<<status<<'\n';
        bool sta[maxk];
        for(int i=0;i<k;++i)
        {
            if(status&(1<<i))
            {
                sta[i+1]=true;
            }
        }
        sta[0]=true;
        long long final_cost[maxn];
        for(int j=0;j<important_edge.size();++j)
        {
            final_cost[j]=important_edge[j].w;
        }
        for(int i=1;i<=k;++i)
        {
            if(sta[i]==true)
            {
                for(int j=0;j<important_edge.size();++j)
                {
                    final_cost[j]=min(final_cost[j],addif_cost[i][j]);
                }
            }
        }
        long long final_ans=0;
        for(int i=1;i<=k;++i)
        {
            if(sta[i]==true)
            {
                final_ans+=build_cost[i];
            }
        }
        for(int j=0;j<important_edge.size();++j)
        {
            final_ans+=final_cost[j];
        }
        ans=min(ans,final_ans);
    }
    // cerr<<ans;
    cout<<ans;
    return 0;
}