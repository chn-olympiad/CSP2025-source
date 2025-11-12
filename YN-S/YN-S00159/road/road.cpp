#include <bits/stdc++.h>
using namespace std;

namespace my_namespace {
	int n;
	int m;
	int k;
	int w[1000000 + 2];
	int main() {
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie();
		cout.tie();
		cin >> n >> m >> k;
		long long int ans = 0;
		int u;
		int v;
		for (int i = 1; i <= m; i++) {
			cin >> u >> v >> w[i];;
			ans += w[i];
		}
		cout << ans << '\n';
		return 0;
	}
}

int main() {
	return my_namespace::main();
}