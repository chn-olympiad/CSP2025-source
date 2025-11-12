#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u, v, w, s, c, a;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0) {
		for (long long i = 0; i < m; i++) {
			cin >> u >> v >> w;
			s += w;
		}
		cout << s;
	} else {
		for (long long i = 0; i < n; i++) {
			cin >> u >> v >> w;
			if (u <= k || v <= k)
				continue;
			else
				s += w;
		}
		for (long long i = 0; i < k; i++) {
			cin >> c;
			s += c;
			for (long long j = 0; j < n; j++) {
				cin >> a;
			}
		}
		cout << s;
	}
	return 0;
}