#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 8;
int n, m, k;
int ve[N][N], f[N], c[N];
bool vis[N][N];
struct Road{
	int u, v, w;
}ro[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>ro[i].u>>ro[i].v>>ro[i].w;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>ve[i][j];
		}
	}
	int tot=0;
	for(int i=1; i<=n; i++) {
		tot += ro[i].w;
	}
	cout<<tot;
	
	
	

	return 0;
}

