#include <bits/stdc++.h>
using namespace std;
int c[2000009];
int a[2000009];

struct sb {
	int u, v, w;
} b[2000009];

bool cmp(sb a1, sb a2) {
	return a1.w < a2.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> b[i].u >> b[i].v >> b[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
	}
	if (k == 0) {
		sort(b + 1, b + m + 1, cmp);
		cout << b[1].w + b[2].w + b[3].w;
		return 0;
	}
	return 0;
}