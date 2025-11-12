#include<cstdio>
#include<algorithm> 
const int MAXN = 210;
int T, n;
int a[100010][5];
bool hasmem[MAXN][MAXN / 2][MAXN / 2];
int mem[MAXN][MAXN / 2][MAXN / 2];
int tmp[100010];
int dfs(int now, int s1, int s2)
{
	if(now > n) return 0;
	if(hasmem[now][s1][s2]) return mem[now][s1][s2];
	int s3 = now - 1 - s1 - s2;
	int ans = 0;
	if(s1 < n / 2) ans = std::max(ans, dfs(now + 1, s1 + 1, s2) + a[now][1]); 
	if(s2 < n / 2) ans = std::max(ans, dfs(now + 1, s1, s2 + 1) + a[now][2]); 
	if(s3 < n / 2) ans = std::max(ans, dfs(now + 1, s1, s2) + a[now][3]); 
	hasmem[now][s1][s2] = true;
	mem[now][s1][s2] = ans;
	return ans;
} 
bool cmp(int A, int B)
{
	return A > B;
}
bool hasmem2[MAXN][MAXN / 2];
int mem2[MAXN][MAXN / 2];
int dfs2(int now, int s1)
{
	if(now > n) return 0;
	if(hasmem2[now][s1]) return mem2[now][s1];
	int s2 = now - 1 - s1;
	int ans = 0;
	if(s1 < n / 2) ans = std::max(ans, dfs2(now + 1, s1 + 1) + a[now][1]); 
	if(s2 < n / 2) ans = std::max(ans, dfs2(now + 1, s1) + a[now][2]); 
	hasmem2[now][s1] = true;
	mem2[now][s1] = ans;
	return ans;
} 
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) for(int j = 1; j <= 3; ++ j) scanf("%d", &a[i][j]);
		if(n > 200)
		{
			bool isA = true, isB = true;
			for(int i = 1; i <= n; ++ i)
			{
				if(a[i][2] || a[i][3]) isA = false;
				if(a[i][3]) isB = false;
			}
			if(isA)
			{
				for(int i = 1; i <= n; ++ i) tmp[i] = a[i][1];
				std::sort(&tmp[1], &tmp[n + 1], cmp);
				int ans = 0;
				for(int i = 1; i <= n / 2; ++ i) ans += tmp[i];
				printf("%d\n", ans);
				continue;
			}
			else if(isB)
			{
				printf("%d\n", dfs2(1, 0));
				for(int i = 1; i <= n; ++ i) for(int j = 0; j <= n / 2; ++ j) hasmem2[i][j] = false;
				continue;
			}
		}
		printf("%d\n", dfs(1, 0, 0));
		for(int i = 1; i <= n; ++ i) for(int j = 0; j <= n / 2; ++ j) for(int k = 0; k <= n / 2; ++ k) hasmem[i][j][k] = false;
	}
	return 0;
}
