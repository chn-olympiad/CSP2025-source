#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n,m,k;
int u,v,w;
ll ans;
int mp[10005][10005];
int vc[12];
int c[12][10005];
int r1[10005];
ll f[10005];
vector<int>r[10005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		r[u].push_back(v);
		r[v].push_back(u);
		mp[u][v]=w;
		mp[v][u]=w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>vc[i];
		for(int j=1;j<=n;j++)cin>>c[i][j];
	}
	cout<<ans;
	return 0;
}
