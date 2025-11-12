#include <bits/stdc++.h>
#define PII pair <int, int>
#define PIP pair <int, PII>
#define LL long long
#define DB double
#define ST string

#define x first
#define y second

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10, K = 20;
int n, m, k, c[K], a[K][N];

int fa[N + K];
int find(int x)
{ return fa[x] == x ? x : fa[x] = find(fa[x]); }
PIP ed[M];

bool used[K];
LL ans = -1;
priority_queue <PIP> q;
void dfs(int x, LL res, int chs)
{
//	cout << x << ' ' << res << ' ' << chs << '\n';
	
	if(ans != -1 && res >= ans) return ;
	
	if(x == k + 1)
	{
		while(q.size()) q.pop();
		fr(i, 1, k) if(used[i]) fr(j, 1, n)
			q.push({-a[i][j], {n + i, j}});
	
		fr(i, 1, n + k) fa[i] = i;
		
		int now = 0, i = 1;
		while(now < n + chs - 1)
		{
			PIP t;
			if(q.empty() || -q.top().x > ed[i].x) t = ed[i], i ++ ;
			else t = q.top(), t.x *= -1, q.pop();
			
			int dist = t.x;
			int x = t.y.x, y = t.y.y;
			
			if(find(x) == find(y)) continue;
			
			res += 1ll * dist;
			if(ans != -1 && res >= ans) return ;
//			cout << i << ' ' << q.size() << ' ' << x << "<->" << y << ' ' << res << '\n';
			
			now ++ ;
			fa[find(x)] = find(y);
		}
		
//		cout << "ED " << res << '\n';
		
		if(ans == -1 || ans > res) ans = res;
		
		return ;
	}
	
	if(c[x]) dfs(x + 1, res, chs);
	used[x] = 1;
	dfs(x + 1, res + 1ll * c[x], chs + 1);
	used[x] = 0;
}

int flg[K];
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	fr(i, 1, m) cin >> ed[i].y.x >> ed[i].y.y >> ed[i].x;
	
	sort(ed + 1, ed + 1 + m);
	
//	fr(i, 1, m) cout << ed[i].x << ' ' << ed[i].y.x << ' ' << ed[i].y.y << '\n';
	
	fr(i, 1, k) 
	{
		cin >> c[i];
		fr(j, 1, n) cin >> a[i][j];
//		fr(j, 1, n) fr(l, 1, n) if(j != l)
//			q.push({a[i][j] + a[i][l] + c[i], j, l, i});
	}
	
//	fr(i, 1, n) fa[i] = i;
	
//	
//	int res = 0;
//	while(q.size())
//	{
//		node t = q.top(); q.pop();
//		
//		int cost = t.cost;
//		int x = t.x, y = t.y;
//		
//		if(find(x) == find(y)) continue;
//		
//		if(t.town != -1)
//		{
//			
//		}
//		
//		if(used) flg[used] = 0;
//		
//		res += cost;
//		fa[find(x)] = find(y);
//	}
	
	dfs(1, 0, 0);
	
	cout << ans << '\n';
	
	return 0;
}

