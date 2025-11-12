#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 510;
char ch[N];
int c[N];
typedef long long ll;
const ll mod = 998244353;
ll f[(1 << 20) + 10][30];
inline void mdf(ll &A, ll B) { A = (A + B) % mod; }
int n, m;
vector<int> lim;
inline void work1()
{
	sort(c + 1, c + n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (c[j] < i || ch[i] == '0') continue;
			lim.clear();
			for (int t = 1; t < i; t++)
				if (ch[t] == '1') lim.emplace_back(t); // < t
			int pos = 1, cnt = 0;
			bool flag = false;
			ll mul = 1;
			for (int t : lim)
			{
				while (pos <= n && c[pos] < t) 
				{
					pos++;
					if (pos == j) flag = true, pos++, cnt++;
				}
				pos--;
				if (pos == j) pos--, cnt--, flag = false;
				if (pos <= cnt) 
				{
					mul = 0;
					break;
				}
				mul = mul * (pos - cnt) % mod, cnt++;
			}
			for (int t = n - cnt - (!flag); t >= 1; t--) mul = mul * t % mod;
			ans = (ans + mul) % mod;
		}
	cout << ans << "\n";
	exit(0);
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> ch[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (m == n)
	{
		bool flag1 = true, flag2 = true;
		ll ans = 1;
		for (int i = 1; i <= n; i++) flag1 &= (ch[i] == '1'), flag2 &= (c[i] > 0), ans = ans * i % mod;
		if (flag1 && flag2) cout << ans << "\n";
		else cout << "0\n";
		return 0;
	} 
	if (m == 1) work1();
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int S = 0; S < (1 << n); S++)
		{
			if (__builtin_popcount(S) != i - 1) continue;
			for (int j = 0; j < i; j++)
				for (int now = 1; now <= n; now++)
				{
					if (S & (1 << now - 1)) continue;
					mdf(f[S | (1 << now - 1)][j + (ch[i] == '0' || c[now] <= j)], f[S][j]);
				}
		}
	ll ans = 0;
	for (int i = 1; i + m <= n; i++)
		mdf(ans, f[(1 << n) - 1][i]);
	cout << ans << "\n";
	return 0;
}

