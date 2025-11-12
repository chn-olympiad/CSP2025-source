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
#define p(x...) S("["#x"] Line ", __LINE__), P(x)
#else
#define p(x...) 0
#define g(x...) 
#endif
#ifndef DISFILE
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
#else
#define file(...)
#endif
}using namespace whaleL;
const int N = 500 + 02;
#define int ll
const int MOD = 998244353;

int f[N][N][N];
char s[N];
int n, m, a[N], p[N], cnt, ans;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	file(employ);
	cin >> n >> m;
	f(i, n) cin >> s[i];
	f(i, n) {
		cin >> a[i];
	}
	if (n == m) {
		f(i, n) if (s[i] == '0') re cout << 0, 0;
		f(i, n) if (a[i] == 0) re cout << 0, 0;
		int res = 1;
		f(i, n) 
			res = (res * i) % MOD;
		cout << res;
		re 0;
	}
	f(i, n) p[i] = i;
	do {
		cnt = 0;
		f(i, n) {
			if (s[i] == '0') cnt ++;
			else if (cnt >= a[p[i]]) cnt ++;
		}
		if (n - cnt >= m) ans ++;
	}while (next_permutation(p + 1, p + 1 + n));
	cout << ans;
}


