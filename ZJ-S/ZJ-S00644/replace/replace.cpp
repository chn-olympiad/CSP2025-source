#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10, M = 3010;
using pii = pair<int, int>;

int n, q, ed[M];
map<pii, int> S[M]; int idx;
string a[N], b[N];
map<int, vector<pii> > z;
struct dat {
	int x, y, id;
	bool operator < (const dat& t) const {
		return x < t.x;
	}
};
map<int, vector<dat> > qu;
int c[N], res[N];

void ins(string a, string b) {
	int p = 0;
	for (int i = 0; i < (int)a.size(); i ++ ) {
		if (!S[p].count({a[i] - 'a', b[i] - 'a'})) S[p][{a[i] - 'a', b[i] - 'a'}] = ++ idx;
		p = S[p][{a[i] - 'a', b[i] - 'a'}];
	} ed[p] ++ ;
}
void add(int x, int y) {
	while (x < N) c[x] += y, x += (x & -x);
}
int qry(int x) {
	int res = 0;
	while (x) res += c[x], x -= (x & -x);
	return res;
}
void clr(int x) {
	while (x < N) c[x] = 0, x += (x & -x);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q; int L = 0;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i] >> b[i];
		L += a[i].size() + b[i].size();
	}
	if (q <= 3000 && L <= 3000) {
		for (int i = 1; i <= n; i ++ ) ins(a[i], b[i]);
		for (int i = 1; i <= q; i ++ ) {
			string s, t; cin >> s >> t;
			if (s.size() != t.size()) {
				cout << 0 << '\n';
				continue ;
			} vector<pii> cur; int cnt = 0;
			int ql = -1, qr = 0;
			for (int j = 0; j < (int)s.size(); j ++ )
				if (s[j] != t[j]) {
					if (ql == -1) ql = j;
					qr = j;
				}
			for (int j = 0; j < (int)s.size(); j ++ ) {
				if (j <= ql) cur.push_back({0, j}); 
				vector<pii> arr;
				for (pii _ : cur) {
					int k = _.first, it = _.second;
					if (S[k].count({s[j] - 'a', t[j] - 'a'})) {
						int id = S[k][{s[j] - 'a', t[j] - 'a'}];
						arr.push_back({id, it}); 
						if (j >= qr) cnt += ed[id];
					}
				} cur = arr;
			} cout << cnt << '\n';
		} 
	}
	else {
		for (int i = 1; i <= n; i ++ ) {
			int x = -1, y = -1;
			for (int j = 0; j < (int)a[i].size(); j ++ ) {
				if (a[i][j] == 'b') x = j; 
				if (b[i][j] == 'b') y = j;
			}
			z[x - y].push_back({x, (int)a[i].size() - x});
		}
		for (int i = 1; i <= q; i ++ ) {
			string s, t; 
			cin >> s >> t;
			if (s.size() != t.size()) {
				res[i] = 0;
				continue ;
			} int _x = -1, _y = -1;
			for (int j = 0; j < (int)s.size(); j ++ ) {
				if (s[j] == 'b') _x = j;
				if (t[j] == 'b') _y = j;
			}
			qu[_x - _y].push_back({_x, (int)s.size() - _x, i});
		}
		for (auto _ : qu) {
			vector<dat> it = _.second;
			vector<pii> d = z[_.first];
			sort(d.begin(), d.end());
			sort(it.begin(), it.end());
			for (int i = 0, j = 0; i < (int)d.size(); i ++ ) {
				int _q = j;
				while (_q < (int)it.size() && it[_q].x <= d[i].first) {
					res[it[_q].id] = qry(it[_q].y);
					_q ++ ;
				} j = _q;
				int p = i;
				while (p < (int)d.size() && d[p].first == d[i].first) {
					add(d[p].second, 1); p ++ ;
				}
				_q = j;
				while (_q < (int)it.size() && it[_q].x <= d[i].first) {
					res[it[_q].id] = qry(it[_q].y);
					_q ++ ;
				} j = _q; i = p - 1;
				if (i == (int)d.size() - 1) {
					int _q = j;
					while (_q < (int)it.size()) {
						res[it[_q].id] = qry(it[_q].y);
						_q ++ ;
					}
				}
			}
			for (int i = 0; i < (int)d.size(); i ++ ) clr(d[i].second);
		}
		for (int i = 1; i <= q; i ++ ) cout << res[i] << '\n';
	}
	return 0;
}
