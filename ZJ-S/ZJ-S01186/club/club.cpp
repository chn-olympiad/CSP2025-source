#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
int T, n, a[N][5];
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
struct arr{int x, y, z;}ar[N];
bool cmp1(arr l, arr r)
{
	return max(l.y, l.z) - l.x < max(r.y, r.z) - r.x;
}
bool cmp2(arr l, arr r)
{
	return max(l.x, l.z) - l.y < max(r.x, r.z) - r.y;
}
bool cmp3(arr l, arr r)
{
	return max(l.x, l.y) - l.z < max(r.x, r.y) - r.z;
}
inline void solve()
{
	int cnt0 = 0, cnt1 = 0, cnt2 = 0, sum = 0, tot = 0;
	n = read();
	for (register int i = 1;i <= n; i = -~i)
	{
		a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
		int mx = max(a[i][0], max(a[i][1], a[i][2]));
		if (mx == a[i][0]) ++ cnt0;
		else if (mx == a[i][1]) ++ cnt1;
		else ++ cnt2;
		sum += mx;
	}
	if (cnt0 <= n / 2 && cnt1 <= n / 2 && cnt2 <= n / 2)
	{
		cout << sum << "\n";
		return;
	}
	if (cnt0 > n / 2)
	{
		for (register int i = 1;i <= n; i = -~i)
		{
			int mx = max(a[i][0], max(a[i][1], a[i][2]));
			if (mx == a[i][0])
			{
				ar[ ++ tot] = {a[i][0], a[i][1], a[i][2]};
			}
		}
		sort (ar + 1, ar + tot + 1, cmp1);
		for (register int i = tot;i > n / 2; -- i)
		{
			//cout << ar[i].x << "\n";
			sum = sum - ar[i].x + max(ar[i].y, ar[i].z);
		}
		cout << sum << "\n";
	}
	else if (cnt1 > n / 2)
	{
		for (register int i = 1;i <= n; i = -~i)
		{
			int mx = max(a[i][0], max(a[i][1], a[i][2]));
			if (mx == a[i][1])
			{
				ar[ ++ tot] = {a[i][0], a[i][1], a[i][2]};
			}
		}
		sort (ar + 1, ar + tot + 1, cmp2);
		for (register int i = tot;i > n / 2; -- i)
		{
			//cout << ar[i].x << "\n";
			sum = sum - ar[i].y + max(ar[i].x, ar[i].z);
		}
		cout << sum << "\n";
	}
	else
	{
		for (register int i = 1;i <= n; i = -~i)
		{
			int mx = max(a[i][0], max(a[i][1], a[i][2]));
			if (mx == a[i][2])
			{
				ar[ ++ tot] = {a[i][0], a[i][1], a[i][2]};
			}
		}
		sort (ar + 1, ar + tot + 1, cmp3);
		for (register int i = tot;i > n / 2; -- i)
		{
			//cout << ar[i].x << "\n";
			sum = sum - ar[i].z + max(ar[i].x, ar[i].y);
		}
		cout << sum << "\n";
	}
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	//cout << T << "\n";
	while (T --)
	{
		solve();
	}
	return 0;
}
