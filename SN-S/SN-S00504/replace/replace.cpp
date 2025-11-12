//xianshitieyizhongxue wangzhengqinghe 13891989834 chusan
#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000010
#define infll 1000000000000000010ll
#define st 29
#define mod 1000000007
#define maxn 5000000
using namespace std;
int aqx, n, q, tot, L[maxn + 10], P[maxn + 10], Q[maxn + 10], PW[maxn + 10];
vector<int> v;
map<pair<int, int>, int> mp;
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	PW[0] = 1;
	for (int i = 1;i <= maxn;i++) PW[i] = 1ll * PW[i - 1] * st % mod; 
	return;
}
void solve()
{
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		string s, t; cin >> s >> t;
		int x = 0, y = 0;
		for (char i:s) x = (1ll * x * st + i - 'a' + 1) % mod;
		for (char i:t) y = (1ll * y * st + i - 'a' + 1) % mod;
		mp[make_pair(x, y)]++; L[++tot] = s.size();
	}
	sort(L + 1, L + tot + 1); tot = unique(L + 1, L + tot + 1) - L - 1; reverse(L + 1, L + tot + 1);
	while (q--)
	{
		string s, t; cin >> s >> t; int k = s.size(); s = "0" + s; t = "0" + t;
		if (s.size() != t.size()) {cout << "0\n"; continue;}
		int l = 0, r = 0;
		for (int i = 1;i <= k;i++)
		{
			P[i] = (1ll * P[i - 1] * st + s[i] - 'a' + 1) % mod;
			Q[i] = (1ll * Q[i - 1] * st + t[i] - 'a' + 1) % mod;
		}
		for (int i = 1;i <= k;i++) if (s[i] != t[i]) {l = i; break;}
		for (int i = k;i >= 1;i--) if (s[i] != t[i]) {r = i; break;}
		ll ans = 0;
		for (int i = 1;i <= l;i++)
		{
			for (int j = 1;j <= tot;j++)
			{
				if (i + L[j] - 1 < r) break;
				if (i + L[j] - 1 > k) continue;
				int x = (P[i + L[j] - 1] + 1ll * (mod - P[i - 1]) * PW[L[j]]) % mod;
				int y = (Q[i + L[j] - 1] + 1ll * (mod - Q[i - 1]) * PW[L[j]]) % mod;
				ans += mp[make_pair(x, y)];
			}
		}
		cout << ans << "\n";
	}
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) solve();
	return 0;
}
