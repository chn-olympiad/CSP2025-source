#incluide<bits/stdc++.h>
using namespace std;
const int inf = 1e+5;
int n, m, k, u[inf], v[inf], w[inf], c[inf], a[inf][inf], ans;

void dfs() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {

		}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

}