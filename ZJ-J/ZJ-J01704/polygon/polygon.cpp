#include<bits/stdc++.h>
using namespace std;

const int N = 5010, MOD = 998244353;
int len[N];
int n;
int cnt;

void dfs(int i, int maxv, int sum)
{
	if(i == n + 1)
	{
		if(sum > maxv * 2) cnt = (cnt + 1) % MOD;
		return;
	}
	dfs(i + 1, len[i], sum + len[i]);
	dfs(i + 1, maxv, sum);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &len[i]);
	sort(len + 1, len + n + 1);
	dfs(1, 0, 0);
	printf("%d\n", cnt);
	
	
	return 0;
}
