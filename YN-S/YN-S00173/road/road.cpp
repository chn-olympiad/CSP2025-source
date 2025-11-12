#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[100010], v[100010], w[100010], ans;

struct node {
	int c, a[1000010];
} s[1000100];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {

		cin >> u[i] >> v[i] >> w[i];
		ans += w[i];
	}

	cout << ans;
	return 0;
}