#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a, b, t = 0;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%d", &a);
	for (int i = 2; i <= n * m; i++)
	{
		scanf("%d", &b);
		if (b > a)
		{
			t++;
		}
	}
	a = t / n + 1;
	b = t % n + 1;
	printf("%d %d", a, (a % 2) ? b : n - b + 1);
	return 0;
}

