#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
int n, m, k, a[N], c[N], sum;



int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	bool p[1005][1005];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j + 1] == 0 || p[i + 1][j] == 0)
				sum += k;
		}


	}
	cout << sum;
	return 0;
}
