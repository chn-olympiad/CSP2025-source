// AFO
#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 998244353;
const int N = 505;
int n, m, ans, p[N], c[N], fac[N];
string s;
bool vis[N];
void DFS(int u) {
	if (u > n) {
		int cnt = 0;
		F(i, 1, n) {
			if (cnt >= c[p[i]] || s[i] == '0') ++cnt;
		}
		if (n-cnt >= m) ++ans;
		return;
	}
	F(i, 1, n) if (!vis[i]) {
		vis[i] = 1, p[u] = i;
		DFS(u+1);
		vis[i] = 0;
	}
}
int buc[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	FIO
	cin >> n >> m >> s; s = " " + s;
	fac[0] = 1;
	F(i, 1, n) {
		fac[i] = fac[i-1] * i % mod;
		cin >> c[i];
	}
	sort(c + 1, c + 1 + n);
	bool flag = 1;
	F(i, 1, n) if (s[i] == '0') flag = 0;
	if (m == n) {	
		bool f2 = 1;
		F(i, 1, n) if (c[i] == 0) f2 = 0;
		if (flag && f2) cout << fac[n] << '\n';
		else cout << 0 << '\n';
		return 0;
	}
	if (m == 1) {
		bool f1 = 1;
	    F(i, 1, n) if (s[i] == '1') f1 = 0;
	    if (f1) {
	    	cout << 0 << '\n';
	    	return 0;
		}
////		F(i, 1, n) {
////			F(j, 1, i) {
////				int p = upper_bound(c + 1, c + 1 + n, j-1) - c - 1;
////				int q = n + 1 - (upper_bound(c + 1, c + 1 + n, j)-c);
////				f[i][j] = (f[i-1][j-1] * p % mod + f[i-1][j] * q % mod) % mod;
////			}
////		}
////		cout << (fac[n] - f[n][n] + mod) % mod << '\n';
//		F(i, 1, n) buc[c[i]]++;
//		F(i, 1, n) buc[i] += buc[i-1];
//		F(i, 1, n) {
//			ans = ans * (buc[i-1] - (i-1)) % mod;
//		}
//		return 0;
	}
	if (flag) {
		bool f2 = 1;
		F(i, 1, n) if (c[i] == 0) f2 = 0;
		if (f2) {
			cout << fac[n] << '\n';
			return 0;
		}
	}
	DFS(1);
	cout << ans << '\n';
	return 0;
} 
/*
5 5
11111
1 1 4 5 1
*/
