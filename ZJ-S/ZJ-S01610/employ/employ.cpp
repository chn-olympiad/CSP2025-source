#include <bits/stdc++.h>
using namespace std;
char f[15];
int n, m, pr[15], c[15], ans;
bitset<15> v, w;

bool check()
{
	int cnt = 0, fnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] && fnt < c[pr[i]])
		{
			cnt++;
		}
		else
		{
			fnt++;
		}
	}
	return cnt >= m;
}

void DFS(int dept)
{
	if (dept == n)
	{
		if (check())
		{
			ans++;
		}
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!w[i])
		{
			w[i] = 1;
			pr[dept + 1] = i;
			DFS(dept + 1);
			w[i] = 0;
		}
	}
	return ;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d\n%s", &n, &m, f);
	if (n > 10)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		v[i] = f[i - 1] - '0';
		scanf("%d", &c[i]);
	}
	DFS(0);
	printf("%d\n", ans);
	return 0;
}
