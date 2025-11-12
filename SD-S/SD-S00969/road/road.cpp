#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const int N = 1e4 + 50;
int n, m, k;
int ans;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		ans += w;
	}
	cout << ans;
	return 0;
}
