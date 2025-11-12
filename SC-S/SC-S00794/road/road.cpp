#include <bits/stdc++.h>
using namespace std;

struct node
{
	int next, to, val;
} edge[20100];
struct node2
{
	int v;
	long long w;
};
struct node3
{
	int u, v;
	long long w;
};

vector<node2> e[10100];
int n, m, k, num, head[10100], cnt[10100];
long long c[20], a[20][10100];
bool vis[10100];
long long ans = 0;

void add(int from, int to, int val)
{
	edge[++num].next = head[from];
	edge[num].to = to;
	edge[num].val = val;
	head[from] = num;
}

bool cmp(node2 x, node2 y)
{
	return x.w < y.w;
}

bool operator < (node3 x, node3 y)
{
	return x.w > y.w;
}

void qlt()
{
	priority_queue<node3> q;
	q.push((node3){1, 1, 0});
	int ncnt = 0;
	while (!q.empty())
	{
		node3 t = q.top();
		q.pop();
		//cout << t.u << ' ' << t.v << ' ' << t.w << endl;
		if (vis[t.v]) continue;
		vis[t.v] = true;
//		add(t.u, t.v, t.w);
//		add(t.v, t.u, t.w);
		if (t.v <= n)
		{
			ans += t.w;
			if (++ncnt > n) break;
		}
		int tt = e[t.u].size();
		while (cnt[t.u] < tt)
		{
			cnt[t.u]++;
			if (!vis[e[t.u][cnt[t.u]-1].v])
			{
				q.push((node3){t.u, e[t.u][cnt[t.u]-1].v, e[t.u][cnt[t.u]-1].w});
				break;
			}
		}
		tt = e[t.v].size();
		while (cnt[t.v] < tt)
		{
			cnt[t.v]++;
			if (!vis[e[t.v][cnt[t.v]-1].v])
			{
				//cout << t.u << ' ' << e[t.v][cnt[t.v]-1].v << ' ' << e[t.v][cnt[t.v]-1].w + t.w << endl;
				if (t.v > n) q.push((node3){t.v, e[t.v][cnt[t.v]-1].v, e[t.v][cnt[t.v]-1].w + t.w});
				else q.push((node3){t.v, e[t.v][cnt[t.v]-1].v, e[t.v][cnt[t.v]-1].w});
				break;
			}
		}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back((node2){v, w});
		e[v].push_back((node2){u, w});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			e[n+i].push_back((node2){j, a[i][j]});
			e[j].push_back((node2){n+i, a[i][j]+c[i]});
		}
	}
	for (int i = 1; i <= n + k; i++)
		sort(e[i].begin(), e[i].end(), cmp);
	qlt();
	cout << ans << endl;
	return 0;
}//4 4 0 1 4 6 2 4 5 3 4 4 2 3 7