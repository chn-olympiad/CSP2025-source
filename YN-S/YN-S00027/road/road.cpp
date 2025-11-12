#include <bits/stdc++.h>
using namespace std;
int  u[1000005], v[1000005], w[1000005];
int a[10005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int m, n, k;
	cin >> n >> m >> k;
	for (int = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i];
		}
	}
	sort(u + 1, u + m + 1);
	sort(v + 1, v + m + 1);
	sort(w + 1, w + m + 1);
	sort(a + 1, a + n + 1);
	cout << u[1] + v[1] + w[1] + a[1] + a[2];
	fclose(stdin);
	fclose(stdout);
	return 0;
}