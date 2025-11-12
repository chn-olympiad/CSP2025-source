#include <bits/stdc++.h>

using namespace std;

#define int long long

int _;
inline int read() {int s = 0, w = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') w *= -1;ch = getchar();}while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + (ch ^ 48);ch = getchar();}return s * w;}
inline void write(int x) {if (x < 0) x = -x, putchar('-');if (x > 9) write(x / 10);putchar(x % 10 + '0');}

const int N = 5e5 + 5;
int n, k, sum[N], vis[N], bi[35];
set<int> c;

struct node {
	int l, r;
	bool operator < (const node& b) {
		if ((r - l + 1) == (b.r - b.l + 1)) {
			return l > b.l;
		}
		return (r - l + 1) < (b.r - b.l + 1);
	}
} a[N];

struct edge {
	int l, r;
	bool operator < (const edge& c) {
		if ((r - l + 1) == (c.r - c.l + 1)) {
			return l < c.l;
		}
		return (r - l + 1) < (c.r - c.l + 1);
	}
} b[N];

inline void solve() {
	n = read(), k = read();
	if (k == 0) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int a = read();
			int cnt = 0;
			while (a) {
				if (a & 1) bi[cnt]++;
				a >>= 1;
				cnt++;
			}
			int f = 0;
			for (int x = 0; i <= 30; ++i) {
				if (bi[x] != 0) {
					f = 1;
					break;
				}
			}
			if (f) continue;
			for (int x = 0; i <= 30; ++i) {
				bi[x] = 0;
			}
			ans++;
		}
		write(ans);
		return ;
	}
	if (k == 1 || n > 1000) {
		int ans = 0;
		int cur = 0;
		while (k) {
			if (k & 1) c.insert(cur);
			k >>= 1;
			cur++;
		}
		
		for (int i = 1; i <= n; ++i) {
			int a = read();
			int cnt = 0;
			while (a) {
				if (a & 1) bi[cnt]++;
				a >>= 1;
				cnt++;
			}
			int f = 0;
			for (int x = 0; x <= 30; ++x) {
				if (c.count(x)) {
					if (bi[x] == 0) {
						f = 1;
						break;
					}
				} else {
					if (bi[x] & 1) {
						f = 1;
						break;
					}
				}
			}
			if (f) {
				continue;
			}
			memset(bi, 0, sizeof bi);
			ans++;
		}
		write(ans);
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		int a = read();
		sum[i] = (sum[i - 1] ^ a);
	}
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if ((sum[j] ^ sum[i - 1]) == k) {
				a[++tot] = {i, j};
				b[tot] = {i, j};
			}
		}
	}
	sort(a + 1, a + tot + 1);
	sort(b + 1, b + tot + 1);
	int ans = 0;
	for (int i = 1; i <= tot; ++i) {
		bool f = 0;
		for (int j = a[i].l; j <= a[i].r; ++j) {
			if (vis[j]) {
				f = 1;
				break;
			}
		}
		if (f == 1) continue;
		for (int j = a[i].l; j <= a[i].r; ++j) {
			vis[j] = 1;
		}
		ans++;
	}
	memset(vis, 0, sizeof vis);
	int ac = ans;
	ans = 0;
	for (int i = 1; i <= tot; ++i) {
		bool f = 0;
		for (int j = b[i].l; j <= b[i].r; ++j) {
			if (vis[j]) {
				f = 1;
				break;
			}
		}
		if (f == 1) continue;
		for (int j = b[i].l; j <= b[i].r; ++j) {
			vis[j] = 1;
		}
		ans++;
	}
	write(max(ac, ans));
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	_ = read();
	_ = 1;
	for (int i = 1; i <= _; ++i) solve();
	return 0;
}
