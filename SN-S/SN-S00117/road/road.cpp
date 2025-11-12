//SN-S00117  吴禹泽  陕西延安中学
#include<iostream>
#include<cstring>
#include<algorithm>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct Edge{
	int v, w, nxt;
}edge[2200050];

int h[10015], tot;

inline void addEdge(int u, int v, int w) {
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].nxt = h[u];
	h[u] = tot;
	tot ++;
}

int n, m, k;
int ww[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	fastio;
	
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		ww[i] = w;
	}
	
	sort(ww+1, ww+m+1);
	
	int ans = 0;
	for(int i=1; i<=n-1; i++) {
		ans += ww[i];
	}
	cout<<ans;
	return 0;
}
