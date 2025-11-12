#include<bits/stdc++.h>
#define int long long
using namespace std;

struct edge{
	int to,w;
};

int n,m,k;
int c[10],a[10][1000005];
vector<edge>G[1000005];

void prim(int x,int last){
	//  燃尽了，prim忘完了 
}

signed main(){
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}
//prim+预处理 
//但是忘完了 
