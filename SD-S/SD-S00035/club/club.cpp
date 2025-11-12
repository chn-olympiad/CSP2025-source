#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long ans = 0;
int t, n, b1[N], c1[N], d1[N];
int cb = 0, cc = 0, cd = 0;
struct Node
{
	int b, c, d;
}a[N];
int pd(int x)
{
	if (a[x].b >= a[x].c && a[x].b >= a[x].d)
		return 1;
	else if (a[x].c >= a[x].b && a[x].c >= a[x].d)
		return 2;
	else if (a[x].d >= a[x].b && a[x].d >= a[x].c)
		return 3;
	return 0;
}
int pd1(int x, int z)
{
	if (z == 1)
		return a[x].b - max(a[x].c, a[x].d);
	if (z == 2)
		return a[x].c - max(a[x].b, a[x].d);
	if (z == 3)
		return a[x].d - max(a[x].b, a[x].c);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int qq = 1; qq <= t; qq ++)
	{
		ans = 0;
		cb = cc = cd = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].b >> a[i].c >> a[i].d;
		for (int i = 1; i <= n; i++)
		{
			int tot = pd(i);
			if (tot == 1)
			{
				b1[++cb] = i;
				ans += a[i].b;
			}
			else if (tot == 2)
			{
				c1[++cc] = i;
				ans += a[i].c;
			}
			else if (tot == 3)
			{
				d1[++cd] = i;
				ans += a[i].d;
			}
		}
		int q[N] = {0};
		if (cb > n / 2)
		{
			for (int j = 1; j <= cb; j++)
				q[j] = pd1(b1[j], 1);
			sort(q + 1, q + cb + 1);
			for (int j = 1; j <= cb - n/ 2; j++)
			{
				ans -= q[j];
			}	
		}
		if (cc > n / 2)
		{
			for (int j = 1; j <= cc; j++)
				q[j] = pd1(c1[j], 2);
			sort(q + 1, q + cc + 1);
			for (int i = 1; i <= cc - n / 2; i++)
				ans -= q[i];
		}
		if (cd > n / 2)
		{
			for (int j = 1; j <= cd; j++)
				q[j] = pd1(d1[j], 3);
			sort(q + 1, q + cd + 1);
			for (int j = 1; j <= cd - n / 2; j++)
				ans -= q[j];
		}
		cout << ans << endl;
	}
	return 0;
}
