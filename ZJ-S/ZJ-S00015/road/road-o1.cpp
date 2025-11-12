#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
const int maxm=1e6+7;
long long towns_offset[17][maxn];
struct node
{
    long long u;
    long long v;
    long long w;
    bool operator<(const node&nd)const
    {
        return w<nd.w;
    }
};
struct dsu
{
    vector<int>fa;
    dsu(int n)
    {
        fa.reserve(n+7);
        for(int i=0;i<=n;++i)
        {
            fa.push_back(i);
        }
    }
    int find(int x)
    {
        if(fa[x]==x)return x;
        else return fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        fa[find(x)]=find(y);
    }
};
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    vector<node>edges;
    int n,m,k; cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        node nd;
        cin>>nd.u>>nd.v>>nd.w;
        edges.push_back(nd);
    }
    // kruskal
    sort(edges.begin(),edges.end());
    dsu D(n);
    vector<node>important_edge;
    long long noadd_ans=0;
    for(int i=0;i<m;++i)
    {
        node nd=edges[i];
        long long u=nd.u,v=nd.v,w=nd.w;
        if(D.find(u)!=D.find(v))
        {
            important_edge.push_back(nd);
            noadd_ans+=w;
            D.merge(u,v);
        }
    }
    // test for kruskal
    // cerr<<noadd_ans<<'\n';
    // for(auto A:important_edge)
    // cerr<<A.u<<' '<<A.v<<' '<<A.w<<'\n';

    // input for towns
    vector<long long>towns_cost[17];
    for(int i=1;i<=k;++i)
    {
        for(int j=0;j<=n;++j)
        {
            long long t; cin>>t;
            towns_cost[i].push_back(t);
        }
    }
    // test for input
    // for(int i=1;i<=k;++i)
    // {
    //     for(auto &A:towns_cost[i])
    //     cerr<<A<<' ';
    //     cerr<<'\n';
    // }

    // compute the offset
    for(int i=1;i<=k;++i)
    {
        for(int j=0;j<important_edge.size();++j)
        {
            node ed=important_edge[j];
            int u=ed.u,v=ed.v,w=ed.w;
            if(towns_cost[i][u]+towns_cost[i][v]<w)
            towns_offset[i][j]=w-(towns_cost[i][u]+towns_cost[i][v]);
        }
    }
    // test for offset
    // for(int i=1;i<=k;++i)
    // {
    //     for(int j=0;j<important_edge.size();++j)
    //     {
    //         cerr<<towns_offset[i][j]<<' ';
    //     }
    //     cerr<<'\n';
    // }
    
    // zhuangya DP
    long long ans=noadd_ans;
    for(int i=0;i<(1<<k);++i)
    {
        // the bit of 1 is choosed
        long long nowans=0;
        long long best_offset[maxn];
        memset(best_offset,0,sizeof(best_offset));
        for(int j=0;j<k;++j)
        {
            if((i&(1<<j)))
            {
                int nowtown=j+1;
                nowans+=towns_cost[nowtown][0];
                for(int edc=0;edc<important_edge.size();++edc)
                best_offset[edc]=max(best_offset[edc],towns_offset[nowtown][edc]);
            }
        }
        // test for best_offset
        for(int edc=0;edc<important_edge.size();++edc)
        {
            cerr<<best_offset[edc]<<' ';
        }
        cerr<<'\n';
        
        for(int edc=0;edc<important_edge.size();++edc)
        {
            nowans+=important_edge[edc].w-best_offset[edc];
        }
        cerr<<i<<' '<<nowans<<'\n';
    }
    cerr<<ans;
    cout<<ans;
    return 0;
}