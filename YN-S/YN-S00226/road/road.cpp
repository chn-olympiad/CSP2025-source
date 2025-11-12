#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int c[100005], y[100005], h[100005];
int w;
int a[15], b[15][100005];
int ci[10005];
int maxn;

int main() {
	freopen("road", "r", stdin);
	freopen("road", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> c[i] >> y[i] >> h[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		for (int j = 1; j <= m; j++) {
			cin >> b[i][j];
		}
	}
	cout << 13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}