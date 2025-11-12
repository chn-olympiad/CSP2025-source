#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,k,ans;
int mp[1005][1005];
int fa[1005];
int fd(int x){
    if(fa[x]==x) return x;
    return fa[x]=fd(fa[x]);
}
void merge(int x,int y){
    y=fd(y);x=fd(x);
    fa[x]=y;
}
int c[15];
int a[15][10005];
struct edge{
    int u,v,w;
}e[1000005];
int cnt;
bool cmp(edge x,edge y){
    return x.w<y.w;
}
void kls(){
    sort(e+1,e+1+cnt,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    int ed=0;
    for(int i=1;i<=cnt;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        u=fd(u);v=fd(v);
        if(u!=v){
            merge(u,v);
            ans+=w;
            ed++;
            if(ed==n-1) break;
        }
    }
}
signed main(){
    //freopen("road3.in","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u][v]=mp[v][u]=min(mp[u][v],w);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
        ans+=c[i];
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                mp[j][k]=min(mp[j][k],a[i][j]+a[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(mp[i][j]==0x3f3f3f3f3f3f3f3f) continue;
            e[++cnt].u=i;e[cnt].v=j;e[cnt].w=mp[i][j];
        }
    }
    kls();
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
