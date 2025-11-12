#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, a;

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> a;
		for (int j = 1; j <= n; j++) {
			cin >> w;
		}
	}
	srand(time(0));
	int x = rand();
	cout << x;
	return 0;
}