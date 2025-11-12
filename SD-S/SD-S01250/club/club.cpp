#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int T;
struct node
{
	int a, b, c;
	int x;
} w[N];
int c[5];
int t[N];
int tp;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T --)
	{
		c[0] = 0, c[1] = 0, c[2] = 0;
		tp = 0;
		
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].c);
		for (int i = 1; i <= n; i ++)
		{
			if (w[i].a >= w[i].b && w[i].a >= w[i].c)
				w[i].x = 0, c[0] ++;
			else if (w[i].b >= w[i].a && w[i].b >= w[i].c)
				w[i].x = 1, c[1] ++;
			else if (w[i].c >= w[i].b && w[i].c >= w[i].a)
				w[i].x = 2, c[2] ++;
		}
		
		int m = 0, id = 0;
		for (int i = 0; i < 3; i ++)
			if (c[i] > m) m = c[i], id = i;
		long long res = 0;
		for (int i = 1; i <= n; i ++)
			res += max(max(w[i].a, w[i].b), w[i].c);
			
		for (int i = 1; i <= n; i ++)
			if (w[i].x == id)
			{
				if (id == 0) t[++ tp] = -max(w[i].b, w[i].c) + w[i].a;
				if (id == 1) t[++ tp] = -max(w[i].a, w[i].c) + w[i].b;
				if (id == 2) t[++ tp] = -max(w[i].b, w[i].a) + w[i].c;
			}
		sort(t + 1, t + tp + 1);
		for (int i = 1; i <= tp - n / 2; i ++) 
			res -= t[i];
		printf("%lld\n", res);
	}
	
	return 0;
}
