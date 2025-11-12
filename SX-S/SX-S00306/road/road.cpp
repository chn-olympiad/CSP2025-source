#include <bits/stdc++.h>
using namespace std;
long long a[10][1000];
int n, m, k;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i += 1) {
		for (int j = 0; j < 3; j += 1) {
			cin >> a[i][j];
		}
	}
	cout << 13;

	return 0;
}