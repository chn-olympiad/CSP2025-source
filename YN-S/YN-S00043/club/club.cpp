#include<bits/stdc++.h>
int n, val[5], sum[5], ans;

struct stu
{
	int mx, cha, to;
	bool operator<(const stu &b)const
	{
		return this->cha > b.cha;
	}
} a[100100];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ans = n = 0;
		sum[0] = sum[1] = sum[2] = sum[3] = sum[4] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &val[1], &val[2], &val[3]);
			if (val[1] >= val[2] && val[1] >= val[3])
			{
				a[i].mx = val[1];
				a[i].to = 1;
				a[i].cha = a[i].mx - std::max(val[2], val[3]);
				continue;
			}
			if (val[2] >= val[1] && val[2] >= val[3])
			{
				a[i].mx = val[2];
				a[i].to = 2;
				a[i].cha = a[i].mx - std::max(val[1], val[3]);
				continue;
			}
			if (val[3] >= val[1] && val[3] >= val[2])
			{
				a[i].mx = val[3];
				a[i].to = 3;
				a[i].cha = a[i].mx - std::max(val[2], val[1]);
				continue;
			}
		}
		std::sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++)
		{
			if (sum[a[i].to] + sum[a[i].to] + 2 <= n)
			{
				ans += a[i].mx;
				sum[a[i].to]++;
			}
			else
			{
				ans += a[i].mx - a[i].cha;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
