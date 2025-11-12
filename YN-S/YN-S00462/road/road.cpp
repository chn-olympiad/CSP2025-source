#include <bits/stdc++.h>
using namespace std;
int u[10004];
int v[10004];
int w[10009];
int a[1000006];
int b[1000006];
int sum;

int main(void) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> u[i] >> v[i] >> w[i];
		sum = min(u[i] + v[i] + w[i], sum);
	}
	for (int j = 1; j <= k; j++) {
		cin >> a[j];
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
	}
	cout << sum;
	return 0;
}