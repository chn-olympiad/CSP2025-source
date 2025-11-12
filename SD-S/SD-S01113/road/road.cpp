#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		{
			f = 1; 
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
struct node
{
	int id, y, w;
};
int n, m, k, fa[10005], ans, c[15], s[15][10005];
vector <node> a[10005];
int find(int x)
{
	if(x == fa[x])return x;
	return fa[x] = find(fa[x]);
}
struct node2
{
	int x, y, w;
}e[2000005];
bool cmp(node2 c, node2 d)
{
	if(c.w == d.w)
	{
		if(c.x == d.x)
		{
			return c.y < d.y;
		}
		return c.x < d.x;
	}
	return c.w < d.w;
}
void kruscal()
{
	for(int i = 1;i <= n;i++)
	{
		fa[i] = i;
	}
	//cout << 1 << endl;
	int cnt = 0, sum = 0;
	sort(e + 1, e + m + 1, cmp);
	//cout << 1 << endl;
	for(int i = 1;i <= m;i++)
	{
		//cout << 1 << endl;
		if(cnt == n - 1)
		{
			ans = min(ans, sum);
			return;
		}
		int x = e[i].x, y = e[i].y, z = e[i].w;
		int fx = find(x), fy = find(y);
		if(fx == fy)continue;
		fa[fx] = fy; 
		sum += z;
		cnt++;
		//cout << cnt << endl;
	}
	return;
 } 
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	//cout << 1 << endl;
	cin >> n >> m >> k;
	//cout << n << ' ' << m << ' ' << k << endl;
	//cout << "DEBUG";
	int x, y, z;
	//cout << "DEBUG";
	ans = 1e16 + 7;
	//cout << "DEBUG";
	for(int i = 1;i <= m;i++)
	{
		x = read(), y = read(), z = read();
		a[x].push_back({i, y, z});
		a[y].push_back({i, x, z});
		e[i].x = x, e[i].y = y, e[i].w = z;
	}
	//cout << "DEBUG";
	if(k == 0)
	{
		kruscal();
		cout << ans;
		return 0;
	}
	//kruscal();
	//cout << ans << endl;;
	//cout << "DEBUG";
	bool flg = 1;
	//bool flag[1005] = {0};
	for(int i = 1;i <= k;i++)
	{
		//memset(flag, 0, sizeof(flag));
		bool flag[1005] = {0};
		c[i] = read();
		if(c[i])flg = 0;
		for(int j = 1;j <= n;j++)
		{
			s[i][j] = read();
		}
		for(int j = 1;j <= n;j++)
		{
			memset(flag, 0, sizeof(flag));
			for(int q = 0;q < a[j].size();q++)
			{
				node f = a[j][q];
				int y = f.y, id = f.id;
				e[id].w = min(e[id].w, s[i][j] + s[i][y]);
				flag[y] = 1;
			}
			for(int l = 1;l <= n;l++)
			{
				if(j == l)continue;
				if(!flag[l])e[++m].x = j, e[m].y = l, e[m].w = s[i][j] + s[j][l]; 
			}
		}
	}
	kruscal();
	cout << ans << endl;
	//cout << 1 << endl;
	return 0;
}


