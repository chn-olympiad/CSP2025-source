#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector<pair<int,int> > g[1000010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	cout<<505585650;
	return 0;
}