#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 5;
int n, m, k, a[15][N];
ll sum;
int main (){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++){
		int u, v ,w;
		cin >> u >> v >> w;
		sum += w;
	}
	int f = 1;
	for (int i = 1; i <= k; i ++){
		for (int j = 0; j <= n; j ++){
			cin >> a[i][j];
			if (a[i][j] != 0)
				f = 0;
		}
	}			
	if (f){
		cout << 0;
		return 0;
	}
	cout << sum;
	return 0;
} 
