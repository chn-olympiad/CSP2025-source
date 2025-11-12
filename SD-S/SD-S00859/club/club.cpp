#include<bits/stdc++.h>
namespace whaleL{
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define emp emplace
#define emb emplace_back
#define fo(i, j, n) for(int i = (j); i <= (n); i ++)
#define f(i, n) fo(i, 1, n)
#define re return
#define brk break
#define con continue
#define il inline
#define gn (cout << '\n', 0)
il void P() {cerr << '\n';}
template<typename m, typename...ms>
void P(m x, ms...y) {cerr << x << ' '; P(y...);}
il void S(string s, int a) {cerr << s << a << ": ";}
#ifdef _MJawa_
#define p(x...) (S("["#x"] Line ", __LINE__), P(x), 0)
#else
#define p(...) 0
#endif
#ifndef DISFILE
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
#else
#define file(...)
#endif
}using namespace whaleL;
const int N = 2e5 + 233;
//#define int ll

pii s[N];
int a[N][4], cn[4];
int n, ans, m;

priority_queue<int> q;

#define nt(x) ((x + 1) % 3)

il void SOLVE() {
	ans = cn[0] = cn[1] = cn[2] = 0;
	cin >> n;
//	scanf("%d", &n);
	m = n / 2;
	f(i, n) {
		fo(j, 0, 2) 
//			scanf("%d", &a[i][j]);
			cin >> a[i][j];
		fo(j, 0, 2) {
			if ((a[i][j] >= a[i][nt(j)]) && (a[i][j] >= a[i][nt(nt(j))])) {
				ans += a[i][j], cn[j] ++;
				brk;
			}
		}
	}
	if (cn[0] <= m && cn[1] <= m && cn[2] <= m) {
//	printf("%d\n", ans);
		cout << ans, gn;
		p(114);
		re;
	}
	ans = 0;
	fo(u, 0, 2) {
		int res = 0;
		f(i, n) {
			s[i].fi = a[i][u];
			s[i].se = max(a[i][nt(u)], a[i][nt(nt(u))]);
			res += a[i][u];
			q.emp(s[i].se - s[i].fi);
		}
		f(i, m) {
			res += q.top(), q.pop();
		}
		f(i, m) q.pop();
		ans = max(ans, res);
	}
//	printf("%d\n", ans);
	cout << ans, gn;
	p(114);
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	file(club);
	int T; cin >> T;
	while (T --) SOLVE();
//	fclose(stdin), fclose(stdout);
}

