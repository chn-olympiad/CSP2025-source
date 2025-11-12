#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
struct node
{
	pair<ll, ll> a[4];
} a[maxn];
bool operator<(node lhs, node rhs)
{
	return lhs.a[1].first - lhs.a[2].first > rhs.a[1].first - rhs.a[2].first;
}
ll t, n, ans, sumx[maxn];
void dfs(ll id, ll cur, ll cnta, ll cntb, ll cntc)
{
	if (cur + sumx[n] - sumx[id - 1] <= ans)
	{
		return;
	}
	if (id > n)
	{
		ans = cur;
		return;
	}
	if (cnta < n / 2)
	{
		dfs(id + 1, cur + a[id].a[1].first, cnta + 1, cntb, cntc);
	}
	if (cntb < n / 2)
	{
		dfs(id + 1, cur + a[id].a[2].first, cnta, cntb + 1, cntc);
	}
	if (cntc < n / 2)
	{
		dfs(id + 1, cur + a[id].a[3].first, cnta, cntb, cntc + 1);
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (ll i = 1; i <= n; i++)
		{
			cin >> a[i].a[1].first >> a[i].a[2].first >> a[i].a[3].first;
			sumx[i] = sumx[i - 1] + max(max(a[i].a[1].first, a[i].a[2].first), a[i].a[3].first);
		}
		ans = 0;
		if (n <= 10)
		{
			dfs(1, 0, 0, 0, 0);
			cout << ans << '\n';
			continue;
		}
		for (ll i = 1; i <= n; i++)
		{
			a[i].a[1].second = 1;
			a[i].a[2].second = 2;
			a[i].a[3].second = 3;
			sort(a[i].a + 1, a[i].a + 4, greater<pair<ll, ll>>());
		}
		sort(a + 1, a + 1 + n);
		ll cnt[4];
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j < 4; j++)
			{
				if (cnt[a[i].a[j].second] < n / 2)
				{
					cnt[a[i].a[j].second]++;
					ans += a[i].a[j].first;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}