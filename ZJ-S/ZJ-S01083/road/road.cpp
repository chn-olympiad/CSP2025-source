#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,m,ans,g[10100][10100];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		ll u,v,w;
		for(int j=1;j<=n;j++){
			cin>>u;
		}
	}
	cout<<ans;
	return 0;
}
