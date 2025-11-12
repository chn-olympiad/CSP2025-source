#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int p[N];
int n, m;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n * m; i ++)scanf("%d", &p[i]);
	int num;
	for(int i = 1; i <= n * m; i ++)
	{
		int maxv = 0, id = -1;
		for(int j = 1; j <= n * m; j ++)
		{
			if(p[j] >= maxv)
			{
				maxv = p[j];
				id = j;
			}
		}
		if(id == 1)
		{
			num = i;
			break;
		}
		p[id] = -1;
	}
	int c = (num % n ? num / n + 1 : num / n);
	int r = (c % 2 ? num % n ? num % n : n : num % n ? n - num % n + 1: 1);
	printf("%d %d", c, r);
	return 0;
}
