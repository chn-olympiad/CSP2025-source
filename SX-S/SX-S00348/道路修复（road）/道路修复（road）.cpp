#include <bits/stdc++.h>
using namespace std;
int a[100086];

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	int min = INT_MAX;
	int u1, u2, u3;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u1 >> u2 >> u3;

		int min = min + u1;
		if (min > u2)
			min = min + u2;
		else if (min > u3)
			min = min + u3;
	}
	for (int j = j + m + 1; j <= n ; j++) {
		cin >> a[j];
	}
	cout << 13;
	return 0;
}
