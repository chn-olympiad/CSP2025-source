#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)

using namespace std;
const int N = 1e6 + 10;
int m;
string s, t;
string a[200005], b[200005];
int h1[N], h2[N], pw[N], len[N], g[N], h[N];
void solve() {
	int n, res = 0;
	cin >> s >> t;
	n = s.size();
	s = '#' + s;
	t = '#' + t;
	rep(i, 1, n) {
		h1[i] = h1[i - 1] * 131 + s[i];
		h2[i] = h2[i - 1] * 131 + t[i];
	}
	int l = 1, r = n;
	while(s[l] == t[l]) ++ l;
	while(s[r] == t[r]) -- r;
	per(p, l, 1) {
		rep(i, 1, m) {
//			p, p + len[i] - 1
//			1, len[i]
			if(p + len[i] - 1 > n) continue;
			if(p + len[i] - 1 < r) continue;
//			if(p == 1 && i == 1) {
//				cout << "deb : \n";
//				cout << p + len[i] - 1 << ' ' << p - 1 << ' ' << h1[p + len[i] - 1] - h1[p - 1] * pw[len[i]] << '\n';
//			}
			if(h1[p + len[i] - 1] - h1[p - 1] * pw[len[i]] == g[i])  
				if(h2[p + len[i] - 1] - h2[p - 1] * pw[len[i]] == h[i])
					++ res;
		}
	}
	cout << res << '\n';
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> m >> q;
	pw[0] = 1;
	rep(i, 1, 1000000) pw[i] = pw[i - 1] * 131;
	rep(i, 1, m) {
		cin >> a[i] >> b[i];
		len[i] = a[i].size();
		a[i] = '#' + a[i];
		b[i] = '#' + b[i];
		
		int s1 = 0, s2 = 0;
		rep(j, 1, len[i]) {
			s1 = s1 * 131 + a[i][j];
			s2 = s2 * 131 + b[i][j];
		}
		g[i] = s1, h[i] = s2;
//		cout << g[i] << ' ' << h[i] << '\n';
	}
	rep(i, 1, q) {
		solve();
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

10 2
aabca aadea
ab cd
bc de
aa bb
ab ad
b c
b d
c e
cx ex
abcx adex

xabcx xadex
bd cd
*/
