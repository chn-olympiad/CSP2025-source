#include<bits/stdc++.h>
using namespace std;
int n, K, a[500002], ans = -1;
bool vis[500002];
int read()
{
	int res = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while('0' <= c && c <= '9')
	{
		res = (res << 1) + (res << 3) + (c ^ 48);
		c = getchar();
	}
	return f * res;
}
void dfs(int k, int s)
{
	if(k == n)
	{
	 	ans = max(ans, s);
	 	return;
	}
	for(int i = k; i <= n; i++)
	{
		if(!vis[i])
		{
			int res = a[k];
			vis[i] = true;
			for(int j = k + 1; j <= i; j++) res ^= a[j];
			dfs(i, s + (res == K));
			vis[i] = false;
		}
	}
	dfs(k + 1, s);
	return;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read();
	K = read();
	for(int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
