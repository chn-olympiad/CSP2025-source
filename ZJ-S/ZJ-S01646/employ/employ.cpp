#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
char s[N];
int c[N];
bool st[N];
int ans;

void dfs(int u, int cnt)
{
	int t = 0;
	for (int i = 1; i <= n; i ++ )
		if (!st[i] && cnt >= c[i])
			t ++ ;
	if (u - 1 - cnt + n - u + 1 -t < m) return;
	
	if (u > n)
	{
		ans ++ ;
		return;
	}
	for (int i = 1; i <= n; i ++ )
		if (!st[i])
		{
			st[i] = true;
			dfs(u + 1, cnt + (!(s[u] - '0') || (cnt >= c[i])));
			st[i] = false;
		}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
	
	dfs(1, 0);
	
	printf("%d\n", ans);
		
	return 0;
}
