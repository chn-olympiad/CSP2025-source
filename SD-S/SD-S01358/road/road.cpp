//fen+dijkstra+A
//64pts+8pts = 72pts
//ono zuofajiale
//shi lian tong hai shi wang luo liu
//wo shi sz
//wo mei xue guo wo bu zhi dao


#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int to,val;
};
vector<edge> g[100005];
int c[10],a[10][10005];
void dijkstra(int start){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		int u,v,w;
		cin >> u >> v >> w;
//		g[u].push_back({v,w});
//		g[v].push_back({u,w});
		for(int i = 1;i <= k;i++){
			g[u+(i-1)*n].push_back({v+(i-1)*n,w});
			g[v+(i-1)*n].push_back({u+(i-1)*n,w});
		}
	}
	bool A = 1;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i] != 0) A = 0;
		bool have0 = 0;
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j] == 0) have0 = 1;
		}  
		if(!have0) A = 0;
	} 
	for(int u = 1;u <= n;u++){
		for(auto v:g[u]){
			
		}
	}
}

