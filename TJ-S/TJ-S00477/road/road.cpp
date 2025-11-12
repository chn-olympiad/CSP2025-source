#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge
{
	int u, v, w;
};

vector <edge> bian;

bool cmp(edge x, edge y)
{
	return x.w < y.w;
}

vector <int> g[10005];

bool vis[100005], flag = 0;
bool dfshuan(int x, int last)
{
	for (int i = 0; i < g[x].size(); i++)
	{
		int ifi = g[x][i];
		if (ifi == last) continue;
		if (!vis[ifi])
		{
			vis[ifi] = 1;
			if (ifi) dfshuan(ifi, x);
		}
		else
		{
			flag = 1;
			return true;
		}
	}
	return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge temp;
		temp.u = u;
		temp.v = v;
		temp.w = w;
		bian.push_back(temp);
		swap(temp.u, temp.v);
		bian.push_back(temp);
//		g[u].push_back(make_pair(v, w));
//		g[v].push_back(make_pair(u, w));
		
	}
	for (int j = 1; j <= k; j++)
	{
		int tasdjl;
		cin >> tasdjl;
		for (int i = 1; i <= n; i++)
		{
			int temp1;
			cin >> temp1;
			edge temp;
			temp.u = n + j;
			temp.v = i;
			temp.w = temp1;
			bian.push_back(temp);
			swap(temp.u, temp.v);
			bian.push_back(temp);
//			g[n + j].push_back(make_pair(i, 0));
//			g[i].push_back(make_pair(n + j, 0));
		}
	}
	n += k;
	int ans = 0;
//	cout << "r" << endl;
	sort(bian.begin(), bian.end(), cmp);
//	for (int i = 0; i < bian.size(); i++)
//	{
//		cout << bian[i].u << " " << bian[i].v << endl;
//	}
//	cout << "r" << endl;
	for (int j = 0; j < bian.size(); j++)
	{
//	cout << "r" << endl;
		edge i = bian[j];
//	cout << "r" << endl;
		int u = i.u, v = i.v;
//	cout << "r" << u << " " << v << endl;
		g[u].push_back(v);
//	cout << "r" << endl;
		
		g[v].push_back(u);
		memset(vis, 0, sizeof(vis));
		if (dfshuan(u, -1))
		{
			g[u].pop_back();
			g[v].pop_back()
;//			g[u][g[u].size() - 1] = 0;
//			g[v][g[v].size() - 1] = 0;
		}
		else
		{
//			cout << i.u << " " << i.v << " " << i.w << endl;
			ans += i.w;
		}
	}
	cout << ans << endl;
	return 0;
}
