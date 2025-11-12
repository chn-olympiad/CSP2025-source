#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,m,k;
struct node{
    int to,w;
    node(int to,int w):to(to),w(w){}
    friend bool operator<(node x,node y){return x.w>y.w;}
};
vector<vector<node>>g;
int ans;
int dis[10005];
void dij(int start){
    memset(dis,0x3f,sizeof dis);
    priority_queue<int>q;
    q.push(start);
    dis[start]=0;
    while(!q.empty()){
        int u=q.top();q.pop();
        ans=dis[u];
        for(node vv:g[u]){
            int v=vv.to,w=vv.w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push(v);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    g.resize(n*2+10);
    for(int i=1;i<=m;i++){
        int x,y,w;cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    for(int i=1;i<=k;i++){
        int cc,a;
        cin>>cc;
        for(int j=1;j<=n;j++){
            cin>>a;
            g[j].push_back({n+4+i,a+cc});
            g[n+1+i].push_back({j,a});
        }
    }
    dij(1);
    for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
    cout<<ans<<endl;
}
