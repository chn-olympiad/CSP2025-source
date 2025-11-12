#include <iostream>
using namespace std;
int path[10005][10005],n,m,k,r[10005][15],c[15],sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		path[u][v] = w;
		path[v][u] = w;
		sum += w;
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
			r[j][i] = x;
		}
	}
	cout << sum;
}
