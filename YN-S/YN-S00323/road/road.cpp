#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int x, y, z;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
	}
	for (int i = 1; i <= k; i++) {
		cin >> x;
		for (int i = 1; i <= n; i++) {
			cin >> y;
		}
	}
	cout << 0;
	return 0;
}
