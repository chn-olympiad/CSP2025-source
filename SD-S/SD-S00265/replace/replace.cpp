#include <bits/stdc++.h>
#define fi first
#define se second
#define mps make_pair(uf[j][0], uf[j][1])
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
using pss = pair<string, string>;
using psi = pair<string, int>;

const int N = 2E5 + 10;

int n, m, k, tot, q;
string s[N][2], t[N][2];
string qx[N], qz[N], ux[N], uz[N];
int ql[N], qr[N];
array<string, 4> uf[N];
pair<pss, int> qf[N];
psi x[N], y[N];
vector<array<int, 3>> upd[N];
vector<pii> qry[N];
int qpx[N], qpy[N], fen[N], ans[N];

void add(int x, int y) {
	for (int i = x; i <= tot; i += i & -i)
		fen[i] += y;
}
int sum(int x) {
	if (!x) return 0;
	int res = 0;
	for (int i = x; i; i -= i & -i)
		res += fen[i];
	return res;
}

array<string, 4> work(string a, string b) {
	string x = "", y = "", _y = "", z = "";
	int pos = 0;
	while (a[pos] == b[pos])
		x += a[pos ++];
	pos = a.size() - 1;
	while (a[pos] == b[pos])
		z += a[pos --];
	reverse(x.begin(), x.end());
	reverse(z.begin(), z.end());
	for (int j = x.size(); j + z.size() < a.size(); j ++)
		y += a[j], _y += b[j];
	return {x, y, _y, z};
}

pii qseg(psi s[], string t) {
	int L, R;
	int lo = 1, ro = tot;
	while (lo <= ro) {
		int mid = lo + ro >> 1;
		if (s[mid].fi < t) lo = mid + 1;
		else ro = mid - 1;
	}
	L = lo, ro = tot;
	while (lo <= ro) {
		int mid = lo + ro >> 1;
		if (t.size() > s[mid].fi.size()) ro = mid - 1;
		else {
			bool ok = true;
			for (int o = 0; o < t.size(); o ++)
				if (t[o] != s[mid].fi[o]) {
					ok = false;
					break;
				}
			if (ok) lo = mid + 1;
			else ro = mid - 1;
		}
	}
	R = lo - 1;
	return {L, R};
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; i ++) {
		cin >> s[i][0] >> s[i][1];
		if (s[i][0] == s[i][1]) continue;
		
		auto tmp = work(s[i][0], s[i][1]);
		string x = tmp[0], y = tmp[1], _y = tmp[2], z = tmp[3];
		uf[ ++ m] = {y, _y, x, z};
	}
	sort(uf + 1, uf + 1 + m);
	
	
	for (int i = 1; i <= q; i ++) {
		cin >> t[i][0] >> t[i][1];
		
		auto tmp = work(t[i][0], t[i][1]);
		string x = tmp[0], y = tmp[1], _y = tmp[2], z = tmp[3];
		qf[i] = {{y, _y}, i};
		qx[i] = x, qz[i] = z;
	}
	sort(qf + 1, qf + 1 + q);
	
//	cerr << "UPD\n";
//	for (int i = 1; i <= m; i ++)
//		cerr << uf[i][0] << ' ' << uf[i][1] << ' ' << uf[i][2] << ' ' << uf[i][3] << '\n';
//	cerr << "QUERY\n";
//	for (int i = 1; i <= q; i ++)
//		cerr << qf[i].fi.fi << ' ' << qf[i].fi.se << ' ' << qf[i].se << '\n';
	
	for (int i = 1, j = 1, k = 1; i <= q; i = k) {
		while (k <= q && qf[i].fi == qf[k].fi) k ++;
		while (j <= m && mps < qf[i].fi) j ++;
		if (j <= m && mps == qf[i].fi) {
			int ul = j, ur;
			while (j <= m && mps == qf[i].fi) j ++;
			ur = j - 1, tot = 0;
			// 扫描线 i ~ k - 1 的查询对应 ul ~ ur 的修改 
//			cerr << i << ' ' << k - 1 << ' ' << ul << ' ' << ur << '\n';
			for (int o = i; o < k; o ++) {
				int id = qf[o].se;
				x[ ++ tot] = {qx[id], id};
				y[tot] = {qz[id], id};
			}
			for (int o = 1; o <= tot + 1; o ++)
				upd[o].clear(), qry[o].clear(), fen[o] = 0;
			
			sort(x + 1, x + 1 + tot);
			sort(y + 1, y + 1 + tot);
			for (int o = 1; o <= tot; o ++)
				qpx[x[o].se] = o, qpy[y[o].se] = o;
			for (int o = i; o < k; o ++) {
				int id = qf[o].se;
				qry[qpx[id]].push_back({qpy[id], id});
			}
			for (int o = ul; o <= ur; o ++) {
				auto xseg = qseg(x, uf[o][2]);
				auto yseg = qseg(y, uf[o][3]);
				if (xseg.fi > xseg.se || yseg.fi > yseg.se) continue;
				upd[xseg.fi].push_back({yseg.fi, yseg.se, 1});
				upd[xseg.se + 1].push_back({yseg.fi, yseg.se, -1});
			}
			
			for (int o = 1; o <= tot; o ++) {
				for (auto t : upd[o]) {
					int l = t[0], r = t[1], v = t[2];
					add(l, v), add(r + 1, -v);
				}
				for (auto t : qry[o]) {
					int x = t.fi, y = t.se;
					ans[y] = sum(x);
				}
			}
		}
	}
	
	for (int i = 1; i <= q; i ++)
		cout << ans[i] << '\n';
	
	return 0;
}

