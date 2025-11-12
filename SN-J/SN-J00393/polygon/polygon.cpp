//准考证号：SN-J00393
//姓名：张益舟 
//学校：西安滨河学校 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5005], ans;
int max_(int x, int y)
{
	int maxn = -1;
	for (int i = x; i <= y; i++) maxn = max(maxn, a[i]);
	return maxn;
}
int sum_(int x, int y)
{
	int sum = 0;
	for (int i = x; i <= y; i++) sum += a[i];
	return sum;
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("poligon.out", "w", stdout);
	scanf("%d", &n);
	int maxn = -1, sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= n - i + 1; j++)
		{
			if (sum_(j, j + i - 1) > 2 * max_(j, j + i - 1)) ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
