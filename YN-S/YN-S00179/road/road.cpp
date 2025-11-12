#include <bits/stdc++.h>
#define For(a,b,i) for(int i=a;i<=b;i++)
using namespace std;
const int N = 1e4 + 5, B = 1e8;
int w[N][N];
int m, n, k;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	For(1, n, i) {
		For(1, n, j) {
			if (i == j) {
				w[i][j] = 0;
			} else {
				w[i][j] = B;
			}
		}
	}
	For(1, m, i) {
		int u, v, x;
		cin >> u >> v >> x;
		w[u][v] = x;
		w[v][u] = x;
	}
	For(1, n, k) {
		For(1, n, i) {
			For(1, n, j) {
				w[i][j] = min(w[i][k] + w[j][k], w[i][j]);
			}
		}
	}
	cout << w[1][n];

	return 0;
}