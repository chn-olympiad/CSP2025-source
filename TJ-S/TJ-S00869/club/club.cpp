#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
struct node
{
	int a1, a2, a3, d12, d13, d23;
};
node a[100010];
struct node1
{
	int id, d;
};
node1 b[200010];
int f[100010];
bool flag[100010];
bool cmp(node1 x, node1 y)
{
	return x.d < y.d;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n; 
		cin >> n;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3)
			{
				a[i].d12 = a[i].a1 - a[i].a2;
				a[i].d13 = a[i].a1 - a[i].a3;
				a[i].d23 = (abs)(a[i].a2 - a[i].a3);
				ans += a[i].a1;
				f[i] = 1;
				cnt1++;
			}
			else if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3)
			{
				a[i].d12 = a[i].a2 - a[i].a1;
				a[i].d23 = a[i].a2 - a[i].a3;
				a[i].d13 = (abs)(a[i].a1 - a[i].a3);
				ans += a[i].a2;
				f[i] = 2;
				cnt2++;
			}
			else if (a[i].a3 >= a[i].a1 && a[i].a3 >= a[i].a2)
			{
				a[i].d13 = a[i].a3 - a[i].a1;
				a[i].d23 = a[i].a3 - a[i].a2;
				a[i].d12 = (abs)(a[i].a1 - a[i].a2);
				ans += a[i].a3;
				f[i] = 3;
				cnt3++;
			}
		}
		memset(flag, false, sizeof(flag));
		if (cnt1 > n / 2)
		{
			int cntx = 0;
			for (int i = 1; i <= n; i++)
			{
				if (f[i] == 1)
				{
					cntx++;
					b[cntx] = (node1){i, a[i].d12};
					cntx++;
					b[cntx] = (node1){i, a[i].d13};
				}
			}
			sort(b + 1, b + cntx + 1, cmp);
			int i = 0;
			while (cnt1 > n / 2)
			{
				i++;
				if (!flag[b[i].id])
				{
					flag[b[i].id] = true;
					cnt1--;
					ans -= b[i].d;
				}
			}
		}
		else if (cnt2 > n / 2)
		{
			int cntx = 0;
			for (int i = 1; i <= n; i++)
			{
				if (f[i] == 2)
				{
					cntx++;
					b[cntx] = (node1){i, a[i].d12};
					cntx++;
					b[cntx] = (node1){i, a[i].d23};
				}
			}
			sort(b + 1, b + cntx + 1, cmp);
			int i = 0;
			while (cnt2 > n / 2)
			{
				i++;
				if (!flag[b[i].id])
				{
					flag[b[i].id] = true;
					cnt2--;
					ans -= b[i].d;
				}
			}
		}
		else if (cnt3 > n / 2)
		{
			int cntx = 0;
			for (int i = 1; i <= n; i++)
			{
				if (f[i] == 3)
				{
					cntx++;
					b[cntx] = (node1){i, a[i].d13};
					cntx++;
					b[cntx] = (node1){i, a[i].d23};
				}
			}
			sort(b + 1, b + cntx + 1, cmp);
			int i = 0;
			while (cnt3 > n / 2)
			{
				i++;
				if (!flag[b[i].id])
				{
					flag[b[i].id] = true;
					cnt3--;
					ans -= b[i].d;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
