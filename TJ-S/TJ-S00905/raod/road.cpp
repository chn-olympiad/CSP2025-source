#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int n,m,k;
struct node{
    int u,v,w,k;
}ls[N*12];
bool operator<(node a,node b)
{
    return a.w>b.w;
}
int a[12][N],c[12],fa[N],p=0;
long long ans=2e18;
priority_queue<node>q;
inline void init()
{
    for(int i=1;i<=k+n;i++)
        fa[i]=i;
}
inline void run(int x)
{
    init();
    long long sum=0;
    int a=n-1;
    for(int i=0;i<k;i++)
    {
        if(x&(1<<i))
            {a++;sum+=c[i];}
    }
    for(int i=0;i<p;i++)
    {
        if(a==0)break;
        node l=ls[i];
        if(l.k==-1||(1<<l.k)&x){
            int u=l.u,v=l.v;
            long long w=l.w;
            while(u!=fa[u])u=fa[u];
            while(v!=fa[v])v=fa[v];
            if(u!=v)
            {
                if((u+v)&1){
                    fa[v]=u;
                }
                else{
                    fa[u]=v;
                }
                sum+=w;
                a--;
            }
        }
    }
    ans=min(ans,sum);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        q.push({u,v,w,-1});
    }
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
        }
    }
    long long sum=0;
    init();
    for(int i=0;i<m;i++)
    {
        node l=q.top();
        q.pop();
        int u=l.u,v=l.v;
        long long w=l.w;
        int U=u,V=v;
        while(u!=fa[u])u=fa[u];
        while(v!=fa[v])v=fa[v];
        if(u!=v)
        {
            if((u+v)&1){
                fa[u]=v;
                fa[U]=v;
                fa[V]=v;
            }
            else{
                fa[v]=u;
                fa[V]=u;
                fa[U]=u;
            }
            ls[p++]=l;
        }
    }
    for(int i=0;i<=n-2;i++)
    {
        q.push(ls[i]);
    }
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            q.push({i+n+1,j,a[i][j],i});
        }
    }
    p=0;
    while(!q.empty())
    {
        ls[p++]=q.top();
        q.pop();
    }
    for(int i=0;i<(1<<k);i++)
    {
        run(i);
    }
    cout<<ans;
    return 0;
}
