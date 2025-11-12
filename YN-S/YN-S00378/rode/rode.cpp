#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1000050], b[1200050], c[1000050], d[1000050], f[10050][10005], sum;

int main() {
	freopen("rode.in", "r", stdin);
	freopen("rode.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> d[i];
		for (int j = 1; j <= n; j++) {
			cin >> f[i][j]	;
		}
	}
	for (int i = 1; i <= n; i++) {
		sum += c[i];
	}
	cout << sum / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}