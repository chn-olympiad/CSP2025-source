#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct IO {
	IO() { freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout); }
	~IO() { fclose(stdin), fclose(stdout); }
} io;
const ll P = 999999999999999989;
int n, q;
char s[5000005], t[5000005];
int nxt[10000005][26], tcn = 1;
int lt[10000005], rt[10000005], cti;
void DFS(int u) {
	lt[u] = ++cti;
	for (int i = 0; i < 26; i++) {
		if (nxt[u][i]) DFS(nxt[u][i]);
	}
	rt[u] = cti;
}
struct MDF {
	ll has;
	int u, v;
	bool operator<(const MDF &b) const { return has < b.has; }
} mdf[200005];
struct QRY {
	ll has;
	int u, v, id;
	bool operator<(const QRY &b) const { return has < b.has; }
} qry[200005];
bool In(int u, int v) { return lt[u] >= lt[v] && rt[u] <= rt[v]; }
ll ans[200005];
namespace Solver {
	struct MDF {
		int x, y, w;
		bool operator<(const MDF &b) const { return x < b.x; }
	} mdf[800005];
	struct QRY {
		int x, y, id;
		bool operator<(const QRY &b) const { return x < b.x; }	
	} qry[200005];
	int mC, qC;
	void InsM(int u, int v) {
		mdf[++mC] = { lt[u], lt[v], 1 };
		mdf[++mC] = { rt[u] + 1, rt[v] + 1, 1 };
		mdf[++mC] = { lt[u], rt[v] + 1, -1 };
		mdf[++mC] = { rt[u] + 1, lt[v], -1 };
	}
	int f[1000005];
	int bu[1000005], bC;
	void M(int i, int w) { for (; i <= bC; i += i & -i) f[i] += w; }
	int Q(int i) { int res = 0; for (; i; i &= i - 1) res += f[i]; return res; }
	void InsQ(int u, int v, int id) {
		qry[++qC] = { lt[u], lt[v], id };
	}
	void Clear() {
		for (int i = 1; i <= bC; i++) f[i] = 0;
		mC = qC = bC = 0;
	}
	int sgn(int x) { return x > 0 ? 1 : -1; }
	void Solve() {
		for (int i = 1; i <= qC; i++) bu[++bC] = qry[i].y;
		for (int i = 1; i <= mC; i++) bu[++bC] = mdf[i].y;
		sort(bu + 1, bu + bC + 1);
		bC = unique(bu + 1, bu + bC + 1) - bu - 1;
		for (int i = 1; i <= qC; i++) {
			qry[i].y = lower_bound(bu + 1, bu + bC + 1, qry[i].y) - bu;
		}
		for (int i = 1; i <= mC; i++) {
			mdf[i].y = lower_bound(bu + 1, bu + bC + 1, mdf[i].y) - bu;
		}
		sort(mdf + 1, mdf + mC + 1), sort(qry + 1, qry + qC + 1);
		for (int i = 1, j = 1; i <= qC; i++) {
			while (j <= mC && mdf[j].x <= qry[i].x) M(mdf[j].y, mdf[j].w), j++;
			ans[qry[i].id] += Q(qry[i].y);
		}
		Clear();
	}
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s%s", s + 1, t + 1);
		if (!strcmp(s + 1, t + 1)) {
			i--, n--;
			continue;
		}
		int L = strlen(s + 1);
		int l = 1, r = L;
		while (s[l] == t[l]) l++;
		while (s[r] == t[r]) r--;
		int p = 1;
		for (int i = l - 1; i >= 1; i--) {
			int &q = nxt[p][s[i] - 'a'];
			if (!q) q = ++tcn;
			p = q;
		}
		int lp = p;
		p = 1;
		for (int i = r + 1; i <= L; i++) {
			int &q = nxt[p][s[i] - 'a'];
			if (!q) q = ++tcn;
			p = q;
		}
		int rp = p;
		__int128 ms = 0;
		for (int i = l; i <= r; i++) ms = (ms * 251 + s[i]) % P;
		for (int i = l; i <= r; i++) ms = (ms * 251 + t[i]) % P;
		mdf[i] = { (ll)ms, lp, rp };
	}
	for (int i = 1; i <= q; i++) {
		scanf("%s%s", s + 1, t + 1);
		int L = strlen(s + 1);
		int l = 1, r = L;
		while (s[l] == t[l]) l++;
		while (s[r] == t[r]) r--;
		int p = 1;
		for (int i = l - 1; i >= 1; i--) {
			int &q = nxt[p][s[i] - 'a'];
			if (!q) q = ++tcn;
			p = q;
		}
		int lp = p;
		p = 1;
		for (int i = r + 1; i <= L; i++) {
			int &q = nxt[p][s[i] - 'a'];
			if (!q) q = ++tcn;
			p = q;
		}
		int rp = p;
		__int128 ms = 0;
		for (int i = l; i <= r; i++) ms = (ms * 251 + s[i]) % P;
		for (int i = l; i <= r; i++) ms = (ms * 251 + t[i]) % P;
		qry[i] = { (ll)ms, lp, rp, i };
	}
	DFS(1);
	sort(mdf + 1, mdf + n + 1), sort(qry + 1, qry + q + 1);
	for (int i = 1, j = 0; i <= q; ) {
		while (j < n && mdf[j + 1].has < qry[i].has) j++;
		int p = i;
		while (p < q && qry[p + 1].has == qry[i].has) p++;
		if (j < n && mdf[j + 1].has == qry[i].has) {
			for (int k = j + 1; k <= n && mdf[k].has == qry[i].has; k++) {
				Solver::InsM(mdf[k].u, mdf[k].v);
			}
			for (int k = i; k <= p; k++) {
				Solver::InsQ(qry[k].u, qry[k].v, qry[k].id);
			}
			Solver::Solve();
		}
		i = p + 1;
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
	return 0;
}
// 15:42