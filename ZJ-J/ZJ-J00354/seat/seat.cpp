#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[105];
bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n * m; ++i)
	{
		scanf("%d", &a[i]);
	}
	int s = a[1], id;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; ++i)
	{
		if (a[i] == s)
		{
			id = i;
			break;
		}
	}
	int c, r;
	if (id % n == 0) c = id / n;
	else c = id / n + 1;
	if (c % 2 == 1) r = id % n;
	else r = n - id % n + 1;
	if (c % 2 == 1 && id % n == 0) r = n;
	if (c % 2 == 0 && id % n == 0) r = 1;
	printf("%d %d", c, r);
	return 0;
}
