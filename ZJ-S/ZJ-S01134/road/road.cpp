#include<bits/stdc++.h>
using namespace std;
int n, m, cnt, c[15], f[10015], k, t[15][10005];
long long ans, sum;
bool ok, usd[15];
struct node{
	int u, v, w;
	bool operator < (const node &other)	const{
		return w < other.w;
	}
}a[1000005], H[110005];
inline int find(int x)	{
	if (f[x] == x)	return x;
	return f[x] = find(f[x]);
}
inline void read(int &x)	{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')	ch = getchar();
	while (ch >= '0' && ch <= '9')	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
}
inline void work(int num, long long kru)	{
	node e[110005] = {(node){0, 0, 0}};
	int len = n - 1, cne = 0;
	for (int i = 1; i < n; ++i)	e[i] = H[i];
	for (int i = 1; i <= n + k; ++i)	f[i] = i;
	for (int i = 1; i <= k; ++i)	{
		if (usd[i])	{
			for (int j = 1; j <= n; ++j)	e[++len] = (node){n + i, j, t[i][j]};
		}
	}
	sort(e + 1, e + len + 1);
	for (int i = 1; i <= len; ++i)	{
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v)	{
			cne++;
			f[u] = v;
			kru += e[i].w;
			if (kru >= ans)	return;
			if (cne + 1 == num)	break;
		}
	}
	ans = min(ans, kru);
}
inline void dfs(int z, int p, long long kru)	{
	if (z > k)	{
		if (p > 0 && p < k && kru < ans)	work(p + n, kru);
		return;
	}
	usd[z] = true;
	dfs(z + 1, p + 1, kru + c[z]);
	usd[z] = false;
	dfs(z + 1, p, kru);
}
int main()	{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	read(m);
	read(k);
	for (int i = 1; i <= n; ++i)	f[i] = i;
	for (int i = 1; i <= m; ++i)	{
		read(a[i].u);
		read(a[i].v);
		read(a[i].w);
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; ++i)	{
		int u = find(a[i].u), v = find(a[i].v);
		if (u != v)	{
			f[u] = v;
			ans += a[i].w;
			H[++cnt] = a[i];
			if (cnt + 1 == n)	break;
		}
	}
	for (int i = 1; i <= k; ++i)	{
		read(c[i]);
		sum += c[i];
		if (c[i])	ok = true;
		for (int j = 1; j <= n; ++j)	read(t[i][j]);
	}
	if (ok)	dfs(1, 0, 0);
	for (int i = 1; i <= n + k; ++i)	f[i] = i;
	for (int i = 1; i <= k; ++i)	{
		for (int j = 1; j <= n; ++j)	{
			H[++cnt] = (node){n + i, j, t[i][j]};
		}
	}
	sort(H + 1, H + cnt + 1);
	int ma = 0;
	for (int i = 1; i <= cnt; ++i)	{
		int u = find(H[i].u), v = find(H[i].v);
		if (u != v)	{
			f[u] = v;
			sum += H[i].w;
			ma++;
			if (ma + 1 == n + k)	break;
		}
	}
	cout << min(sum, ans) << endl;
	return 0;
}
