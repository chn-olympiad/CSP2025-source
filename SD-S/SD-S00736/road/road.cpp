#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n, m, k, c[11], a[11][N], ans;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1, u, v, w; i<=m; i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
		}
	}
	cout<<ans;
	
	return 0;
}
/*
5 8 0
1 2 5
1 3 1
1 4 7
2 3 2
2 5 6
3 4 3
3 5 4
4 5 8

*/
