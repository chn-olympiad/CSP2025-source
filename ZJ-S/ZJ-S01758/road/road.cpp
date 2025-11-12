#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N][N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long ans;
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		if(a[u][v]>w) a[u][v]=a[v][u]=w;
	}
	for(int i=1; i<n; i++) {
		for(int j=i+1; j<=n; j++) {
			ans+=a[i][j];
		}
	}
	cout << ans;
	return 0;
}

