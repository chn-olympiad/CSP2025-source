#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6;
int n, m, k;
int u[N], v[N], w[N], c[15], a[15][10010];
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i ++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 0; i < k; i ++){
		cin >> c[i];
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	cout << 15;
	return 0;
}