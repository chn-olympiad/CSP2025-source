#include <bits/stdc++.h>
using namespace std;
//AnXunSiHaiShiJiaDianSiHuoBa.jpg
struct node
{
	int val, x, y;
};

bool cmp (node a, node b)
{
	return a.val > b.val;
}

const int N = 1e2 + 10;

node a[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, ans_val;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i].val;
	}
	ans_val = a[1].val;
	sort(a + 1, a + n * m + 1, cmp);
	int dx = 1, dy = 1, flag = 1;
	for (int i = 1; i <= n * m; i++)
	{
		a[i].x = dx;
		a[i].y = dy;
		if (a[i].val == ans_val)
		{
			cout << a[i].x << " " << a[i].y << "\n";
			return 0;
		}
		dy += flag;
		if (dy == 0 || dy == n + 1)
		{
			dy -= flag;
			flag = -flag;
			dx++;
		}
	}
	return 0;
}
