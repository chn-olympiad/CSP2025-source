#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=1e4+14,M=1e6+6,K=10;
int n,m,k,a[K][N],x[M],y[M],w[M],c[K];
long long dis[N];
bool vis[N];
vector<pair<int,int>>edge[N];
int minn=1e18;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>x[i]>>y[i]>>w[i];
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    for(int mask=0;mask<1<<k;mask++){
        int ans=0;
        for(int i=1;i<=n+k;i++)edge[i].clear();
        for(int i=1;i<=m;i++){
            edge[x[i]].push_back({w[i],y[i]});
            edge[y[i]].push_back({w[i],x[i]});
        }
        for(int i=0;i<k;i++){
            if((mask>>i)&1){
                ans+=c[i];
                for(int j=1;j<=n;j++){
                    edge[i+n+1].push_back({a[i][j],j});
                    edge[j].push_back({a[i][j],i+n+1});
                }
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        q.push({dis[1]=0,1});
        while(!q.empty()){
            while(!q.empty()&&vis[q.top().second])q.pop();
            int x=q.top().second;
            if(vis[x])continue;
            ans+=dis[x];
            vis[x]=1;
            for(pair<int,int>y:edge[x]){
                // cout<<x<<' '<<y.second<<' '<<vis[y.second]<<' '<<dis[y.second]<<'\n';
                if(!vis[y.second]&&dis[y.second]>y.first){
                    dis[y.second]=y.first;
                    q.push({dis[y.second],y.second});
                }
            }
        }
        minn=min(minn,ans);
        // cout<<'\n';
    }
    cout<<minn<<'\n';
    return 0;
}