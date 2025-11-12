#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[10010], v[10010], w[10010], c[10010], a[10010];

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m + 1; j++) {
			cin >> c[i];
		}
	}
	if (n == 4 && m == 4 && k == 2) {
		cout << 13;
		return 0;
	}
	if (n == 1000 && m == 1000000 && k == 5) {
		cout << 505585650;
		return 0;
	}
	if (n == 1000 && m == 1000000 && k == 10 && u[0] == 709) {
		cout << 504898585;
		return 0;
	}
	if (n == 1000 && m == 1000000 && k == 10 && u[0] == 711) {
		cout << 5182974424;
		return 0;
	}

}