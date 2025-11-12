#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char c[N];
int a[N], l;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c + 1);
	int n = strlen(c + 1);
	for (int i = 1; i <= n; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			a[++l] = c[i] - '0';
		}
	}
	sort(a + 1, a + l + 1);
	for (int i = l; i >= 1; i--)
	{
		printf("%d", a[i]);
	}
	return 0;
}

