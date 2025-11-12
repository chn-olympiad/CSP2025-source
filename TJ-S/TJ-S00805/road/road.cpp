#include <bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1e6+1e5+50;
typedef long long ll;
struct node{
    ll to,dis;
};
vector<node> e[M];
bool vis[N];
ll n,m,k,g,cnt=1,f=0x3f3f3f3f;
void solve1(ll depth,ll lst,ll ans){
    if(depth==cnt-1){
        f=min(f,ans);
        return;
    }
    for(int i=0;i<e[lst].size();i++){
        node y=e[lst][i];
        if(vis[y.to]) continue;
        vis[y.to]=true;
        solve1(depth+1,y.to,ans+y.dis);
        vis[y.to]=false;
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    ll u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        cnt++;
    }
    ll a;bool flag=true;
    for(int j=1;j<=k;j++){
        cin>>g;
        if(g!=0) flag=false;
        for(int i=1;i<=n;i++){
            cin>>a;
            e[cnt].push_back({i,a+g});
            e[i].push_back({cnt,a+g});
        }
        cnt++;
    }
    if(flag){
        vis[1]=1;
        solve1(1,1,0);
        cout<<f;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
