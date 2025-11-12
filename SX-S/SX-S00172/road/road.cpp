#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000005], v[1000005], w[1000005], c[1000005], a[1000005][4], ansp = 0;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		ansp += w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}
	cout << ansp;
	return 0;

}
