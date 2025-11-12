#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10, M = 5e6 + 10;
int n, m;
string s[3][N];
string ss, tt;
int st[M], ls;
int pre[N], suf[N], hsh[N];
int p = 10037, mod = 1e8 + 9;
int b[N << 2], lb;
int cnt, rot[N << 2], rt[N << 2];
int ch[M][30], dh[M][30], dfn[M << 1];
int a[N << 2];
vector <int> id[M << 1];
int gethash()
{
	ll res = 1;
	for (int i = 1; i <= ls; i ++) st[i] += 50;
	for (int i = 1; i <= ls; i ++)
	{
		res = res * p + st[i];
		res %= mod;
	}
	res = (res + mod) % mod;
	b[++ lb] = res;
	return res;
}
void pret()
{
	for (int i = 1; i <= n; i ++)
	{
		if (!hsh[i]) continue;
		int now = rot[hsh[i]];
		if (!now) now = rot[hsh[i]] = ++ cnt;
		int nn = s[1][i].size();
		for (int j = pre[i] - 1; j >= 0; j --)
		{
			int c = s[1][i][j] - 'a' + 1;
			if (!ch[now][c]) ch[now][c] = ++ cnt;
			now = ch[now][c];
		}
		if (now) id[now].push_back(i);
		now = rt[hsh[i]];
		if (!now) now = rt[hsh[i]] = ++ cnt;
		for (int j = nn - suf[i]; j < nn; j ++)
		{
			int c = s[1][i][j] - 'a' + 1;
			if (!dh[now][c]) dh[now][c] = ++ cnt;
			now = dh[now][c];
		}
		if (now) id[now].push_back(i);
		if (pre[i] == 0 && suf[i] == 0)
		{
			//cout << "qwq " << i << ' ' << hsh[i] << '\n';
			a[hsh[i]] ++;
		}
	}
}
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[1][i] >> s[2][i];
		int nn = s[1][i].size();
		for (int j = 0; j < nn; j ++) 
		{
			if (s[1][i][j] == s[2][i][j]) pre[i] ++;
			else break;
		}
		for (int j = nn - 1; j >= 0; j --)
		{
			if (s[1][i][j] == s[2][i][j]) suf[i] ++;
			else break;
		}
		if (pre[i] == nn) continue;//
		ls = 0;
		for (int j = pre[i]; j <= nn - 1 - suf[i]; j ++)
		{
			st[++ ls] = (s[2][i][j] - s[1][i][j]) * (int)(s[1][i][j]);
		}
		hsh[i] = gethash();
	}
	b[++ lb] = 1000000000;
	sort(b + 1, b + 1 + lb);
	lb = unique(b + 1, b + 1 + lb) - b - 1;
	for (int i = 1; i <= n; i ++)
	{
		if (!hsh[i]) continue;
		hsh[i] = lower_bound(b + 1, b + 1 + lb, hsh[i]) - b;
	}
	pret();
	for (int i = 1; i <= m; i ++)
	{
		cin >> ss >> tt;
		int pr = 0, su = 0;
		int nn = ss.size();
		for (int j = 0; j < nn; j ++)
		{
			if (ss[j] == tt[j]) pr ++;
			else break;
		}
		for (int j = nn - 1; j >= 0; j --)
		{
			if (ss[j] == tt[j]) su ++;
			else break;
		}
		ls = 0;
		for (int j = pr; j <= nn - 1 - su; j ++)
		{
			st[++ ls] = (tt[j] - ss[j]) * (int)(ss[j]);
		}
		int hh = gethash();
		int h = lower_bound(b + 1, b + 1 + lb, hh) - b;
		if (b[h] != hh) { cout << 0 << '\n'; continue; }
		//cout << h << '\n';
		int now = rot[h];
		int ans = 0;
		for (int j = pr - 1; j >= 0; j --)
		{
			int c = ss[j] - 'a' + 1;
			now = ch[now][c];
			for (int v : id[now])
			{
				if (suf[v] == 0) ans ++;
				dfn[v] = i;
			}
		}
		now = rt[h];
		for (int j = nn - su; j < nn; j ++)
		{
			int c = ss[j] - 'a' + 1;
			now = dh[now][c];
			for (int v : id[now])
			{
				if (pre[v] == 0) ans ++;
				else if (dfn[v] == i) ans ++;
			}
		}
		ans += a[h];
		cout << ans << '\n';
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	int T = 1;
	while (T --) solve();
	return 0;
}

