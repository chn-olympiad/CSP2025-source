#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+4,K=12,M=2e6;
int n,m,k,fa[M];
int qwq,num;
int a[K][N],c[K],vis[K];
ll nowans,P;
struct node{
    int u,v,w;
}p[M],t[M];
inline int find(int x){
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
inline bool cmp(node x,node y){
    return x.w<y.w;
}
inline void check(){
    ll now=0;
    int tm=m,tn=n,cnt=0;
    for(int i=1;i<=m;++i) t[i]=p[i];
    for(int i=1;i<=k;++i){
        if (vis[i]==0) continue;
        now+=c[i];
        if (now>=nowans) return;
        ++tn;
        for(int j=1;j<=n;++j){
            t[++tm]={tn,j,a[i][j]};
        }
    }
    if (now>=nowans) return;
    for(int i=1;i<=tn;++i) fa[i]=i;
    sort(t+1,t+tm+1,cmp);
    for(int i=1;i<=tm;++i){
        // ++P;
        if (find(t[i].u)==find(t[i].v)) continue;
        fa[find(t[i].u)]=find(t[i].v);
        now+=t[i].w; ++cnt;
        if (now>=nowans) return;
        if (cnt==tn-1){
            break;
        }
    }
    nowans=min(now,nowans);
}
inline void dfs(int x,ll val){
    if (val>=nowans) return;
    if (x==k+1){
        check();
        return;
    }
    vis[x]=0; dfs(x+1,val);
    vis[x]=1; dfs(x+1,val+c[x]);
}
inline void dfs2(int x,ll val){
    if (val>=nowans) return;
    if (x==6){
        check();
        return;
    }
    vis[x]=0; dfs2(x+1,val);
    vis[x]=1; dfs2(x+1,val+c[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=1000000;++i) fa[i]=i;
    for(int i=1;i<=m;++i){
        cin>>p[i].u>>p[i].v>>p[i].w;
    }
    for(int i=1;i<=k;++i){
        cin>>c[i];
        int flag=0;
        if (c[i]==0) ++qwq;
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
            if (flag==0 && a[i][j]==0){
                flag=1; ++num;
            }
        }
    }
    if (qwq+num==2*k){// 32pts
        for(int i=1;i<=1500000;++i) fa[i]=i;
        ll res=0;
        for(int i=1;i<=k;++i){
            for(int j=1;j<=n;++j){
                p[++m]={i+n,j,a[i][j]};
            }
        }
        int cnt=0;
        // cout<<m<<"\n";
        sort(p+1,p+m+1,cmp);
        for(int i=1;i<=m;++i){
            if (find(p[i].u)==find(p[i].v)) continue;
            fa[find(p[i].u)]=find(p[i].v);
            res+=p[i].w; ++cnt;
            if (cnt==n+k-1){
                break;
            }
        }
        cout<<res<<"\n";
        return 0;
    }
    // first, run a Kruskal
    ll ans=0,cnt=0;
    sort(p+1,p+m+1,cmp);
    for(int i=1;i<=m;++i){
        if (find(p[i].u)==find(p[i].v)) continue;
        fa[find(p[i].u)]=find(p[i].v);
        ans+=p[i].w; ++cnt;
        if (cnt==n-1) break;
    }
    if (k==0){// 16 pts
        cout<<ans<<"\n";
        return 0;
    }
    nowans=ans;sort(c+1,c+k+1);
    if (k<=5){
        dfs(1,0);
    }
    else{
        dfs2(1,0);
    }
    for(int i=1;i<=k;++i){
    	vis[i]=1;
	}
	check();
    cout<<nowans<<"\n";
    // cerr<<P<<"\n";
    return 0;
}
/*
6 8 0
1 2 3
2 6 2
1 3 1
2 3 7
3 6 2
1 4 5
3 4 4
5 4 6
*/
