#include <bits/stdc++.h>
using namespace std;
//16:00 bu hui
struct node
{
	int idx, val;
};
struct rp
{
	int val, i, idx;
};
bool cmp (rp a, rp b)
{
	return a.val < b.val;
}

const int N = 1e5 + 10;

int a[N][3];
long long ans;
node b[N][3]; 
rp c[N * 2], d[N];
bool vis[N];

void solve()
{
	memset(vis, 0, sizeof vis);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		b[i][0].val = max(a[i][0], max(a[i][1], a[i][2]));
		b[i][2].val = min(a[i][0], min(a[i][1], a[i][2]));
		b[i][1].val = (a[i][0] + a[i][1] + a[i][2]) - b[i][0].val - b[i][2].val;
		if (b[i][0].val == a[i][0])
		{
			b[i][0].idx = 0;
		}
		if (b[i][0].val == a[i][1])
		{
			b[i][0].idx = 1;
		}
		if (b[i][0].val == a[i][2])
		{
			b[i][0].idx = 2;
		}
		if (b[i][1].val == a[i][0] && b[i][0].idx != 0)
		{
			b[i][1].idx = 0;
		}
		if (b[i][1].val == a[i][1] && b[i][0].idx != 1)
		{
			b[i][1].idx = 1;
		}
		if (b[i][1].val == a[i][2] && b[i][0].idx != 2)
		{
			b[i][1].idx = 2;
		}
		if (b[i][2].val == a[i][0] && b[i][0].idx != 0 && b[i][1].idx != 0)
		{
			b[i][2].idx = 0;
		}
		if (b[i][2].val == a[i][1] && b[i][0].idx != 1 && b[i][1].idx != 1)
		{
			b[i][2].idx = 1;
		}
		if (b[i][2].val == a[i][2] && b[i][0].idx != 2 && b[i][1].idx != 2)
		{
			b[i][2].idx = 2;
		}
		c[i].val = b[i][0].val - b[i][1].val;
		d[i].val = b[i][0].val - b[i][2].val;
		c[i].i = i;
		d[i].i = i;
		c[i].idx = b[i][1].idx;
		d[i].idx = b[i][2].idx;
	}
	for (int i = 1; i <= n; i++)
	{
		c[i + n].val = d[i].val;
		c[i + n].i = d[i].i;
		c[i + n].idx = d[i].idx;
	}
	sort(c + 1, c + 2 * n + 1, cmp);
	int cnt_1, cnt_2, cnt_3;
	cnt_1 = 0;
	cnt_2 = 0;
	cnt_3 = 0;
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[i][0].idx == 0)
		{
			cnt_1++;
		}
		if (b[i][0].idx == 1)
		{
			cnt_2++;
		}
		if (b[i][0].idx == 2)
		{
			cnt_3++;
		}
		ans += b[i][0].val;
	}
	for (int i = 1; i <= n * 2; i++)
	{
		if (cnt_1 <= n / 2 && cnt_2 <= n / 2 && cnt_3 <= n / 2)
		{
			break;
		}
		if (vis[c[i].i])
		{
			continue;
		}
		if (b[c[i].i][0].idx == 0)
		{
			if (cnt_1 <= n / 2)
			{
				continue;
			}
		}
		if (b[c[i].i][0].idx == 1)
		{
			if (cnt_2 <= n / 2)
			{
				continue;
			}
		}
		if (b[c[i].i][0].idx == 2)
		{
			if (cnt_3 <= n / 2)
			{
				continue;
			}
		}
		if (c[i].idx == 0)
		{
			if (cnt_1 < n / 2)
			{
				cnt_1++;
				if (b[c[i].i][0].idx == 0)
				{
					cnt_1--;
				}
				if (b[c[i].i][0].idx == 1)
				{
					cnt_2--;
				}
				if (b[c[i].i][0].idx == 2)
				{
					cnt_3--;
				}
			}
			else
			{
				continue;
			}
		}
		if (c[i].idx == 1)
		{
			if (cnt_2 < n / 2)
			{
				cnt_2++;
				if (b[c[i].i][0].idx == 0)
				{
					cnt_1--;
				}
				if (b[c[i].i][0].idx == 1)
				{
					cnt_2--;
				}
				if (b[c[i].i][0].idx == 2)
				{
					cnt_3--;
				}
			}
			else
			{
				continue;
			}
		}
		if (c[i].idx == 2)
		{
			if (cnt_3 < n / 2)
			{
				cnt_3++;
				if (b[c[i].i][0].idx == 0)
				{
					cnt_1--;
				}
				if (b[c[i].i][0].idx == 1)
				{
					cnt_2--;
				}
				if (b[c[i].i][0].idx == 2)
				{
					cnt_3--;
				}
			}
			else
			{
				continue;
			}
		}
		ans -= c[i].val;
		vis[c[i].i] = 1;
	}
	cout << ans << "\n";
} 
//ChouBaole Code
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
