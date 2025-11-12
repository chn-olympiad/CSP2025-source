#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("club.in", "r", stdin), freopen("club.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
int T, n;
ll a[100005][3], f[100005], g[3], ans;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = 0;
		memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) scanf("%lld", &a[i][j]);
			f[i] = max_element(a[i], a[i] + 3) - a[i];
			g[f[i]]++;
			ans += a[i][f[i]];
		}
		vector<ll> t;
		for (int i = 1; i <= n; i++) {
			if (g[f[i]] > n / 2) {
				int p = -1;
				for (int j = 0; j < 3; j++) {
					if (j != f[i]) {
						if (p == -1 || a[i][j] > a[i][p]) p = j;
					}
				}
				t.push_back(a[i][p] - a[i][f[i]]);
			}
		}
		sort(t.begin(), t.end(), greater<ll>());
		for (int i = 0; i < 3; i++) {
			if (g[i] > n / 2) {
				int x = g[i] - n / 2;
				for (int j = 0; j < x; j++) ans += t[j];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
// 14:39