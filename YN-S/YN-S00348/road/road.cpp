#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[1000001], b[11];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int sum = 0;

	for (int i = 1; i <= m; i++) {

		cin >> a[i];
		sum += a[i];
	}

	for (int i = 1; i <= k; i++) {

		cin >> b[i];
	}

	cout << sum << endl;
	return 0;
}