#include<bits/stdc++.h>
using namespace std;
int t, n, ans;
bool sta = 1;
struct node
{
	int x, y, z;
}a[100005];
void dfs(int idx, int sx, int sy, int sz, int sum)
{
	if(idx > n)
	{
		ans = max(ans, sum);
		return ;
	}
	dfs(idx + 1, sx, sy, sz, sum);
	if(sx < n / 2)
		dfs(idx + 1, sx + 1, sy, sz, sum + a[idx].x);
	if(sy < n / 2)
		dfs(idx + 1, sx, sy + 1, sz, sum + a[idx].y);
	if(sz < n / 2)
		dfs(idx + 1, sx, sy, sz + 1, sum + a[idx].z);
}
bool cmpa(node xx, node yy)
{
	return xx.x > yy.x;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0)
				sta = 0;
		}
		if(!sta)
		{
			dfs(1, 0, 0, 0, 0);
			cout << ans << '\n';
		}
		else if(sta)
		{
			sort(a + 1, a + n + 1, cmpa);
			for(int i = 1;i <= n / 2;i++)
				ans += a[i].x;
			cout << ans << '\n';
		}
	}
	return 0;
}

