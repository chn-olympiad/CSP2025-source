#include<bits/stdc++.h>
using namespace std;
const int N=10015,M=1000005;
const long long INF=0x3f3f3f3f3f3f3f3f;
struct edge{
    int u,v,w,i;
    bool operator<(const edge& e)const{return w<e.w;}
}E[M],e[N*11];
int val[10],fa[N],sz[N];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
void merge(int x,int y){
    x=fa[x];
    y=fa[y];
    if(sz[x]<sz[y]) swap(x,y);
    fa[y]=x;
    sz[x]+=sz[y];
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0,u,v,w;i<m;++i){
        cin >> u >> v >> w;
        --u;
        --v;
        E[i]=edge{u,v,w,-1};
    }
    sort(E,E+m);
    for(int i=0;i<n;++i){
        fa[i]=i;
        sz[i]=1;
    }
    int cnt=0;
    for(int i=0;i<m;++i){
        const int u=E[i].u,v=E[i].v,w=E[i].w;
        if(find(u)!=find(v)){
            merge(u,v);
            e[cnt++]=edge{u,v,w,-1};
        }
    }
    for(int i=0;i<k;++i){
        cin >> val[i];
        for(int j=0,w;j<n;++j){
            cin >> w;
            e[cnt++]=edge{j,i+n,w,i};
        }
    }
    sort(e,e+cnt);
    long long res=INF;
    for(int S=0;S<(1<<k);++S){
        long long ans=0;
        for(int j=0;j<k;++j) ans+=val[j]*((S>>j)&1);
        for(int i=0;i<n+k;++i){
            fa[i]=i;
            sz[i]=1;
        }
        for(int i=0;i<cnt;++i){
            const int u=e[i].u,v=e[i].v,w=e[i].w,j=e[i].i;
            if(j!=-1 && !((S>>j)&1)) continue;
            if(find(u)!=find(v)){
                ans+=w;
                merge(u,v);
            }
        }
        res=min(res,ans);
    }
    cout << res << endl;
    return 0;
}