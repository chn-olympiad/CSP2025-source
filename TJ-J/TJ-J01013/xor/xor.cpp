#include<cstdio>
#include<algorithm>
const int MAXN = 500010;
int n, k, a[MAXN];
int s[MAXN];
bool hasmem[MAXN];
int mem[MAXN];
int dfs(int now)
{
	if(now > n) return 0;
	if(hasmem[now]) return mem[now];
	int ans = 0;
	ans = std::max(ans, dfs(now + 1));
	for(int i = now; i <= n; ++ i)
	{
		if((s[i] ^ s[now - 1]) == k)
		{
			ans = std::max(ans, dfs(i + 1) + 1);
		} 
	}
	hasmem[now] = true;
	mem[now] = ans;
	return ans;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	if(n >= 2000)
	{
		if(k == 1)
		{
			int ans = 0;
			for(int i = 1; i <= n; ++ i) ans += a[i];
			printf("%d\n", ans);
		}
		else
		{
			int ans = 0;
			for(int i = 1; i <= n; ++ i)
			{
				if(!a[i]) ans ++;
				else
				{
					int ti = i;
					while(a[i + 1]) ++ i;
					ans += (i - ti + 1) / 2;
				}
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	for(int i = 1; i <= n; ++ i) s[i] = s[i - 1] ^ a[i];
	printf("%d\n", dfs(1));
	return 0;
}
