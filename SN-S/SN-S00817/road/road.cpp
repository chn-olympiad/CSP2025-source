#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 1e4+5;
const int M = 1e6+1e5+5;
typedef long long ll;

struct edge
{
	int u, v;
	ll w;
	int type, id;
	bool operator<(const edge x) const
	{
		return (w == x.w ? type < x.type : w > x.w);
	}
};

int n, m, k;
ll ans;
pair<ll, int> a[11][N];
ll c[11];
priority_queue<edge> q;
int f[N];
int il[11], ir[11];
bool vis[11], fix[11][N];

int fnd(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = fnd(f[x]);
}

void mrg(int x, int y)
{
	int fx = fnd(x);
	int fy = fnd(y);
	f[fx] = fy;
}

void add(int id)
{
	int u, v;
	u = a[id][il[id]].second, v = a[id][ir[id]].second;
	if(il[id] > n || ir[id] > n)
		return;
	if(!vis[id])
		q.push({u, v, c[id]+a[id][il[id]].first+a[id][ir[id]].first, 1, id});
	else
		q.push({u, v, (fix[id][u] ? 0 : a[id][il[id]].first)+(fix[id][v] ? 0 : a[id][ir[id]].first), 1, id});
	ir[id]++;
	if(ir[id] > n)
		ir[id] = (++il[id])+1;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int i, j, u, v, cnt = 0;
	ll w;
	
	cin >> n >> m >> k;
	for(i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		q.push({u, v, w, 0, 0});
	}
	for(i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(j = 1; j <= n; j++)
		{
			cin >> a[i][j].first;
			a[i][j].second = j;
		}
		sort(a[i]+1, a[i]+1+n);
//		for(j = 1; j <= n; j++)
//			cout << a[i][j].first << ' ' << a[i][j].second << endl;
		il[i] = 1, ir[i] = 2;
		add(i);
	}
	for(i = 1; i <= n; i++)
		f[i] = i;
	while(cnt < n-1)
	{
		edge x = q.top();
		u = x.u, v = x.v, w = x.w;
		q.pop();
		if(fnd(u) == fnd(v))
			continue;
		mrg(u, v);
		ans += w;
		cnt++;
		if(x.type == 1)
		{
			vis[x.id] = 1;
			fix[x.id][u] = 1;
			fix[x.id][v] = 1;
			add(x.id);
		}
	}
	cout << ans << endl;
	
	return 0;
}
