#include <bits/stdc++.h>
using namespace std;

const int N = 510, mod = 998244353;
int c[N], p[N];
char s[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		p[i] = i;
	}
	int ans = 0;
	do {
		int tot = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (c[p[i]] <= tot) {
				tot++;
				continue;
			}
			if (s[i] == '0') {
				tot++;
			} else {
				res++;
			}
		}
		if (res >= m) ans++;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << "\n";
	return 0;
}