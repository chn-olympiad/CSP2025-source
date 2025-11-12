#include<bits/stdc++.h>
using namespace std;
#define maxn 20004
#define maxk 12

ifstream is("road.in", ios::in);
ofstream os("road.out", ios::out);
#define cin is
#define cout os

struct edge
{
    int u, v, w;
    edge(int U=0, int V=0, int W=0): u(U), v(V), w(W) {}
    friend bool operator<(const edge &a, const edge &b)
    {
        return a.w<b.w;
    }
};

vector<edge> vc;
edge ce[maxk][maxn];
int fa[maxn], cc=0;
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int c[maxk];
struct tmp
{
    int w, id, p;
    tmp(int W, int I, int P): w(W), id(I), p(P) {}
    friend bool operator<(const tmp &a, const tmp &b)
    {
        return a.w>b.w;
    }
};

priority_queue<tmp> pq;

edge minx(int n)
{
    auto fw=pq.top();
    pq.pop();
    auto ret=ce[fw.id][fw.p];
    if(fw.id==0&&fw.p==cc) return ret;
    if(fw.p==n) return ret;
    fw.p++;
    if(ce[fw.id][fw.p].w>=ce[0][cc].w&&fw.id!=0)
        return ret;
    pq.emplace(ce[fw.id][fw.p].w, fw.id, fw.p);
    return ret;
}
int64_t chk(int S, int k, int n)
{
    while(!pq.empty()) pq.pop();
    int64_t ret=0;
    pq.emplace(ce[0][1].w, 0, 1);
    for(int i=1;i<=k;i++)
        if(S&(1<<(i-1)))
        {
            ret+=c[i];
            pq.emplace(ce[i][1].w, i, 1);
        }
    iota(fa+1, fa+n+k+1, 1);
    edge E;
    while(!pq.empty())
    {
        E=minx(n);
        int u=E.u, v=E.v, w=E.w;
        u=find(u), v=find(v);
        if(u==v) continue;
        fa[v]=u;
        ret+=w;
    }
    return ret;
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1, u, v, w;i<=m;i++)
    {
        cin>>u>>v>>w; 
        vc.emplace_back(u, v, w);
    }
    iota(fa+1, fa+n+k+1, 1);
    sort(vc.begin(), vc.end());
    int64_t tot=0;
    for(auto E:vc)
    {
        int u=E.u, v=E.v, w=E.w;
        if(find(u)==find(v)) continue;
        fa[find(v)]=find(u);
        tot+=w;
        ce[0][++cc]=E;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1, w;j<=n;j++) 
            cin>>w, ce[i][j]={i+n, j, w};
        sort(ce[i]+1, ce[i]+1+n);
    }
    for(int i=1;i<(1<<k);i++)
        tot=min(tot, chk(i, k, n));
    cout<<tot;
}