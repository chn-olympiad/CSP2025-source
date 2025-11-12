#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define ll long long 
#define ull unsigned long long
#define PII pair<int,int>
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define ld double
#define cl(f,x) memset(f,x,sizeof(f))
#define lg(x) (31-__builtin_clz(x))
#define pcnt(x) __builtin_popcount(x)
using namespace std;
void file_IO() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=1e4+15,K=10,M=1<<10;
struct node {
    int u,v,w;
    node() {
        u=v=w=0;
    }
    node(int a,int b,int c) {
        u=a; v=b; w=c;
    }
    bool operator < (const node &tmp) const {
        return w<tmp.w;
    }
}; vector<node> vec,vect[K],f[M];
int fa[N],siz[N],a[K];
int find(int x) {
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
vector<node> merge(vector<node> vec,vector<node> tmp) {
    vector<node> res;
    int len=vec.size(),lent=tmp.size();
    int i=0,j=0;
    while(i<len||j<lent) {
        if(i<len&&(j==lent||vec[i]<tmp[j]))
            res.push_back(vec[i++]);
        else
            res.push_back(tmp[j++]);
    }
    return res;
}
ll kruskal(int n,vector<node> &edge) {
    rep(i,1,n)
        fa[i]=i,siz[i]=1;
    ll res=0;
    vector<node> t;
    for(auto x:edge) {
        int u=x.u,v=x.v,w=x.w;
        u=find(u); v=find(v);
        if(u!=v) {
            res+=w;
            if(siz[u]>siz[v])
                swap(u,v);
            fa[u]=v;
            siz[v]+=siz[u];
            t.push_back(x);
        }
    }
    edge=t;
    return res;
}
ll g[M];
int read() {
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9')
        x=x*10+ch-48,ch=getchar();
    return x;
}
void solve() {
    int n=read(),m=read(),k=read();
    while(m--) {
        int u=read(),v=read(),w=read();
        vec.push_back(node(u,v,w));
    }
    sort(vec.begin(),vec.end());
    rep(i,0,k-1) {
        a[i]=read();
        rep(j,1,n) {
            int x=read();
            vect[i].push_back(node(n+i+1,j,x));
        }
        sort(vect[i].begin(),vect[i].end());
    }
    f[0]=vec;
    ll res=kruskal(n+k,f[0]);
    rep(S,1,(1<<k)-1) {
        int x=S&-S;
        f[S]=merge(f[S^x],vect[lg(x)]);
        g[S]=g[S^x]+a[lg(x)];
        chkmin(res,g[S]+kruskal(n+k,f[S]));
    }
    printf("%lld\n",res);
}
bool M2;
// g++ road.cpp -std=c++14 -Wall -O2 -o road
signed main() {
    file_IO();
    int testcase=1;
    // scanf("%d",&testcase);
    while(testcase--)
        solve();
    // debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    // debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}