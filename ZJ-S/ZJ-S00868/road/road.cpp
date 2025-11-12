#include <bits/stdc++.h>
using namespace std;
vector<pair<int,long long> >v[10025];
long long n,m,k,cnt,ans=0x3f3f3f3f3f3f3f3f,c[15],vis[15],dis[10025];
long long Timm;
long long Kruskal(long long ans1){
    long long x=1,y,z;
    for(int i=2;i<=n+k;i++)dis[i]=0x3f3f3f3f3f3f3f3f;
    dis[1]=-1;
    for(int i=2;i<=n+cnt;i++){
        for(int j=0;j<v[x].size();j++){
            if(v[x][j].first>n&&vis[v[x][j].first-n]==0)continue;
            dis[v[x][j].first]=min(dis[v[x][j].first],v[x][j].second);
        }
        y=0x3f3f3f3f3f3f3f3f;
        for(int i=2;i<=n+k;i++){
            if(dis[i]==-1)continue;
            if(i>n&&vis[i-n]==0)continue;
            if(y>dis[i]){
                y=dis[i];
                z=i;
            }
        }
        dis[z]=-1;
        ans1+=y;
        x=z;
    }
    return ans1;
}
void dfs(int i,long long sum){
    Timm++;
    if(Timm>=300000000)return;
    if(i==k+1){
        Timm+=n*n;
        ans=min(ans,Kruskal(sum));
        return;
    }
    dfs(i+1,sum);
    if(vis[i])return;
    cnt++;
    vis[i]=1;
    dfs(i+1,c[i]+sum);
    cnt--;
    vis[i]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x,y,w;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(!c[i]){
            vis[i]=1;
            cnt++;
        }
        for(int j=1;j<=n;j++){
            cin>>w;
            v[n+i].push_back({j,w});
            v[j].push_back({n+i,w});
        }
    }
    if(cnt==k)cout<<Kruskal(0);
    else{
        dfs(1,0);
        cout<<ans;
    }
    return 0;
}
