#include <bits/stdc++.h>
#define ll long long
#define D(x) cout << #x << ": " << x << ' '
#define DE(x) cout << #x << ": " << x << '\n'
using namespace std;
constexpr ll MOD = 998244353;
ll n, m;
ll ans;
string s;
ll c[510];
ll a[510];
bool vis[510];
bool check()
{
	ll sum = 0, cnt = 0;
	for (int i = 1; i <= n && sum < m; i++)
	{
		cnt += s[i] == '0';
		if (s[i] == '1')
		{
			if (cnt < c[a[i]])
				sum++;
			else
				cnt++;
		}
	}
	return sum >= m;
}
void dfs(ll d)
{
	if (d > n)
	{
		(ans += check()) %= MOD;
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			vis[i] = 1;
			a[d] = i;
			dfs(d + 1);
			vis[i] = 0;
			a[d] = 0;
		}
}
int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	bool fagl = 1;
	for (int i = 1; i <= n; i++)
		fagl = (s[i] == '1' ? fagl : 0);
	ll cnt = 0;
	for (int i = 1; i <= n; i++)
		cin >> c[i], cnt += c[i] == 0;
	dfs(1);
	cout << ans << '\n';
	return 0;
}
