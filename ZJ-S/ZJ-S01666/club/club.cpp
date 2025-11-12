#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
//int maks[100005];
long long ans;

int read()
{
	int num = 0;
	while (1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ')
		{
			return num;
		}
		num = num * 10 + int(c - '0');
	}
}

void write(int n)
{
	char c[11] = {};
	int len = 0;
	while (n)
	{
		c[++len] = char(n % 10 + '0');
		n /= 10;
	}
	for (int i = len; i >= 1; --i)
	{
		putchar(c[i]);
	}
}

//void dfs(int step, int x, int y, int z, int sum)
//{
//	// 20pts
//	if (step == n)
//	{
//		ans = max(ans, sum);
//		return;
//	}
//	if (x < n / 2)
//	{
//		dfs(step + 1, x + 1, y, z, sum + a[step + 1][1]);
//	}
//	if (y < n / 2)
//	{
//		dfs(step + 1, x, y + 1, z, sum + a[step + 1][2]);
//	}
//	if (z < n / 2)
//	{
//		dfs(step + 1, x, y, z + 1, sum + a[step + 1][3]);
//	}
//}
// O(2^n) shit mountain code L
// silly.

int maks(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
	// 1.4684s
	// This is useless bro lol
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	scanf("%d", &t);
	t = read();
	while (t--)
	{
		// O(t*nlogn)
		ans = 0;
//		scanf("%d", &n);
		n = read();
		int x, y, z;
		long long xs, ys, zs;
		int xm[100005] = {0, };
		int ym[100005] = {0, };
		int zm[100005] = {0, }; // memset
		x = 0;
		y = 0;
		z = 0;
		xs = 0;
		ys = 0;
		zs = 0;
//		memset(xm, 0, sizeof(xm));
//		memset(ym, 0, sizeof(ym));
//		memset(zm, 0, sizeof(zm));
//		memset(a, 0, sizeof(a));
		//O(n)
		
		for (int i = 1; i <= n; ++i)
		{
//			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]); // 1.5s
			a[i][1] = read();
			a[i][2] = read();
			a[i][3] = read(); // 0.6608s??????????????
//			for (int j = 1; j <= 3; ++j)
//			{
////				cin >> a[i][j]; // 2.421s
//				scanf("%d", &a[i][j]); // 1.8064s
//			}
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
			{
				xs += a[i][1];
				xm[++x] = a[i][1] - maks(a[i][2], a[i][3]);
			}
			else if (a[i][2] >= a[i][3])
			{
				ys += a[i][2];
				ym[++y] = a[i][2] - maks(a[i][1], a[i][3]);
			}
			else
			{
				zs += a[i][3];
				zm[++z] = a[i][3] - maks(a[i][1], a[i][2]);
			}
		}
		//O(n)
		
		sort(xm + 1, xm + 1 + x);
		sort(ym + 1, ym + 1 + y);
		sort(zm + 1, zm + 1 + z);
		// O(nlogn)
		
//		cout << x << " " << y << " " << z << endl;
//		cout << xs << " " << ys << " " << zs << endl;
//		for (int i = 1; i <= n; ++i)
//		{
//			cout << xm[i] << " " << ym[i] << " " << zm[i] << endl;
//		}
		ans = xs + ys + zs;
		if (x > n / 2)
		{
			for (int i = 1; i <= x - n / 2; ++i)
			{
				ans -= xm[i];
			}
		}
		else if (y > n / 2)
		{
			for (int i = 1; i <= y - n / 2; ++i)
			{
				ans -= ym[i];
			}
		}
		else if (z > n / 2)
		{
			for (int i = 1; i <= z - n / 2; ++i)
			{
				ans -= zm[i];
			}
		}
		// O(1)
		
//		dfs(0, 0, 0, 0, 0);
//		cout << ans << endl;
//		printf("%d\n", ans);
		write(ans);
		putchar('\n');
//		cout << endl;
	}
	return 0;
}
// Input:
// 3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
//
// Output:
// 18
// 4
// 13
