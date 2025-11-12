#include <bits/stdc++.h>
using namespace std;

int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x*f;
}
void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return;
}

int n, q;

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	n=read(), q = read();
	for (int i = 1; i <= q; i++) printf("0\n");

	return 0;
}