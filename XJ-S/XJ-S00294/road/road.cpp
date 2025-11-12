#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct edge{
    int v,w;
};
vector<edge> e[N];
int n,m,k,a[N],c[N],f[N],ans;
bool cmp(edge u,edge v){
    return u.w<v.w;
}
void dfs(int now,int val){
    if(f[now]){
        return ;
    }
    f[now]=1,ans+=val;
    edge s[N]={0};
    int i=0;
    for(edge v:e[now]){
        i++;
        s[i].v=v.v,s[i].w=v.w;
    }
    sort(s+1,s+1+i,cmp);
    for(int j=1;j<=i;j++){
        if(f[s[j].v]==1){
            continue;
        }
        dfs(s[j].v,s[j].w);
        return ;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back((edge){v,w});
        e[v].push_back((edge){u,w});
    }
    for(int i=1;i<=k;i++){
        int q;
        cin>>q;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=1;j<=n;j++){
            memset(c,0,sizeof(c));
            for(int l=0;l<e[j].size();l++){
                c[e[j][l].v]=1;
                if(e[j][l].w>a[j]+a[e[j][l].v]+q){
                    e[j][l].w=a[j]+a[e[j][l].v]+q;
                }
            }
            for(int l=1;l<=n;l++){
                if(l==j||c[l]==1){
                   continue; 
                }
                e[j].push_back((edge){l,a[j]+a[l]+q});
                e[l].push_back((edge){j,a[j]+a[l]+q});
            }
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}