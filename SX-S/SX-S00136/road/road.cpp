#include <bits/stdc++.h>
using namespace std;
long long n, m, k, page[10005][10005], c, p, summ, u, v, w;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(), cout.tie();
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) {
		for (int j = 1; j <= n + k; j++) {
			if (i == j) {
				page[i][j] = 0;
				page[j][i] = 0;
			} else {
				page[i][j] = INT_MAX;
				page[j][i] = INT_MAX;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		page[u][v] = w;
		page[v][u] = w;
	}


	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> p;
			page[j][n + i] = p ;
			page[n + i][j] = p ;
		}
	}

	/*for (int i = 2; i <= n + k; i++) {
		cout << "page[1][n]:" << page[n - 1][n] << endl;
	}*/
	for (int o = 1; o <= n; o++) {
		for (int i = 1; i <= o; i++) {
			for (int j = 1; j <= i; j++) {
				page[i][j] = min(page[i][j], page[i][o] + page[o][j]);
			}
		}
	}


	/*for (int i = 1; i <= n + k; i++) {
		for (int j = 1; j <= n + k; j++) {
			cout << page[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 2; i <= n; i++) {
		summ += page[i - 1][i];
		//cout << "page[i-1][i]:" << page[i - 1][i] << endl;
	}
	cout << summ;
	return 0;
}
