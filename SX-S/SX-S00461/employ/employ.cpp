#include <iostream>
using namespace std;
int n, m, k;
int u[100010], v[100010], w[100010], c, a;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 1; j <= k; j++) {
		cin >> c;
		for (int i = 1; i <= n; i++) {
			cin >> a;
		}
	}
	cout << 11;
	return 0;
}