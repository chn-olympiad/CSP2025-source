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

const int N = 1e4 + 20;
const int M = 1e6 + 10;
const int K = 15;

int n, m, k;
struct node
{
	int u, v;
	int w;
} mp[M];

node ext[K];

int cost[K];
int c[K][N];

int fa[N];
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fx] = fy;
}

bool cho[K]; // 指示第 k 个点是选还是不选

int ans = INT_MAX;
void check()
{
	int ret = 0;
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	// (n,n+k]

	int tot = 0;
	int choose = 0; // 选择了几个点
	memset(ext, 0, sizeof(ext));

//	cerr << "check ";
//	for (int i = 1; i <= k; i++) cerr << cho[i] << " ";
//	cerr << endl;

	for (int i = 1; i <= k; i++)
	{
		if (cho[i])
		{
			ret += cost[i];
			choose++;
			for (int j = 1; j <= n; j++)
			{
				ext[++tot] = {i + n, j, c[i][j]};
			}
		}
	}
//	cerr << "ret=" <<ret<<endl;

	if (tot)
	{
		sort(ext + 1, ext + 1 + n, [](node a, node b) -> bool
		{
			return a.w < b.w;
		});
	}

	int totE = 1, totY = 1; // 额外，原始队列最小值

	int idx = 0;
	while (idx < n + choose - 1)
	{
		int a, b;
		int num = 0;

		if (totE <= tot && ext[totE].w < mp[totY].w)
		{
			a = ext[totE].u, b = ext[totE].v;
			num = ext[totE].w;
			totE++;
		}
		else
		{
			a = mp[totY].u;
			b = mp[totY].v;
			num = mp[totY].w;
			totY++;

		}

		if (find(a) == find(b)) continue;
		//printf("%d %d : %d\n",a,b,num);

		merge(a, b);
		ret += num;
		idx++;
	}

	ans = min(ans, ret);
}
void dfs(int x)
{
	if (x > k)
	{
		check();
		return;
	}

	dfs(x + 1);
	cho[x] = 1;
	dfs(x + 1);
	cho[x] = 0;

	return;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read(), m = read(), k = read();
	//scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= m; i++)
	{
		//scanf("%d%d%d", &mp[i].u, &mp[i].v, &mp[i].w);
		mp[i].u = read(), mp[i].v = read(), mp[i].w = read();
	}
	for (int i = 1; i <= k; i++)
	{
		cost[i] = read();
		//scanf("%d", &cost[i]);
		for (int j = 1; j <= n; j++)
		{
			c[i][j] = read();
			//scanf("%d", &c[i][j]);
		}
	}

	sort(mp + 1, mp + 1 + m, [](node a, node b) -> bool
	{
		return a.w < b.w;
	});

	if (k == 0) check();
	else
	{
		dfs(1);
	}

	printf("%d\n", ans);

	return 0;
}