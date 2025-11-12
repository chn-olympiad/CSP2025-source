#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
	int x, y, z;
}a[100010];
long long T, n, cnt1, cnt2, cnt3, ans;
bool ifa = true, ifb = true;

inline bool cmpa(Node x, Node y)
{
	return x.x >= y.x;
}
inline bool cmpb(Node x, Node y)
{
	int xx = max(x.x, x.y) - min(x.x, x.y);
	int yy = max(y.x, y.y) - min(y.x, y.y);
	if (xx != yy)
	{
		return xx > yy;
	}
	else
	{
		return max(x.x, x.y) > min(x.x, x.y);
	}
}
inline bool cmp100(Node x, Node y)
{
	int xmax = max(x.x, max(x.y, x.z));
	int xmin = min(x.x, min(x.y, x.z));
	int xmid, ymid;
	if (xmax == x.x)
	{
		if (xmin == x.y)
		{
			xmid = x.z;
		}
		else
		{
			xmid = x.y;
		}
	}
	else if (xmax == x.y)
	{
		if (xmin == x.x)
		{
			xmid = x.z;
		}
		else
		{
			xmid = x.x;
		}
	}
	else
	{
		if (xmin == x.x)
		{
			xmid = x.y;
		}
		else
		{
			xmid = x.x;
		}
	}
	int ymax = max(y.x, max(y.y, y.z));
	int ymin = min(y.x, min(y.y, y.z));
	if (ymax == y.x)
	{
		if (ymin == y.y)
		{
			ymid = y.z;
		}
		else
		{
			ymid = y.y;
		}
	}
	else if (ymax == y.y)
	{
		if (ymin == y.x)
		{
			ymid = y.z;
		}
		else
		{
			ymid = y.x;
		}
	}
	else
	{
		if (ymin == y.x)
		{
			ymid = y.y;
		}
		else
		{
			ymid = y.x;
		}
	}
	if (xmax - xmid != ymax - ymid)
	{
		return xmax - xmid > ymax - ymid;
	}
	else
	{
		return xmid - xmin > ymid - ymin;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (int ii = 1; ii <= T; ii++)
	{
		//input
		cin >> n;
		int tn = n / 2;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			if (a[i].y != 0)
			{
				ifa = false;
			}
			if (a[i].z != 0)
			{
				ifb = false;
			}
		}
		
		//differentAB
		if (ifa == true && ifb == true)
		{
			sort(a + 1, a + n + 1, cmpa);
			for (int i = 1; i <= tn; i++)
			{
				ans += a[i].x;
			}
			cout << ans;
		}
		else if (ifb == true)
		{
			sort(a + 1, a + n + 1, cmpb);
			for (int i = 1; i <= n; i++)
			{
				if (cnt1 >= tn)
				{
					ans += a[i].y;
				}
				else if (cnt2 >= tn)
				{
					ans += a[i].x;
				}
				else
				{
					if (a[i].x >= a[i].y)
					{
						ans += a[i].x;
						cnt1++;
					}
					else
					{
						ans += a[i].y;
						cnt2++;
					}
				}
			}
			cout << ans;
		}
		else
		{
			sort(a + 1, a + n + 1, cmp100);
			for (int i = 1; i <= n; i++)
			{
				int amx = max(a[i].x, max(a[i].y, a[i].z));
				if (cnt1 >= tn)
				{
					if (a[i].y >= a[i].z)
					{
						ans += a[i].y;
					}
					else
					{
						ans += a[i].z;
					}
				}
				else if (cnt2 >= tn)
				{
					if (a[i].x >= a[i].z)
					{
						ans += a[i].x;
					}
					else
					{
						ans += a[i].z;
					}
				}
				else if (cnt3 >= tn)
				{
					if (a[i].x >= a[i].y)
					{
						ans += a[i].x;
					}
					else
					{
						ans += a[i].y;
					}
				}
				else
				{
					if (a[i].x == amx)
					{
						ans += a[i].x;
						cnt1++;
					}
					else if (a[i].y == amx)
					{
						ans += a[i].y;
						cnt2++;
					}
					else
					{
						ans += a[i].z;
						cnt3++;
					}
				}
			}
			cout << ans;
		}
		cout << endl;
		//reset
		ans = cnt1 = cnt2 = cnt3 = 0;
		ifa = ifb = true;
	}
	return 0;
}
