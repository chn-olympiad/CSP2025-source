#include <bits/stdc++.h>
using namespace std;
long long a[1000000], b[1000000], c[1000000], box;
int n, m, k;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		box += c[i];
	}
	cout << box;
	return 0;
}
