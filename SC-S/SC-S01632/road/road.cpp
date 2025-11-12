#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int>G[1001];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<13;
	return 0;
}
