#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
struct Club
{
	int d1, d2, d3, diff;
}a[N];

bool cmp(Club x, Club y)
{
	if(x.diff < 0 && y.diff < 0) return x.diff > y.diff;
	return x.diff < y.diff;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t --)
	{
		cin >> n;
		int m = n / 2;
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d %d %d", &a[i].d1, &a[i].d2, &a[i].d3);
			a[i].diff = a[i].d1 - a[i].d2;
		}
		int ans = 0, c1 = 0, c2 = 0, c3 = 0;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i ++)
		{
			if(a[i].diff > 0)
			{
				c1 ++;
				ans += a[i].d1;
			}
			else
			{
				c2 ++;
				ans += a[i].d2;
			}
		}
		if(c1 > m && c2 < m)
			for(int i = 1; i <= c1 - m; i ++)
				ans -= a[i].diff;
		else if(c2 > m && c1 < m)
			for(int i = 1; i <= c2 - m; i ++)
				ans -= a[i].diff;
		cout << ans << endl;
	}
	return 0;
}
