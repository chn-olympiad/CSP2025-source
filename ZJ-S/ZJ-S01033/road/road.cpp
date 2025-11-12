#include<bits/stdc++.h>
#define PII pair<int, int>
#define IOS ios::sync_with_stdio(false)
#define x first
#define y second
#define ll long long
#define ull unsigned long long
#define forr(a, b, c) for (int i = (a); i <= (b); i += (c))
using namespace std;
const int N = 1e5 + 10, inf = INT_MAX;
int n, m, k;
int in[N], vis[N];
vector<PII> g[N];
vector<int> d(N, inf);
void into(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}

int main()
{
	into();
	IOS;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		in[v]++;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(!in[i]){
			q.push(i);
			d[i] = 0;
		}
	}
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 1;
		for (auto to : g[u])
		{
			int v = to.x, w = to.y;
			if(vis[v] == 1) continue;
			if(d[u] + w < d[v])
			{
				d[v] = d[u] + w;
			}
			if(--in[v] == 0) q.push(v);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, d[i]);
	}
	cout << ans << '\n';
	
}

