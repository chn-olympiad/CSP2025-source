// 这道题可做在哪 
#include <bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) ((int)s.size())
using namespace std;
const int N = 2e5 + 5, base = 13331;
const int M = 5e6 + 6;
int n, q;
ull ha[M], hb[M], c[M], d[M], pw[M];
string a[N], b[N];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	FIO
	pw[0] = 1; F(i, 1, 5000000) pw[i] = pw[i-1] * base;
	cin >> n >> q;
	F(i, 1, n) {
		cin >> a[i] >> b[i];
		ha[i] = hb[i] = 0;
		F(j, 0, sz(a[i])-1) ha[i] = ha[i] * base + a[i][j], hb[i] = hb[i] * base + b[i][j];
//		cout << ha[i] << ' ' << hb[i] << '\n';
	}
	F(_, 1, q) {
		string s, t; cin >> s >> t;
		int len = sz(s);
		if (len != sz(t)) {
			cout << 0 << '\n';
			continue;
		}
		s = " " + s, t = " " + t;
		int l = 1, r = len, ans = 0;
		F(i, 1, len) {
			c[i] = c[i-1] * base + s[i], d[i] = d[i-1] * base + t[i];
		}
		F(i, 1, len) if (s[i] != t[i]) {
			l = i; break;
		}
		D(i, len, 1) if (s[i] != t[i]) {
			r = i; break;
		}
		F(i, r, len) {
			F(j, 1, n) {
				if (sz(a[j]) < i-l+1) continue;
				int ln = sz(a[j]); 
//				cout << i-ln<<' '<<i << ' ' << j << ' ' << c[i]-c[i-ln] << '\n';
				if (ha[j] == c[i] - c[i-ln]*pw[ln] && hb[j] == d[i] - d[i-ln]*pw[ln]) {
					++ans;
				} 
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

