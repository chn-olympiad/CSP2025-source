#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, ll> pair;
const ll N = 1e5 + 5;
struct node { ll a, bel; } tmp[4];
ll n, t, ans, boc[4];
bool cmp(node a, node b) { return a.a > b.a; } 
std::priority_queue<pair, std::vector<pair>, std::greater<pair>> q[4];
ll get(node a)
{
	if (boc[a.bel] == n / 2) return a.a - q[a.bel].top().first;
	else return a.a;
}
int main()
{
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		for (ll i = 1; i <= 3; i++)
		{
			while (!q[i].empty())
				q[i].pop();
		}
		ans = boc[1] = boc[2] = boc[3] = 0;
		for (ll i = 1, a, b, c; i <= n; i++)
		{
			std::cin >> a >> b >> c;
			tmp[1] = {a, 1}, tmp[2] = {b, 2}, tmp[3] = {c, 3};
			std::sort(tmp + 1, tmp + 4, cmp);
			if (get(tmp[1]) > get(tmp[2]))
			{
				ans += get(tmp[1]);
				if (boc[tmp[1].bel] == n / 2)
				{
					q[q[tmp[1].bel].top().second].push({114514, 1919810});
					boc[tmp[2].bel]++, boc[tmp[1].bel]--;
					q[tmp[1].bel].pop();
				}
				boc[tmp[1].bel]++;
				q[tmp[1].bel].push({tmp[1].a - tmp[2].a, tmp[2].bel});
			}
			else 
			{
				boc[tmp[2].bel]++;
				ans += get(tmp[2]);
				q[tmp[2].bel].push({114514, 1919810});	
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}
