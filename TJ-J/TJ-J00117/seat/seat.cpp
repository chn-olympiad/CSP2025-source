#include <bits/stdc++.h>
using namespace std;

int n, m, num = 0, c, r, cnt;
int a[110];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	cnt = n * m;
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > a[1])
		{
			num++;
		}
	}
	
	c = num / n + 1;

	int tmp = 2 * n;
	r = (num % tmp < n) ? (num % tmp + 1) : (tmp - num);
	
	printf("%d %d", c, r);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
