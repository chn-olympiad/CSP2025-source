#include <bits/stdc++.h>

using namespace std;

const int N = 510, P = 998244353;

int n, m, a[N], c[N];
int f[1 << 18][18];

void get(int &a, int b) { a += b; if (a >= P) a -= P; }

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < n; i++) cin >> c[i], cnt += (c[i] > 0);
	long long p = 1;
	for (int i = 1; i <= n; i++) p = p * i % P;
	if (cnt < m) {
		cout << 0;
		return 0;
	}
	if (m == n) {
		if (cnt == n) cout << p;
		else cout << 0;
		return 0;
	}
	if (n > 18) {
		cout << p;
		return 0;
	}
	f[0][0] = 1;
	for (int i = 0; i < 1 << n; i++) {
		int x = 1;
		for (int j = 0; j < n; j++) if (i >> j & 1) x++;
		for (int j = 0; j <= n; j++) {
			if (!f[i][j]) continue;
			for (int k = 0; k < n; k++) {
				if (i >> k & 1) continue;
				if (!a[x]) get(f[i | (1 << k)][j + 1], f[i][j]);
				else {
					if (j >= c[k]) get(f[i | (1 << k)][j + 1], f[i][j]);
					else get(f[i | (1 << k)][j], f[i][j]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - m; i++) get(ans, f[(1 << n) - 1][i]);
	cout << ans;
	return 0;
}

