#include <bits/stdc++.h>
using namespace std; const int N = 5500000, M = 200005;
int n, q, a[N], m, hd[M << 1], sz[M << 1]; long long ans[M];
struct QR {
	string u, v;
} qr[M];
struct SA {
	int sa[N], rk[N], cnt[N], ht[22][N], y[N];
	void build() {
		for (int i = 1; i <= m; ++i) ++cnt[a[i]];
		for (int i = 1; i < N; ++i) cnt[i] += cnt[i - 1];
		for (int i = m; i >= 1; --i) sa[cnt[a[i]]--] = i;
		for (int i = 2, t = rk[sa[1]] = 1; i <= m; ++i)
			rk[sa[i]] = (a[sa[i]] != a[sa[i - 1]] ? ++t : t);
		//for (int i = 1; i <= m; ++i) cout << rk[i] << ' '; cout << '\n';
		for (int w = 1; w <= m; w <<= 1) {
			int t = 0;
			for (int i = m - w + 1; i <= m; ++i) y[++t] = i;
			for (int i = 1; i <= m; ++i) if (sa[i] > w) y[++t] = sa[i] - w;
			memset(cnt, 0, sizeof cnt);
			for (int i = 1; i <= m; ++i) ++cnt[rk[i]];
			for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
			for (int i = m; i >= 1; --i) sa[cnt[rk[y[i]]]--] = y[i];
			swap(rk, y); t = rk[sa[1]] = 1;
			for (int i = 2; i <= m; ++i)
				rk[sa[i]] = (y[sa[i]] == y[sa[i - 1]] &&
				             y[sa[i] + w] == y[sa[i - 1] + w] ? t : ++t);
			if (t == m) break;
		}
		//cout << m << '\n';
		//for (int i = 1; i <= m; ++i) cout << sa[i] << ' '; cout << '\n';
		//for (int i = 1; i <= m; ++i) cout << rk[i] << ' '; cout << '\n';
		//return;
		for (int i = 1, k = 0; i <= m; ++i) {
			if (i == sa[1]) {
				k = 0; continue;
			}
			if (k) --k;
			while (a[i + k] == a[sa[rk[i] - 1] + k]) ++k;
			ht[0][rk[i]] = k;
		}
		for (int i = 1; (1 << i) <= m; ++i)
			for (int j = 1; j + (1 << i) - 1 <= m; ++j)
				ht[i][j] = min(ht[i - 1][j], ht[i - 1][j + (1 << i - 1)]);
	}
	int lcp(int x, int y) {
		if (x == y) return m - sa[x] + 1;
		if (x > y) swap(x, y); ++x;
		int k = __lg(y - x + 1);
		return min(ht[k][x], ht[k][y - (1 << k) + 1]);
	}
	pair<int, int> rnge(int x, int y) {
		int l = 1, r = x, w, f, g;
		while (l <= r) {
			w = l + r >> 1;
			if (lcp(x, w) >= y) f = w, r = w - 1; else l = w + 1;
		}
		l = x; r = m;
		while (l <= r) {
			w = l + r >> 1;
			if (lcp(x, w) >= y) g = w, l = w + 1; else r = w - 1;
		}
		return make_pair(f, g);
	}
} sa;
struct BIT {
	int a[N];
	void U(int x, int v) {
		for (; x <= m; x += x & -x) a[x] += v;
	}
	void add(int l, int r, int v) {
		U(l, v); U(r + 1, -v);
	}
	int Q(int x) {
		int r = 0; for (; x; x -= x & -x) r += a[x];
		return r;
	}
} tr;
struct upds {
	int l, r;
}; vector<upds> g[N];
struct ques {
	int x, i;
}; vector<ques> h[N];
int sigm(char u, char v) {
	return (u - 'a') * 26 + v - 'a' + n + q + 1;
}
void ins(string u, string v, int i) {
	if (u.size() != v.size()) return;
	hd[i] = m + 1; sz[i] = u.size();
	for (int j = 0; j < sz[i]; ++j)
		a[++m] = sigm(u[j], v[j]);
	a[++m] = i;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		string u, v; cin >> u >> v;
		ins(u, v, i);
	}
	for (int i = 1; i <= q; ++i)
		cin >> qr[i].u >> qr[i].v, ins(qr[i].u, qr[i].v, i + n);
	sa.build(); //return 0;
	for (int i = 1; i <= q; ++i) {
		if (qr[i].u.size() != qr[i].v.size()) continue;
		int pre = 0;
		while (qr[i].u[pre] == qr[i].v[pre]) ++pre;
		int suf = sz[i + n] - 1;
		while (qr[i].u[suf] == qr[i].v[suf]) --suf;
		for (int j = 0; j <= pre; ++j)
			h[suf - j + 1].push_back(ques{sa.rk[hd[i + n] + j], i});
	}
	for (int i = 1; i <= n; ++i) {
		pair<int, int> d = sa.rnge(sa.rk[hd[i]], sz[i]);
		g[sz[i]].push_back(upds{d.first, d.second});
	}
	for (int i = N - 1; i >= 1; --i) {
		for (auto [l, r] : g[i]) tr.add(l, r, 1);
		for (auto [x, id] : h[i]) ans[id] += tr.Q(x);
	}
	for (int i = 1; i <= q; ++i) cout << ans[i] << '\n'; return 0;
}