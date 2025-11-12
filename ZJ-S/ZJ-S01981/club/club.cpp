#include <bits/stdc++.h>
#define ll long long
#define D(x) cout << #x << ": " << x << ' '
#define DE(x) cout << #x << ": " << x << '\n'
using namespace std;
ll T;
ll n;
ll cnt[6];
ll a[110000][6];
vector<ll> t[6];
priority_queue<ll, vector<ll>, greater<ll>> q;
int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (cin >> T; T--; )
	{
		cin >> n;
		while (q.size())
			q.pop();
		for (int i = 1; i <= 3; i++)
			cnt[i] = 0, t[i].clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ll mxx = max({a[i][1], a[i][2], a[i][3]});
			if (mxx == a[i][1])
				cnt[1]++, t[1].push_back(i);
			else if (mxx == a[i][2])
				cnt[2]++, t[2].push_back(i);
			else if (mxx == a[i][3])
				cnt[3]++, t[3].push_back(i);
			ans += mxx;
		}
		for (int i = 1; i <= 3; i++)
			if (cnt[i] > n / 2)
			{
				ll k = cnt[i] - n / 2;
				for (auto x : t[i])
				{
					ll mxx = max({a[x][1], a[x][2], a[x][3]}), mnn = min({a[x][1], a[x][2], a[x][3]}), mxn = 0;
					ll sum = 0;
					for (int j = 1; j <= 3; j++)
					{
						sum += mxx == a[x][j];
						if (a[x][j] != mxx && a[x][j] != mnn)
							mxn = a[x][j];
					}
					if (sum > 1)
						q.push(0);
					else
						q.push(mxx - mxn);
				}
				while (k)
				{
					k--;
					ans -= q.top();
					q.pop();
				}
				break;
			}
		cout << ans << '\n';
	}
	return 0;
}
