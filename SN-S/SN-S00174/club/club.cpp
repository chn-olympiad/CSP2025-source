#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
struct xx{
	int a, b, c;
	int qq, ww, ee,q1;
}a[500005];
int cmp(xx a, xx b)
{
	return a.qq > b.qq;
}
int cmp1(xx a, xx b)
{
	return max(a.ww, a.ee) > max(b.ww, b.ee);
}
int cmp2(xx a, xx b)
{
	return a.q1 > b.q1;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(a, 0, sizeof a);
		int ans1 = 0, ans2 = 0, ans3 = 0;
		bool f = 1, f1 = 0;
		for (int i = 1;i <= n;i ++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].b || a[i].c) f = 0;
			if (a[i].c) f1 = 0;
			a[i].q1 = a[i].b-a[i].a;
			a[i].qq = a[i].c+a[i].b - a[i].a;
			a[i].ww = a[i].c - a[i].b;
			a[i].ee = a[i].c - a[i].a;
			ans1 += a[i].a;
		}
		int i = 1;
		sort(a+1, a+1+n, cmp);
		if (f == 1)
		{
			int ans = 0;
			for (int i = 1;i <= n/2;i++)
			{
				ans += a[i].a;
			}
			cout << ans << endl;
			continue;
		}
		if (f1)
		{
			sort(a+1, a+1+n, cmp2);
			int i = 1;
			while (a[i].q1 >= 0)
			{
				if (i >= n/2)
				{
					break;
				}
				ans1 += a[i].q1;
				i++;
			}
			cout << ans1 <<endl;
			continue;
		}
		while (a[i].qq > 0)
		{
			if (i > n/2) break;
			ans1 += a[i].qq;
			i++;
		}
		sort(a+1, a+1+n, cmp1);
		i = 1;
		while (a[i].ww > 0)
		{
			if (i > n/2) break;
			ans1 += a[i].ww;
			i++;
		}
		cout << ans1 << endl;
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

