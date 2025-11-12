#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 505;
int n, m;
string s;
int c[N];
int buk[N];
int jc[N];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) (res = res * a % mod) %= mod;
		(a = a * a % mod) %= mod;
		b >>= 1;
	}
	return res % mod;
}
vector<int> ve;
bool vis[N];
int res;
void dfs(int len) {
	if (len >= n) {
		int cnt = 0;
		int sum = 0;
		for (int i = 1; i <= n; i ++ ) {
			int p = ve[i- 1];
			if (c[p] <= cnt) sum += 1;
			if (s[i] == '1') cnt ++ ;
		}
		res += ((n - sum) >= m);
		res %= mod;
		return ;	
	}
	for (int i = 1; i <= n; i ++ ) {
		if (vis[i]) continue;
		vis[i] = 1;
		ve.push_back(i);
		dfs(len + 1);
		vis[i] = 0;
		ve.pop_back();
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> s;
	s = " " + s;
	bool f = 1;
	for (auto i : s) {
		if (i == '0') f = 0; 
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++ ) {
		cin >> c[i];
		buk[c[i]] += 1;
		cnt += (c[i] == 0);
	}
	jc[1] = 1;
	for (int i = 2; i <= n; i ++ ) {
		jc[i] = jc[i - 1] * i % mod;
	}
	if (n <= 10) {
		res = 0;
		dfs(0);
		cout << res << endl;
		return 0;
	}
	f = 1;
	if (f) {
		if (cnt + m > n) {
			cout << 0 << endl;
			return 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			ans += jc[i] % mod; ans %= mod; 
		}
		cout << ans << endl;
		return 0; 
	}
	cout << jc[n] % mod << endl;
	return 0;
}

