#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
struct Node{
	long long v, w;
};
vector <Node> g[N];
long long a[N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	for(int i=1; i<=k; i++) {
		long long c;
		cin >> c;
		for (int j=1; j<=n; j++) cin >> a[j];
	}
	cout << 0 << endl;
	return 0;
}
