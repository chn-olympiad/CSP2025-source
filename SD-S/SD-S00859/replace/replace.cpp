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
#endif
#ifndef DISFILE
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
#else
#define file(...)
#endif
}using namespace whaleL;
const int N = 2e5 + 233;
#define int ll
#define ull unsigned ll

int ln[N];
string s[N][2], b[2];
int n, q;

bool tag;
signed main(){
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	file(replace);
	cin >> n >> q;
	f(i, n) {
		cin >> s[i][0] >> s[i][1];
		ln[i] = s[i][0].size();
	}
	f(awa, q) {
		int ans = 0;
		cin >> b[0] >> b[1];
		if (b[0] == b[1]) cout << 0, gn;
		int lb = b[0].size();
		f(k, n) {
			fo(l, 0, lb - 1) {
				int r = l + ln[k] - 1;
				if (r > lb - 1) brk;
				tag = false;
				fo(i, l, r) {
					if (b[0][i] != s[k][0][i - l]) tag = true;
				}
				if (tag == true) con;
				fo(i, l, r) {
					b[0][i] = s[k][1][i - l];
				}
				if (b[0] == b[1]) ans ++;
				fo(i, l, r) {
					b[0][i] = s[k][0][i - l];
				}
			}
		}
		cout << ans, gn;
	}
}


