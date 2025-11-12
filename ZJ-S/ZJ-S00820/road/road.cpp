#include <bits/stdc++.h>
#define int long long
#define lll unsigned long long
#define vc vector
#define pi pair<int, int>
#define mkp make_pair
#define INF 2147483647
#define endl "\n"
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

constexpr int N = 10011;
constexpr int NN = 110011;
constexpr int M = 1000011;
constexpr int K = 11;

struct node
{
	int u, v, w;
}a[M], b[N], dc[NN];
int n, m, k, tot, ans;
int c[K][N], fa[N << 1];
bitset<K> vis;


int find(int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

void kruskal()
{
	int sum = 0, s = n;
	tot = n - 1;
	for (int i = 1; i <= tot; i++)
	{
		dc[i] = b[i];
	}
	for (int i = 1; i <= k; i++)
	{
		if(!vis[i]) continue;
		sum += c[i][0];
		s++;
		for (int j = 1; j <= n; j++)
		{
			dc[++tot] = (node){s, j, c[i][j]};
		}
	}
	if(s == n) return ;
	if(sum >= ans) return ;
	sort(dc + 1, dc + 1 + tot, [](node x, node y){  return x.w < y.w;  });
	for (int i = 1; i <= s; i++)
	{
		fa[i] = i;	
	}
	for (int i = 1, cnt = 0; i <= tot; i++)
	{
		int x = find(dc[i].u), y = find(dc[i].v), z = dc[i].w;
		if(x != y)
		{
			fa[x] = y;
			sum += z;
			cnt++;
			if(cnt == s - 1) break;
		}
	}
	ans = min(ans, sum);
}

void dfs(int step)
{
	if(step > k)
	{
		kruskal();
		return ;	
	}	
	vis[step] = 1;
	dfs(step + 1);
	vis[step] = 0;
	dfs(step + 1);
}

signed main()
{
	IOS;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cin >> c[i][j];
		}
	}
	sort(a + 1, a + 1 + m, [](node x, node y){  return x.w < y.w;  });
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1, cnt = 0; i <= m; i++)
	{
		int x = find(a[i].u), y = find(a[i].v), z = a[i].w;
		if(x != y)
		{
			fa[x] = y;
			ans += z;
			cnt++;
			b[cnt] = a[i];
			if(cnt == n - 1) break;
		}
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
/*
80pts
*/