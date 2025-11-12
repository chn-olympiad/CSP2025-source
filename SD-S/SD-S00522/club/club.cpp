#include <bits/stdc++.h> //30 pts
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 5;
int t, n, cnt_1;
ll ans;
struct node
{
	ll a_1, a_2, a_3, dlt;
	int flag;
} p[maxN];
void dfs(int x, int a1n, int a2n, int a3n, ll sum)
{
	if (x > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (a1n < n / 2) { dfs(x + 1, a1n + 1, a2n, a3n, sum + p[x].a_1); }
	if (a2n < n / 2) { dfs(x + 1, a1n, a2n + 1, a3n, sum + p[x].a_2); }
	if (a3n < n / 2) { dfs(x + 1, a1n, a2n, a3n + 1, sum + p[x].a_3); }
}
bool cmp(node a, node b)
{
	return a.a_2 - a.a_1 > b.a_2 - b.a_1;
}
bool cmp2(node a, node b)
{
	return a.dlt > b.dlt;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld %lld %lld", &p[i].a_1, &p[i].a_2, &p[i].a_3);
		}
		if (n <= 10) { dfs(1, 0, 0, 0, 0); }
		else
		{
			cnt_1 = n;
			for (int i = 1; i <= n; i++)
			{
				ans += p[i].a_1;
				p[i].flag = 1;
				p[i].dlt = p[i].a_3 - p[i].a_1;
			}
			sort(p + 1, p + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
			{
				ans += (p[i].a_2 - p[i].a_1);
				p[i].flag = 2;
				p[i].dlt = p[i].a_3 - p[i].a_2;
			}
			sort(p + 1, p + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i++)
			{
				if (p[i].dlt <= 0) { break; }
				p[i].flag = 3;
				ans += p[i].dlt;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
