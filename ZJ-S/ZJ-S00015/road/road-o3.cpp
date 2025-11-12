#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+17;
const int nmax=1e4;
const int maxm=1e6+7;
const int maxk=17;
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
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    vector<edge>all_edges;
    for(int i=1;i<=m;++i)
    {
        edge edt;
        cin>>edt.u>>edt.v>>edt.w;
        all_edges.push_back(edt);
    }
    for(int i=1;i<=k;++i)
    {
        int t; cin>>t;
        for(int j=1;j<=n;++j)
        {
            long long w; cin>>w;
            edge edt;
            edt.u=j;
            edt.v=i+nmax;
            edt.w=w;
            all_edges.push_back(edt);
        }
    }
    // ksuskal
    long long ans=0;
    vector<long long>eduse[maxk]
    sort(all_edges.begin(),all_edges.end());
    return 0;
}