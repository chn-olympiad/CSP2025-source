#include <bits/stdc++.h>

using namespace std;

int t, n, x, y, z, ans;

struct mr
{
	int a, b, c;
}m[100005];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		ans = 0;
		x = 0;
		y = 0;
		z = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> m[i].a >> m[i].b >> m[i].c; 
			if (m[i].a > m[i].b and m[i].a > m[i].c)
			{
				if (x < n / 2)
				{
					ans += m[i].a;
					x++;
				} 
				else if (m[i].c > m[i].b and z < n / 2)
				{
					ans += m[i].c;
					z++;
				} 
				else if (m[i].b > m[i].c and y < n / 2)
				{
					ans += m[i].b;
					y++;
				} 
			}
			if (m[i].b > m[i].a and m[i].b > m[i].c)
			{
				if (y < n / 2)
				{
					ans += m[i].b;
					y++;
				}
				else if (m[i].c > m[i].a and z < n / 2)
				{
					ans += m[i].c;
					z++;
				} 
				else if (m[i].a > m[i].c and x < n / 2)
				{
					ans += m[i].a;
					x++;
				} 
			}
			if (m[i].c > m[i].b and m[i].c > m[i].a)
			{
				if (z < n / 2) 
				{
					ans += m[i].c;
					z++;
				}
				else if (m[i].a > m[i].b and x < n / 2) 
				{
					ans += m[i].a;
					x++;
				}
				else if (m[i].b > m[i].a and y < n / 2) 
				{
					ans += m[i].b;
					y++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
