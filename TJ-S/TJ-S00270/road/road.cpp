#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node{
	int v;
	int w;
	int cnt;
};

ll m, n, k, x, y, z, ans;
ll d[11451];
bool vis[11451];
vector <Node> e[11451];

void prim(){
	for(int i=0; i<=n; i++){
		d[i] = 2147483647;
	}
	
	d[1] = 0;
	
	for(int i=1; i<=n; i++){
		int u=0;
		
		for(int j=1; j<=n; j++){
			if(d[j]<d[u] && !vis[j]){
				u = j;
			}
		}
		
		vis[u] = 1;
		ans += d[u];
		d[u] = 0;
		
		for(auto t:e[u]){
			if(d[t.v]>d[u]+t.w && !vis[t.v]){
				d[t.v] = d[u]+t.w;
			}
		}
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1; i<=m; i++){
		cin>>x>>y>>z;
		
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}
	
	prim();
	
	cout<<ans;
	
	return 0;
}
