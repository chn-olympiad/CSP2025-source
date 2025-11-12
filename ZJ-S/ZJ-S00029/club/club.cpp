#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
struct node
{
	int x, y, z;
	int cha;
}a[100005];

bool cmp(node q, node p)
{
	return q.cha > p.cha;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			int maxn = max(a[i].x, max(a[i].y, a[i].z));
			int minn = min(a[i].x, min(a[i].y, a[i].z));
			int midd = a[i].x + a[i].y + a[i].z - maxn - minn;
			a[i].cha = maxn - midd;
		}
		sort(a + 1, a + n + 1, cmp);
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int maxn = max(a[i].x, max(a[i].y, a[i].z));
			int minn = min(a[i].x, min(a[i].y, a[i].z));
			int midd = a[i].x + a[i].y + a[i].z - maxn - minn;
			if (maxn == a[i].x)
			{
				if (cnt1 < n / 2)
				{
					cnt1++;
					ans += maxn;
				}
				else
				{
					if (midd == a[i].y)
					{
						cnt2++;
						ans += midd;
					}
					else
					{
						cnt3++;
						ans += midd;
					}
				}
			}
			
			else if (maxn == a[i].y)
			{
				if (cnt2 < n / 2)
				{
					cnt2++;
					ans += maxn;
				}
				else
				{
					if (midd == a[i].x)
					{
						cnt1++;
						ans += midd;
					}
					else
					{
						cnt3++;
						ans += midd;
					}
				}
			}
			
			else
			{
				if (cnt3 < n / 2)
				{
					cnt3++;
					ans += maxn;
				}
				else
				{
					if (midd == a[i].y)
					{
						cnt2++;
						ans += midd;
					}
					else
					{
						cnt1++;
						ans += midd;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
