//µ­³þÜ²
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 510, mod = 998244353;
int TTT = 1, n, m, ans, p[N], c[N], vis[N];
string s;

int ch()
{
	int res = 0, now = 0;
	for(int i = 1; i <= n; i++)
		if(now >= c[p[i]] || s[i] == '0') now++;
		else res++;
	return (res >= m);
}

void dfs(int x)
{
	if(x > n) {ans = (ans + ch()) % mod; return;}
	for(int i = 1; i <= n; i++)
		if(!vis[i]) p[x] = i, vis[i] = 1, dfs(x + 1), vis[i] = 0;
}

void mian()
{
	cin >> n >> m >> s; s = " " + s;
	int cnt = 0;
	for(int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ans;
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}

