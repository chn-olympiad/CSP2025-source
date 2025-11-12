#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> inline void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
const ll N = 1e5 + 5;
ll t, n, a[N][4], rec[N], ans, cnt[4];
bool flag[N];
priority_queue <pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
void clearr() {
	ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n; ++i) flag[i] = 0;
}
ll cal(ll k) {
	ll ma = max(max(a[k][1], a[k][2]), a[k][3]);
	ll i = 1;
	while (1) if (ma == a[k][i++]) return i - 1;
}
bool check(){return cnt[1] * 2 <= n && cnt[2] * 2 <= n && cnt[3] * 2 <= n;}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(t);
	while (t--) {
		clearr();
		read(n);
		for (int i = 1; i <= n; ++i) {
			read(a[i][1]), read(a[i][2]), read(a[i][3]);
			rec[i] = cal(i);
			ans += a[i][rec[i]];
			++cnt[rec[i]];
		}
		if (check()) {
			printf("%lld\n", ans);
			continue;
		}
		ll out = (cnt[1] * 2 > n ? 1 : (cnt[2] * 2 > n ? 2 : 3));
		for (int i = 1; i <= n; ++i) {
			if (rec[i] == out) {
				for (int j = 1; j <= 3; ++j) {
					if (j == out) continue;
					q.push(make_pair(a[i][out] - a[i][j], i));
				}
			}
		}
		ll len = cnt[out] - n / 2;
		for (int i = 1; i <= len; ++i) {
			while (flag[q.top().second]) q.pop();
			ll val = q.top().first, k = q.top().second; q.pop();
			ans -= val, flag[k] = 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
