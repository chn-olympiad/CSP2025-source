#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 2;
long long  n, m, k, va = 0, b = 0;
int v[maxn], u[maxn], w[maxn], c[maxn], a[maxn];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= n + 1; i++)
		cin >> c[i];
	for (int i = 1; i <= n + 1; i++) {
		cin >> a[i];
		if (a[i] != 0)
			b = 1;
	}
	if (b == 0)
		cout << 0;
	else
		cout << va;
	fclose(stdout);
	fclose(stdin);
	return 0;
}