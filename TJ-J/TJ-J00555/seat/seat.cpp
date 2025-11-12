#include <bits/stdc++.h>
using namespace std;

namespace p1
{
	const int MAXN = 110;
	int n, m, a1, a[MAXN], p, x, y;
	void solve()
	{
		scanf("%d%d", &n, &m);
		int tots = m * n;
		for(int i = 1; i <= tots; i++) scanf("%d", &a[i]);
		a1 = a[1];
		sort(a + 1, a + 1 + tots, greater<int>());
		for(int i = 1; i <= tots; i++)
		{
			if(a[i] == a1)
			{
				p = i;
				break;
			}
		}
		x = ((p - 1) / n + 1);
		y = (p - 1) % n;
		if(x & 1) y = 1 + y;
		else y = n - y;
		printf("%d %d", x, y);
	}
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	p1::solve();
	return 0; 
} 
