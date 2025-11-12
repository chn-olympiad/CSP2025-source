#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
constexpr int N=1e4+5,M=1e6+5;
int n,m,K,c[15],a[15][N];
ll ans;
struct Edge {
    int u,v,w;
    bool operator< (const Edge &tmp) const {
        return w<tmp.w;
    }
} e[10000005];
int fa[N+10];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void work_k0() {
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) {
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu!=fv) {
            fa[fu]=fv;
            ans+=e[i].w;
        }
    }
    cout<<ans<<"\n";
}
bool speA() {
    for(int i=1;i<=K;i++) {
        if(c[i]) return 0;
        bool flag=0;
        for(int j=1;j<=n;j++)
            if(!a[i][j]) flag=1;
        if(!flag) return 0;
    }
    return 1;
}
void work_speA() {
    for(int k=1;k<=K;k++)
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!a[k][i]||!a[k][j]) e[++m]={i,j,a[k][i]+a[k][j]};
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) {
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu!=fv) {
            fa[fu]=fv;
            ans+=e[i].w;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>K;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=K;i++) {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    if(!K) {
        work_k0();
        return 0;
    }
    if(speA()) {
        work_speA();
        return 0;
    }

    return 0;
}
/*
失败了。
我可能确乎是没有天赋的。
NOIP 将是我的最后一舞了。
*/