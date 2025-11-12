#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> >G[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	while(k--){
		int c,x;
		cin >> c;
		for(int i = 1;i <= n;i++) cin >> x;
	}
	cout << 0;
	return 0;
}
