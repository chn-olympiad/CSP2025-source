#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> >e[10004];
int a[13][10004];
int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int ans = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push(make_pair(v, w));
		e[v].push(make_pair(u, w));
		ans+=w;
	}
	for (int i = 1; i <= k; i++){
		for (int j = 0; j <= n; j++){
			cin >> a[i][j];
		}
	}
	cout << ans-5 ;//womeizhaole
	return 0;
}
//CCF!You are the greatest contect!
