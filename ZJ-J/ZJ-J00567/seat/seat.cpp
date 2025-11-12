#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, t, ans = 0;
	scanf("%d%d", &n, &m);
	scanf("%d", &t);
	for(int i = 2; i <= n * m; i++)
	{
		int x;
		scanf("%d", &x);
		if(x > t)ans++;
	}
	int a = 1, b = 1;
	bool f = 1;
	while(ans != 0)
	{
		if(ans >= n)
		{
			if(a == 1)a = n;
			else a = 1;
			b++;
			f = !f;
			ans -= n;
		}
		else
		{
			if(f)a += ans;
			else a = a - ans;
			ans = 0;
		}
	}
	printf("%d %d", b, a);
	return 0;
}
