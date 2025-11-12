#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=1e4+1,M=1e6+1,inf=1e9+9;
ll n,m,k,adj[N+10][N+10],po[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1,u,v,w;i<=n;i++){
        cin>>u>>v>>w;
        memset(adj[i],inf,sizeof adj[i]);
        adj[u][v]=w,adj[v][u]=w;
    }
    for(ll i=n+1;i<=n+k;i++){
        cin>>po[i-n];
        for(ll j=1,w;j<=k;j++){
            cin>>w;
            adj[i][j]=w,adj[j][i]=w;
        }
    }

	return 0;
}

