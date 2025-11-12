// 忘记prim怎么写了还有救吗 
// fk me

// 12/25 test
// 48pts(maybe
// priskal lol
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int ans = 0;
int rt[10005];
int city[10005];

struct node
{
	int u, v, w;
};
vector<node> edge;

//struct onedirnode
//{
//	int v, m;
//};
//vector<onedirnode> onediredge[10005];

int read()
{
	int num = 0;
	while (1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ')
		{
			return num;
		}
		num = num * 10 + int(c - '0');
	}
}

void write(int n)
{
	char c[11] = {};
	int len = 0;
	while (n)
	{
		c[++len] = char(n % 10 + '0');
		n /= 10;
	}
	for (int i = len; i >= 1; --i)
	{
		putchar(c[i]);
	}
}

bool cmp(node x, node y)
{
	return x.w < y.w;
}

int find(int n)
{
	if (rt[n] == n)
	{
		return rt[n];
	}
	else
	{
		rt[n] = find(rt[n]);
		return rt[n];
	}
}

void merge(int n, int m)
{
	int nrt = find(n);
	rt[nrt] = m;
}

void kruskal()
{
	int connected = 0;
	int flag = 0;
	int cu, cv, cw;
	for (vector<node>:: iterator it = edge.begin(); it != edge.end(); ++it)
	{
		if (connected == n - 1 && flag == 0)
		{
			return;
		}
//		else if (/* idk what to write here */)
//		{
//			// ???
//			// What could it be here?
//		}
		int u = (*it).u;
		int v = (*it).v;
		int w = (*it).w;
		if (u > n || v > n && flag == 0)
		{
			flag = 1;
			cu = u;
			cv = v;
			cw = w;
			flag == 1;
		}
		else if (flag == 1)
		{
			u = cu;
			v = cv;
			w = cw;
		}
		if (find(u) != find(v))
		{
			merge(u, v);
			ans += w;
			++connected;
		}
	}
//	return ans;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	n = read();
//	m = read();
//	k = read();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		rt[i] = i;
	}
	for (int i = 1; i <= m; ++i)
	{
		node adge;
//		adge.u = read();
//		adge.v = read();
//		adge.w = read();
		cin >> adge.u >> adge.v >> adge.w;
		edge.push_back(adge);
//		int u = read();
//		onrdirnode adge;
//		adge.v = read();
//		adge.w = read();
//		onediredge[u].push_back(adge);
	}
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 1; i <= k; ++i)
	{
//		city[i] = read();
		cin >> city[i];
		for (int j = 1; j <= n; ++j)
		{
			int ct;
//			ct = read();
			cin >> ct;
			node adge;
			adge.u = n + i;
			adge.v = j;
			adge.w = city[i] + ct;
			edge.push_back(adge);
		}
	}
	kruskal();
//	write(ans);
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/
