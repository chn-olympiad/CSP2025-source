#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 1e5 + 10;
int T, n, f[500][500];
struct Node {
	int a, b, c;
} p[N];
bool cmp(Node x, Node y) {
	return x.a - x.b > y.a - y.b;
}
void solve() {
	memset(f, -0x3f3f3f3f, sizeof(f));
	bool f1 = 0, f2 = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> p[i].a >> p[i].b >> p[i].c;
		if (p[i].b != 0) f1 = 1;
		if (p[i].c != 0) f2 = 1;
	}
	sort(p + 1, p + n + 1, cmp);
	if (!f2) {
		int ans = 0;
		for (int i = 1; i <= n / 2; i ++) ans += p[i].a;
		if (f1) {
			for (int i = n / 2 + 1; i <= n; i ++) ans += p[i].b;
		}
		cout << ans << endl;
		return;
	}
	f[0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (j > 0 && j <= n / 2)
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + p[i].c);
			if (i - j <= n / 2 && p[i].a >= p[i].b)
				f[i][j] = max(f[i][j], f[i - 1][j] + p[i].a);
			else
				f[i][j] = max(f[i][j], f[i - 1][j] + p[i].b);
		}
	}
	int ans = -1e18;
	for (int i = 0; i <= n / 2; i ++) ans = max(ans, f[n][i]);
	cout << ans << endl;
}
signed main() {
	File("club");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --) solve();
	return 0;
}
