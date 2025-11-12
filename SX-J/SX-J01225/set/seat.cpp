#include <bits/stdc++.h>
using namespace std;
int a[15][15], b[105], c;

int main() {
	int n, m;
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	c = b[0];
	sort(b, n + b + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

		}
	}
	return 0;
}