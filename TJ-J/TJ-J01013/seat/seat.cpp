#include<cstdio>
#include<algorithm>
int n, m, a[110];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; ++ i) scanf("%d", &a[i]);
	int r = a[1];
	std::sort(&a[1], &a[n * m + 1], cmp);
	int pos = 0;
	for(int i = 1; i <= n * m; ++ i) if(a[i] == r) pos = i;
	int s = (pos + n - 1) / n;
	if(s & 1) printf("%d %d\n", s, (pos % n ? pos % n : n));
	else printf("%d %d\n", s, n - (pos % n ? pos % n : n) + 1);
	return 0;
}

