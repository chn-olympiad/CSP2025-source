#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 101
using namespace std;
struct node
{
	int val;
	bool flag;
} a[MAXN];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i].val);
	a[1].flag = true;
	sort(a + 1, a + n * m + 1, [](node x, node y){return x.val > y.val;});
	int x = 1, y = 1, offset = 1;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i].flag)
		{
			printf("%d %d\n", y, x);
			break;
		}
		x += offset;
		if (x < 1 || x > n)
		{
			offset *= -1;
			x += offset;
			y++;
		}
	}
	return 0;
}