#include <bits/stdc++.h>

using namespace std;

int n, m, k, v[10004], e[10004];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int w;
		cin >> w >> w >> w;
		v[i] = w;
	}
	for(int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		for(int j = 1; j <= n; j++) {
			cin >> e[i];
			for(int o = 1; o < j; o++) {
				v[++m] = c + e[j] + e[o];
			}
		}
	}
	sort(v+1, v+m+1);
	for(int i = 1; i <= m; i++) cout << v[i] << ' ';
	int ans =0;
	for(int i = 1; i < n; i++) ans += v[i];
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
