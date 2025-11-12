#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> >e[1000005];
int n, m, k, u, v, w;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_bakc({u, w});
	}
	return 0;
}
