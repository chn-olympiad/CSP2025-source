#include <bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define int long long
template <typename T>
void read(T &x)
{
	char ch = getchar();
	T f = 1;
	x = 0;
	while (ch != '-' and (ch > '9' or ch < '0'))
	    ch = getchar();
	if (ch == '-')
	    f = -1, ch = getchar();
	for (; ch >= '0' and ch <= '9'; ch = getchar())
	    x = x * 10 + ch - '0';
	x *= f;
	return ;
}
template <typename T>
void write (T x, bool flag)
{
	x < 0 ? x = -x, putchar('-') : 0;
	static short Stack[50], top(0);
	do
	    Stack[++top] = x % 10, x /= 10;
	while (x);
	while (top)
	    putchar(Stack[top--] | 48);
	flag ? putchar('\n') : putchar(' ');
	return ;
}
int n, m, K;
struct node 
{
	int u, v, w;
	int bl;
}edge[20000005];
int tot;
int a[10005];
//int val[1005][1005];
int fa[10005];
void init()
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
	}
	return ;
}
int find (int x)
{
	if (fa[x] == x)
	{
		return x;
	}
//	cout << "+";
	fa[x] = find (fa[x]);
}
int c;
vector <int> ve[15];
priority_queue <pair <int, int>, vector<pair <int, int> >, greater <pair <int, int> > > qp;
bool flag[15];
int ans;
int cnt;
signed main()
{
    file("road");
    read(n), read(m), read(K);
	for (int i = 1; i <= m; ++i)
	{
	    read(edge[i].u), read(edge[i].v), read(edge[i].w);
	    qp.push({edge[i].w, i});
	}
	tot = m;
	for (int i = 1; i <= K; ++i)
	{
		read(c);
		for (int j = 1; j <= n; ++j)
		{
			read(a[j]);	
		}
		for (int j = 1; j <= n; ++j)
		{
			for (int k = j + 1; k <= n; ++k)
			{
				if (j == k)
				{
					continue;
				}
				edge[++tot].u = j;
				edge[tot].v = k;
				edge[tot].w = a[j] + a[k] + c;
				edge[tot].bl = i;
				ve[i].push_back(tot);
				qp.push({a[j] + a[k] + c, tot});
			}
		}
	}
//	while (!qp.empty())
//	{
//		cout << qp.top().first << ' ' << qp.top().second << '\n';
//		qp.pop();	
//	}
	while (!qp.empty())
	{
		if (cnt == n - 1)
		{
			break;
		}
		int idx = qp.top().second;
		int fu = find (edge[idx].u);
		int fv = find (edge[idx].v);
//		cout << "+";
		if (fu == fv)
		{
			continue;
		}
//		cout << idx << ' ' << edge[idx].u << ' ' << edge[idx].v << ' ' << edge[idx].w << '\n';
		if (edge[idx].bl != 0)
		{
			if (flag[edge[idx].bl] == 0)
			{
				flag[edge[idx].bl] = 1;
				for (auto x : ve[edge[idx].bl])
				{
					if (x == idx)
					{
						continue;
					}
					qp.push({edge[x].w, x});
				}
			}
		}
		ans += edge[idx].w;
		fa[fu] = fv;
		cnt++;
		qp.pop();
	}
	write (ans, 1);
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
*/

