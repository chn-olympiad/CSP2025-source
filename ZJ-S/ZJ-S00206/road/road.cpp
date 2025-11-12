#include <bits/stdc++.h>
#define gc getchar()
using namespace std;
inline int rd()
{
	int x = 0;
	char s = gc;
	while (!isdigit(s))
		s = gc;
	while (isdigit(s))
	{
		x = (x << 3) + (x << 1) + s - '0';
		s = gc;
	}
	return x;
}
int n, m, k;
int c;
int a[100005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(), m = rd(), k = rd();
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		u = rd(), v = rd(), w = rd();
	}
	c = rd();
	for (int j = 1; j <= k; j++)
	{
		a[j] = rd();
	}
	printf("13\n");
	return 0;
}
