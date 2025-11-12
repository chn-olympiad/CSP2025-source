#include <bits/stdc++.h>
using namespace std;
struct node
{
	int a1, a2, a3;
}a[110000];
int T;
int n;
bool cmp1(node x, node y)
{
	return (x.a1 - max(x.a2, x.a3)) < (y.a1 - max(y.a2, y.a3));
}
bool cmp2(node x, node y)
{
	return (x.a2 - max(x.a1, x.a3)) < (y.a2 - max(y.a1, y.a3));
}
bool cmp3(node x, node y)
{
	return (x.a3 - max(x.a2, x.a1)) < (y.a3 - max(y.a2, y.a1));
}
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
	    cin >> n;
		node c1[110000], c2[110000], c3[110000];
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3)
				c1[++cnt1] = a[i];
			else
			{
				if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3)
					c2[++cnt2] = a[i];
				else
					if (a[i].a3 >= a[i].a1 && a[i].a3 >= a[i].a2)
						c3[++cnt3] = a[i];
			}
		}
		sort(c1 + 1, c1 + cnt1 + 1, cmp1);
		sort(c2 + 1, c2 + cnt2 + 1, cmp2);
		sort(c3 + 1, c3 + cnt3 + 1, cmp3);
		if (cnt1 > n / 2)
		{
			int tiao = cnt1 - n / 2;
			for (int i = 1; i <= tiao; i++)
			{
				if (c1[i].a1 - c1[i].a2 >= c1[i].a1 - c1[i].a3)
				{
					c3[++cnt3] = c1[i];
					c1[i].a1 = c1[i].a2 = c1[i].a3 = 0;
				}
				else
				{
					c2[++cnt2] = c1[i];
					c1[i].a1 = c1[i].a2 = c1[i].a3 = 0;
				}
			}
		}
		else
		if (cnt2 > n / 2)
		{
			int tiao = cnt2 - n / 2;
			for (int i = 1; i <= tiao; i++)
			{
				if (c2[i].a2 - c2[i].a1 >= c2[i].a2 - c2[i].a3)
				{
					c3[++cnt3] = c2[i];
					c2[i].a1 = c2[i].a2 = c2[i].a3 = 0;
				}
				else
				{
					c1[++cnt1] = c2[i];
					c2[i].a1 = c2[i].a2 = c2[i].a3 = 0;
				}
			}
		}
		else
		if (cnt3 > n / 2)
		{
			int tiao = cnt3 - n / 2;
			for (int i = 1; i <= tiao; i++)
			{
				if (c3[i].a3 - c3[i].a1 >= c3[i].a3 - c3[i].a2)
				{
					c2[++cnt2] = c3[i];
					c3[i].a1 = c3[i].a2 = c3[i].a3 = 0;
				}
				else
				{
					c1[++cnt1] = c3[i];
					c3[i].a1 = c3[i].a2 = c3[i].a3 = 0;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= cnt1; i++)
		{
			ans += c1[i].a1;
			//cout << c1[i].a1 << " " << c1[i].a2 << " " << c1[i].a3 << endl;
        }
        //cout << "---" << endl;
		for (int i = 1; i <= cnt2; i++)
        {
			ans += c2[i].a2;
			//cout << c2[i].a1 << " " << c2[i].a2 << " " << c2[i].a3 << endl;
        }
        //cout << "---" << endl;
		for (int i = 1; i <= cnt3; i++)
        {
			ans += c3[i].a3;
			//cout << c3[i].a1 << " " << c3[i].a2 << " " << c3[i].a3 << endl;
        }
        cout << ans << endl;
	}

	return 0;
}
