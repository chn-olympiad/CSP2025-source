#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6+10;
int v[maxn], u[maxn], w[maxn], a[maxn], cj[maxn], cnt = 1, sum;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	while (k--) {
		cin >> cj[cnt];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cnt++;
	}
	sort(w + 1, w + n + 1);
	for (int i = 1; i <= n - 1; i++) {
		sum += w[i];
	}
	cout << sum;
	
	return 0;
}

