#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const int N = 2e5 + 10;
const int M = 2e6 + 10;
typedef long long ll;
struct Edge
{
	int u, v, w;
	friend bool operator<(const Edge &a, const Edge &b)
	{
		return a.w < b.w;
	}
}st[M], e[M], xuan[N];

int xuancnt;
int c[N];
int go[N];
int size[N];
int a[15][N];

int find(int x)
{
	if (x == go[x])
		return x;
	return go[x] = find(go[x]);
}
void read(int &x)
{
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')
			f = -f;
		c = getchar();
	}
	while (isdigit(c))
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	x = x * f;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	read(n), read(m), read(k);
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		read(u), read(v), read(w);
		st[i] = (Edge){u, v, w};
	}
	for (int i = 1; i <= k; ++i)
	{
		read(c[i]);
		for (int j = 1; j <= n; ++j)
			read(a[i][j]);
	}
	for (int i = 1; i <= n; ++i)
		go[i] = i, size[i] = 1;
	std::sort(st + 1, st + m + 1);
	ll tot = 0;
	for (int i = 1; i <= m; ++i)
	{
		int u = st[i].u;
		int v = st[i].v;
		int w = st[i].w;
		int fu = find(u);
		int fv = find(v);
		if (fu != fv)
		{
			tot += w;
			go[fu] = fv;
			xuan[++xuancnt] = st[i];
		}
	}
	ll ans = tot;
	for (int i = 1; i < (1 << k); ++i)
	{
		int nowcn = m;
		ll now = 0;
		for (int j = 1; j <= m; ++j)
			e[j] = st[j];
		for (int j = 1; j <= k; ++j)
		{
			if (i & (1 << (j - 1)))
			{
				for (int l = 1; l <= n; ++l)
					e[++nowcn] = (Edge){j + n, l, a[j][l]};
				now += c[j];
			}
		}
		for (int j = 1; j <= n + k; ++j)
			go[j] = j, size[j] = 1;
		std::sort(e + 1, e + nowcn + 1);
		for (int j = 1; j <= nowcn; ++j)
		{
			int u = e[j].u;
			int v = e[j].v;
			int fu = find(u);
			int fv = find(v);
			if (fu != fv)
			{
				now += e[j].w;
				if (size[fu] < size[fv])
				{
					size[fv] += size[fu];
					go[fu] = fv;
				}
				else
				{
					size[fu] += size[fv];
					go[fv] = fu;
				}
			}
		}
		ans = std::min(ans, now);
	}
	cout << ans << '\n';
	return 0;
}
