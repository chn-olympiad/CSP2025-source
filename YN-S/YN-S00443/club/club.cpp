#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, sum, sum1, sum2, ans1 = 0;

struct wy {
	int a, b, c;
} a[N], b[N];
vector<wy>tot;

bool cmp(wy x, wy y) {
	return y.a - x.a < y.b - x.b;
}

int zd() {
	tot.clear();
	sum = 0, sum1 = 0, sum2 = 0;
	sort(b + 1, b + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		if (i <= n / 2) {
			if (b[i].a >= b[i].c) {
				sum += b[i].a;
			} else {
				tot.push_back({b[i].c, b[i].a, 0});
			}
		} else {
			if (b[i].b >= b[i].c) {
				sum1 += b[i].b;
			}	else {
				tot.push_back({b[i].c, b[i].b, 0});
			}
		}
	}
	sort(tot.begin(), tot.end(), cmp);
	for (int i = 1; i <= tot.size(); i++) {
		if (i <= n / 2) {
			sum2 += tot[i - 1].a;
		} else {
			sum2 += tot[i - 1].b;
		}
	}
	return sum + sum1 + sum2 ;
}

void dfs(int x, int aa, int bb, int cc, int cnt) {
//	cout << x << ' ' << aa << ' ' << bb << ' ' << cc << ' ' << cnt << '\n';
	if (x >= n + 1) {
		ans1 = max(ans1, cnt);
		return;
	}
	if (aa < n / 2)
		dfs(x + 1, aa + 1, bb, cc, cnt + a[x].a);
	if (bb < n / 2)
		dfs(x + 1, aa, bb + 1, cc, cnt + a[x].b);
	if (cc < n / 2)
		dfs(x + 1, aa, bb, cc + 1, cnt + a[x].c);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		tot.clear();
		sum = 0, sum1 = 0, sum2 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		if (n <= 10) {
			ans1 = 0;
			dfs(1, 0, 0, 0, 0);
			cout << ans1 << '\n';
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				b[i] = a[i];
			}//abc
			ans = max(ans, zd());
			for (int i = 1; i <= n; i++) {
				b[i] = a[i];
				swap(b[i].b, b[i].c);
			}//acb
			ans = max(ans, zd());
			for (int i = 1; i <= n; i++) {
				b[i] = a[i];
				swap(b[i].a, b[i].b);
			}//bac
			ans = max(ans, zd());
			for (int i = 1; i <= n; i++) {
				b[i] = a[i];
				swap(b[i].a, b[i].b);
				swap(b[i].b, b[i].c);
			}//bca
			ans = max(ans, zd());
			for (int i = 1; i <= n; i++) {
				b[i] = a[i];
				swap(b[i].a, b[i].c);
				swap(b[i].b, b[i].c);
			}//cab
			ans = max(ans, zd());
			for (int i = 1; i <= n; i++) {
				b[i] = a[i];
				swap(b[i].a, b[i].c);
			}//cba
			ans = max(ans, zd());
			cout << ans << '\n';
		}
	}

	return 0;
}
